// Copyright (c) 2016-2021 The Hush developers
// Distributed under the GPLv3 software license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html
/*
 * Copyright (c) 2007 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_PER_OPENTYPE_H_
#define	_PER_OPENTYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

asn_dec_rval_t uper_open_type_get(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td, asn_per_constraints_t *constraints, void **sptr, asn_per_data_t *pd);

int uper_open_type_skip(asn_codec_ctx_t *opt_codec_ctx, asn_per_data_t *pd);

int uper_open_type_put(asn_TYPE_descriptor_t *td, asn_per_constraints_t *constraints, void *sptr, asn_per_outp_t *po);

#ifdef __cplusplus
}
#endif

#endif	/* _PER_OPENTYPE_H_ */
