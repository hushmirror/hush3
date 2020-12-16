// Copyright (c) 2016-2020 The Hush developers
// Distributed under the GPLv3 software license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html
/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "Crypto-Conditions"
 * 	found in "CryptoConditions.asn"
 */

#include "Condition.h"

static asn_TYPE_member_t asn_MBR_Condition_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Condition, choice.preimageSha256),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SimpleSha256Condition,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"preimageSha256"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Condition, choice.prefixSha256),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CompoundSha256Condition,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"prefixSha256"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Condition, choice.thresholdSha256),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CompoundSha256Condition,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"thresholdSha256"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Condition, choice.rsaSha256),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SimpleSha256Condition,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"rsaSha256"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Condition, choice.ed25519Sha256),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SimpleSha256Condition,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"ed25519Sha256"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Condition, choice.secp256k1Sha256),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SimpleSha256Condition,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"secp256k1Sha256"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Condition, choice.evalSha256),
		(ASN_TAG_CLASS_CONTEXT | (15 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SimpleSha256Condition,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"evalSha256"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_Condition_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* preimageSha256 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* prefixSha256 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* thresholdSha256 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* rsaSha256 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* ed25519Sha256 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* secp256k1Sha256 */
    { (ASN_TAG_CLASS_CONTEXT | (15 << 2)), 6, 0, 0 } /* evalSha256 */
};
static asn_CHOICE_specifics_t asn_SPC_Condition_specs_1 = {
	sizeof(struct Condition),
	offsetof(struct Condition, _asn_ctx),
	offsetof(struct Condition, present),
	sizeof(((struct Condition *)0)->present),
	asn_MAP_Condition_tag2el_1,
	7,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_Condition = {
	"Condition",
	"Condition",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_Condition_1,
	7,	/* Elements count */
	&asn_SPC_Condition_specs_1	/* Additional specs */
};

