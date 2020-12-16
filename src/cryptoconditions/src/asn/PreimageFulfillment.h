// Copyright (c) 2016-2020 The Hush developers
// Distributed under the GPLv3 software license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html
/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "Crypto-Conditions"
 * 	found in "CryptoConditions.asn"
 */

#ifndef	_PreimageFulfillment_H_
#define	_PreimageFulfillment_H_


#include "asn_application.h"

/* Including external dependencies */
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PreimageFulfillment */
typedef struct PreimageFulfillment {
	OCTET_STRING_t	 preimage;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PreimageFulfillment_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PreimageFulfillment;

#ifdef __cplusplus
}
#endif

#endif	/* _PreimageFulfillment_H_ */
#include <asn_internal.h>
