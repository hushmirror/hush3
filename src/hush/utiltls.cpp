// Copyright (c) 2017 The Zen Core developers
// Copyright (c) 2019-2020 The Hush developers
// Distributed under the GPLv3 software license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html

#include <stdio.h>
#include <vector>

#include <wolfssl/options.h>
#include <wolfssl/ssl.h>
#include <wolfssl/wolfcrypt/rsa.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include "../util.h"
#include "utiltls.h"

namespace hush {

// Set of most common default trusted certificates directories used by OpenSSL
static const char* defaultTrustedDirs[] =
{
#ifdef WIN32
    ""
#elif MAC_OSX
    "/System/Library/OpenSSL/certs"
#else // Linux build
    "/etc/ssl/certs",
    "/usr/local/ssl/certs",
    "/usr/lib/ssl/certs",
    "/usr/share/ssl/certs",
    "/etc/pki/tls/certs",
    "/var/lib/ca-certificates"
#endif
};

// Default root certificates (PEM encoded)
static const char defaultRootCerts[] =
{
//    // Example of specifying a certificate
//    //
//    "-----BEGIN CERTIFICATE-----\n"
//    "MIIDYDCCAkigAwIBAgIJAJMakdoBYY67MA0GCSqGSIb3DQEBCwUAMEUxCzAJBgNV\n"
//    "BAYTAkFVMRMwEQYDVQQIDApTb21lLVN0YXRlMSEwHwYDVQQKDBhJbnRlcm5ldCBX\n"
//    "aWRnaXRzIFB0eSBMdGQwHhcNMTcwODE0MTc0MTMyWhcNNDQxMjMwMTc0MTMyWjBF\n"
//    "MQswCQYDVQQGEwJBVTETMBEGA1UECAwKU29tZS1TdGF0ZTEhMB8GA1UECgwYSW50\n"
//    "ZXJuZXQgV2lkZ2l0cyBQdHkgTHRkMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n"
//    "CgKCAQEAzNV+SPRCKSEGlntfpCRMVSfz99NoEo3K1SRyw6GTSb1LNSTQCn1EsCSH\n"
//    "cVZTmyfjcTHpwz4aF14yw8lQC42f218AOsG1DV5suCaUXhSmZlajMkvEJVwfBOft\n"
//    "xpcqE1fA9wovXlnJLXVgyJGMc896S8tcbrCU/l/BsqKh5QX8N60MQ3w376nSGvVP\n"
//    "ussN8bVH3aKRwjhateqx1GRt0GPnM8/u7EkgF8Bc+m8WZYcUfkPC5Am2D0MO1HOA\n"
//    "u3IKxXZMs/fYd6nF5DZBwg+D23EP/V8oqenn8ilvrSORq5PguOl1QoDyY66PhmjN\n"
//    "L9c4Spxw8HXUDlrfuSQn2NJnw1XhdQIDAQABo1MwUTAdBgNVHQ4EFgQU/KD+n5Bz\n"
//    "QLbp09qKzwwyNwOQU4swHwYDVR0jBBgwFoAU/KD+n5BzQLbp09qKzwwyNwOQU4sw\n"
//    "DwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAQEAVtprBxZD6O+WNYUM\n"
//    "ksdKiVVoszEJXlt7wajuaPBPK/K3buxE9FLVxS+LiH1PUhPCc6V28guyKWwn109/\n"
//    "4WnO51LQjygvd7SaePlbiO7iIatkOk4oETJQZ+tEJ7fv/NITY/GQUfgPNkANmPPz\n"
//    "Mz9I6He8XhIpO6NGuDG+74aR1RhvR3PWJJYT0QpL0STVR4qTc/HfnymF5XnnjOYZ\n"
//    "mwzT8jXX5dhLYwJmyPBS+uv+oa1quM/FitA63N9anYtRBiPaBtund9Ikjat1hM0h\n"
//    "neo2tz7Mfsgjb0aiORtiyaH2OetvwR0QuCSVPnknkfGWPDINdUdkgKyA1PX58Smw\n"
//    "vaXEcw==\n"
//    "-----END CERTIFICATE-----"

        ""
};

// Generates RSA keypair (a private key of 'bits' length for a specified 'uPublicKey')
// obsolete since we use EC instead of RSA
static WOLFSSL_EVP_PKEY* GenerateRsaKey(int bits, WOLFSSL_BN_ULONG uPublicKey)
{
    WOLFSSL_EVP_PKEY *evpPrivKey = NULL;
    
    WOLFSSL_BIGNUM *pubKey = wolfSSL_BN_new();
    if (pubKey) {
        if (wolfSSL_BN_set_word(pubKey, uPublicKey)) {
            WOLFSSL_RSA *privKey = wolfSSL_RSA_new();
            if (privKey) {
                if (wolfSSL_RAND_poll() &&  wolfSSL_RSA_generate_key_ex(privKey, bits, pubKey, NULL)) {
                    if ((evpPrivKey = wolfSSL_EVP_PKEY_new())) {
                        if (!wolfSSL_EVP_PKEY_assign_RSA(evpPrivKey, privKey)) {
                            wolfSSL_EVP_PKEY_free(evpPrivKey);
                            evpPrivKey = NULL;
                        }
                    }
                }

                if(!evpPrivKey) {
                    wolfSSL_RSA_free(privKey);
                }   
            }
        }
        wolfSSL_BN_free(pubKey);
    }

    return evpPrivKey;
}

// Generates EC keypair
//
static WOLFSSL_EVP_PKEY* GenerateEcKey(int nid = NID_X9_62_prime256v1)
{
    WOLFSSL_EVP_PKEY *evpPrivKey = NULL;
    WOLFSSL_EC_KEY *privKey = wolfSSL_EC_KEY_new_by_curve_name(nid);
    if (privKey) {
        wolfSSL_EC_KEY_set_asn1_flag(privKey, OPENSSL_EC_NAMED_CURVE);
        if (wolfSSL_EC_KEY_generate_key(privKey)) {
            if ((evpPrivKey = wolfSSL_EVP_PKEY_new())) {
                if (!wolfSSL_EVP_PKEY_assign_EC_KEY(evpPrivKey, privKey)) {
                    wolfSSL_EVP_PKEY_free(evpPrivKey);
                    evpPrivKey = NULL;
                }
            }
        }

        if(!evpPrivKey) {
            wolfSSL_EC_KEY_free(privKey);
        }   
    }

    return evpPrivKey;
}

// Generates certificate for a specified public key using a corresponding private key (both of them should be specified in the 'keypair').
//
static WOLFSSL_X509* GenerateCertificate(WOLFSSL_EVP_PKEY *keypair)
{
    if (!keypair) {
        return NULL;
    } 

    WOLFSSL_X509 *cert = wolfSSL_X509_new();
    if (cert) {
        bool bCertSigned = false;
        long sn = 0;
        
        if (wolfSSL_RAND_bytes((unsigned char*)&sn, sizeof(sn)) &&wolfSSL_ASN1_INTEGER_set(wolfSSL_X509_get_serialNumber(cert), sn)) {
            wolfSSL_X509_gmtime_adj(wolfSSL_X509_get_notBefore(cert), 0);
            wolfSSL_X509_gmtime_adj(wolfSSL_X509_get_notAfter(cert), (60 * 60 * 24 * CERT_VALIDITY_DAYS));

            // setting a public key from the keypair
            if (wolfSSL_X509_set_pubkey(cert, keypair)) {
                // private key from keypair is used; signature will be set inside of the cert
                bCertSigned = wolfSSL_X509_sign(cert, keypair, wolfSSL_EVP_sha512());
            }
        }

        if (!bCertSigned) {
            wolfSSL_X509_free(cert);
            cert = NULL;
        }
    }

    return cert;
}

// Stores key to file, specified by the 'filePath'
//
static bool StoreKey(WOLFSSL_EVP_PKEY *key, const boost::filesystem::path &filePath, const std::string &passphrase)
{
    if (!key)
        return false;

    bool bStored = false;

    FILE *keyfd = fopen(filePath.string().c_str(), "wb");
    if (keyfd)
    {
        WOLFSSL_EC_KEY *ec_key = NULL;
        ec_key = wolfSSL_EVP_PKEY_get0_EC_KEY(key);
        if (ec_key != NULL)
        {
            const WOLFSSL_EVP_CIPHER* pCipher = NULL;

            if (passphrase.length() && (pCipher = wolfSSL_EVP_aes_256_cbc()))
                bStored = wolfSSL_PEM_write_ECPrivateKey(keyfd, ec_key, pCipher, NULL, 0, NULL, (void*)passphrase.c_str());
            else
                bStored = wolfSSL_PEM_write_ECPrivateKey(keyfd, ec_key, NULL, NULL, 0, NULL, NULL);
        }

        fclose(keyfd);
    }

    return bStored;
}

// Stores certificate to file, specified by the 'filePath'
//
static bool StoreCertificate(WOLFSSL_X509 *cert, const boost::filesystem::path &filePath)
{
    if (!cert)
        return false;

    bool bStored = false;

    FILE *certfd = fopen(filePath.string().c_str(), "wb");
    if (certfd)
    {
        bStored = wolfSSL_PEM_write_X509(certfd, cert);
        fclose(certfd);
    }

    return bStored;
}

// Loads key from file, specified by the 'filePath'
//
static WOLFSSL_EVP_PKEY* old_LoadKey(const boost::filesystem::path &filePath, const std::string &passphrase)
{
    if (!boost::filesystem::exists(filePath))
        return NULL;

    WOLFSSL_EVP_PKEY *key = wolfSSL_EVP_PKEY_new();
    FILE *keyfd = fopen(filePath.string().c_str(), "rb");
    if (keyfd)
    {
        key = wolfSSL_PEM_read_PrivateKey(keyfd, NULL, NULL, passphrase.length() ? (void*)passphrase.c_str() : NULL);
        fclose(keyfd);
    }

    return key;
}

// Loads key from file, specified by the 'filePath'
//
static WOLFSSL_EVP_PKEY* LoadKey(const boost::filesystem::path &filePath, const std::string &passphrase)
{
    if (!boost::filesystem::exists(filePath))
        return NULL;

    WOLFSSL_EVP_PKEY *key = NULL;
    FILE *keyfd = fopen(filePath.string().c_str(), "rb");
    byte der[4096];
    byte pem[4096];
    WOLFSSL_EC_KEY *ecKey;
    ecKey = wolfSSL_EC_KEY_new();
    word32 idx = 0;

    if (keyfd)
    {
        int fileSz = fread(pem, 1, 4096, keyfd);
        fclose(keyfd);

        if (fileSz > 0)
        {
            if (ecKey)
            {
                int derSz = wc_KeyPemToDer(pem, fileSz, der, 4096, passphrase.c_str());
                int ret_decode = wc_EccPrivateKeyDecode(der, &idx, (ecc_key*)ecKey->internal, derSz);
                if (ret_decode == 0)
                {
                    if (key = wolfSSL_EVP_PKEY_new())
                    {
                        wolfSSL_EVP_PKEY_assign_EC_KEY(key, ecKey); 
                    }
                }
            }
        } 
    }

    return key;
}

// Loads certificate from file, specified by the 'filePath'
//
static WOLFSSL_X509* LoadCertificate(const boost::filesystem::path &filePath)
{
    if (!boost::filesystem::exists(filePath))
        return NULL;

    WOLFSSL_X509 *cert = NULL;
    FILE *certfd = fopen(filePath.string().c_str(), "rb");
    if (certfd)
    {
        cert = wolfSSL_PEM_read_X509(certfd, NULL, NULL, NULL);
        fclose(certfd);
    }

    return cert;
}

// Verifies if the private key in 'key' matches the public key in 'cert'
// (Signs random bytes on 'key' and verifies signature correctness on public key from 'cert')
//
static bool IsMatching(WOLFSSL_EVP_PKEY *key, WOLFSSL_X509 *cert)
{
    if (!key || !cert)
        return false;

    if (wolfSSL_X509_verify(cert, key) == WOLFSSL_SUCCESS)
    {
        return true;
    }
    
    LogPrintf("Loaded key and certificate do not match, delete them to generate new credentials!!!\n");
    
    return false;
}

// Checks the correctness of a private-public key pair and the validity of a certificate using public key from key pair
//
static bool CheckCredentials(WOLFSSL_EVP_PKEY *key, WOLFSSL_X509 *cert)
{
    if (!key || !cert)
        return false;

    bool bIsOk = false;

    // Validating the correctness of a private-public key pair, depending on a key type
    //
    switch (wolfSSL_EVP_PKEY_base_id(key))
    {
        case EVP_PKEY_RSA:
        case EVP_PKEY_RSA2:
        {
            WOLFSSL_RSA *rsaKey = wolfSSL_EVP_PKEY_get1_RSA(key);
            if (rsaKey)
            {
                bIsOk = (wc_CheckRsaKey((RsaKey*)rsaKey->internal) == 0);
                wolfSSL_RSA_free(rsaKey);
            }
            break;
        }
        case EVP_PKEY_EC:
        {
            WOLFSSL_EC_KEY *eccKey = wolfSSL_EVP_PKEY_get1_EC_KEY(key);
            if (eccKey)
            {
                bIsOk = (wc_ecc_check_key((ecc_key*)eccKey->internal) == 0);
                wolfSSL_EC_KEY_free(eccKey);
            }
            break;
        }

        default:
            bIsOk = false;
    }

    // Verifying if the private key matches the public key in certificate
    if (bIsOk)
        bIsOk = IsMatching(key, cert);

    return bIsOk;
}

// Verifies credentials (a private key, a certificate for public key and a correspondence between the private and the public key)
//
CredentialsStatus VerifyCredentials(
        const boost::filesystem::path &keyPath,
        const boost::filesystem::path &certPath,
        const std::string             &passphrase)
{
    CredentialsStatus status = credAbsent;

    WOLFSSL_EVP_PKEY *key = NULL;
    WOLFSSL_X509 *cert = NULL;

    key  = LoadKey(keyPath, passphrase);
    cert = LoadCertificate(certPath);
    
    if (key && cert) {
        status = CheckCredentials(key, cert) ? credOk : credNonConsistent;
    } else if (!key && !cert) {
        status = credAbsent;
    } else {
        status = credPartiallyAbsent;
    }
    
    if (key) {
        wolfSSL_EVP_PKEY_free(key);
    }
        
    if (cert) {
       wolfSSL_X509_free(cert); 
    }
    
    return status;
}

// Generates public key pair and the self-signed certificate for it, and then stores them by the specified paths 'keyPath' and 'certPath' respectively.
//
bool GenerateCredentials(
        const boost::filesystem::path &keyPath,
        const boost::filesystem::path &certPath,
        const std::string             &passphrase)
{
    bool bGenerated = false;

    WOLFSSL_EVP_PKEY *key = NULL;
    WOLFSSL_X509 *cert = NULL;

    // Generating key and the self-signed certificate for it
    //
    //key = GenerateRsaKey(TLS_RSA_KEY_SIZE, RSA_F4);
    //key = GenerateEcKey(NID_secp256k1);
    key = GenerateEcKey();
    if (key)
    {
        cert = GenerateCertificate(key);
        if (cert)
        {
            bool bKey = StoreKey(key, keyPath, passphrase);
            bool bCert = StoreCertificate(cert, certPath);

            if ( bKey && bCert )
            {
                bGenerated = true;
                LogPrintStr("TLS: New private key and self-signed certificate were generated successfully\n");
            }

            wolfSSL_X509_free(cert);
        }
        wolfSSL_EVP_PKEY_free(key);
    }

    return bGenerated;
}

// Checks if certificate of a peer is valid (by internal means of the TLS protocol)
//
// Validates peer certificate using a chain of CA certificates.
// If some of intermediate CA certificates are absent in the trusted certificates store, then validation status will be 'false')
//
bool ValidatePeerCertificate(WOLFSSL *ssl)
{
    if (!ssl)
        return false;

    bool bIsOk = false;

    WOLFSSL_X509 *cert = wolfSSL_get_peer_certificate (ssl);
    if (cert) {
        long errCode = wolfSSL_get_verify_result(ssl);
        if (errCode != X509_V_OK)
        {
            LogPrint("tls", "TLS: %s: %s():%d - Certificate Verification ERROR=%d: [%s]\n",
                __FILE__, __func__, __LINE__, errCode, wolfSSL_X509_verify_cert_error_string(errCode));
        } else {
            bIsOk = true;

            char buf[256];
            wolfSSL_X509_NAME_oneline(wolfSSL_X509_get_subject_name(cert), buf, 256);
            LogPrint("tls", "TLS: %s: %s():%d - subj name=%s\n",
                __FILE__, __func__, __LINE__, buf);
 
            wolfSSL_X509_NAME_oneline(wolfSSL_X509_get_issuer_name(cert), buf, 256);
            LogPrint("tls", "TLS: %s: %s():%d - issuer name=%s\n",
                __FILE__, __func__, __LINE__, buf);
        }

        wolfSSL_X509_free(cert);
    } else {
        LogPrint("tls", "TLS: %s: %s():%d - WARNING: Peer does not have certificate\n",
            __FILE__, __func__, __LINE__);
    }
    return bIsOk;
}

// Check if a given context is set up with a cert that can be validated by this context
//
bool ValidateCertificate(WOLFSSL_CTX *ssl_ctx)
{
    if (!ssl_ctx) {
        return false;
    }
    
    bool bIsOk = false;

    WOLFSSL_X509_STORE *store = wolfSSL_CTX_get_cert_store(ssl_ctx);

    if (store) {
        WOLFSSL_X509_STORE_CTX *ctx = wolfSSL_X509_STORE_CTX_new();
        if (ctx) {
            bIsOk = (wolfSSL_X509_verify_cert(ctx) == WOLFSSL_SUCCESS);
            wolfSSL_X509_STORE_CTX_free(ctx);
        }
    }

    return bIsOk;
}

// Creates the list of available OpenSSL default directories for trusted certificates storage
//
std::vector<boost::filesystem::path> GetDefaultTrustedDirectories()
{
    namespace fs = boost::filesystem;
    std::vector<fs::path> defaultDirectoriesList;

    // Check and set all possible standard default directories
    for (const char *dir : defaultTrustedDirs)
    {
        fs::path defaultDir(dir);

        if (fs::exists(defaultDir)) {
            defaultDirectoriesList.push_back(defaultDir);
        } 
    }

    return defaultDirectoriesList;
}

// Loads default root certificates (placed in the 'defaultRootCerts') into the specified context.
// Returns the number of loaded certificates.
//
int LoadDefaultRootCertificates(WOLFSSL_CTX *ctx)
{
    if (!ctx) {
        return 0;
    }

    int certsLoaded = 0;

    // Certificate text buffer 'defaultRootCerts' is a C string with certificates in PEM format
    WOLFSSL_BIO *memBuf = wolfSSL_BIO_new_mem_buf(defaultRootCerts, -1);
    if (memBuf) {
        WOLFSSL_X509 *cert = NULL;
        while ((cert = wolfSSL_PEM_read_bio_X509(memBuf, NULL, 0, NULL)))
        {
            if (wolfSSL_X509_STORE_add_cert(wolfSSL_CTX_get_cert_store(ctx), cert) > 0) {
                certsLoaded++;
            }

            wolfSSL_X509_free(cert);
        }
        wolfSSL_BIO_free(memBuf);
    }

    return certsLoaded;
}
}
