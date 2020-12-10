// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Copyright (c) 2016-2018 The Zcash developers
// Copyright (c) 2016-2020 The Hush developers
// Distributed under the GPLv3 software license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html

#ifndef HUSH_KEYIO_H
#define HUSH_KEYIO_H

#include <chainparams.h>
#include <key.h>
#include <pubkey.h>
#include <script/standard.h>
#include <zcash/Address.hpp>
#include <zcash/zip32.h>

#include <string>

CKey DecodeSecret(const std::string& str);
CKey DecodeCustomSecret(const std::string& str, uint8_t secret_key);
std::string EncodeSecret(const CKey& key);
std::string EncodeCustomSecret(const CKey& key,uint8_t secret_key);

CExtKey DecodeExtKey(const std::string& str);
std::string EncodeExtKey(const CExtKey& extkey);
CExtPubKey DecodeExtPubKey(const std::string& str);
std::string EncodeExtPubKey(const CExtPubKey& extpubkey);

std::string EncodeDestination(const CTxDestination& dest);
CTxDestination DecodeDestination(const std::string& str);
bool IsValidDestinationString(const std::string& str);
bool IsValidDestinationString(const std::string& str, const CChainParams& params);

std::string EncodePaymentAddress(const libzcash::PaymentAddress& zaddr);
libzcash::PaymentAddress DecodePaymentAddress(const std::string& str);
bool IsValidPaymentAddressString(const std::string& str, uint32_t consensusBranchId);

std::string EncodeViewingKey(const libzcash::ViewingKey& vk);
libzcash::ViewingKey DecodeViewingKey(const std::string& str);

std::string EncodeSpendingKey(const libzcash::SpendingKey& zkey);
libzcash::SpendingKey DecodeSpendingKey(const std::string& str);

#endif // HUSH_KEYIO_H
