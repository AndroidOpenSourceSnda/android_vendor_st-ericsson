/*
 * LPP_GNSS-DataBitAssistanceReq.c
 *
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * Author: sunilsatish.rao@stericsson.com for ST-Ericsson.
 * License terms: Redistribution and modifications are permitted subject to BSD license.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of ST-Ericsson nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ST-ERICSSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP_PDU-Definitions"
 * 	found in "LPP_RRLP_Rel_10.asn"
 * 	`asn1c -gen-PER`
 */

#include <asn_internal.h>

#include "LPP_GNSS-DataBitAssistanceReq.h"

static int
memb_gnss_TOD_Req_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 3599)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_gnss_TOD_FracReq_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 999)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_dataBitInterval_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 15)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_gnss_TOD_Req_constr_2 = {
	{ APC_CONSTRAINED,	 12,  12,  0,  3599 }	/* (0..3599) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 }
};
static asn_per_constraints_t asn_PER_memb_gnss_TOD_FracReq_constr_3 = {
	{ APC_CONSTRAINED,	 10,  10,  0,  999 }	/* (0..999) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 }
};
static asn_per_constraints_t asn_PER_memb_dataBitInterval_constr_4 = {
	{ APC_CONSTRAINED,	 4,  4,  0,  15 }	/* (0..15) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 }
};
static asn_TYPE_member_t asn_MBR_LPP_GNSS_DataBitAssistanceReq_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_GNSS_DataBitAssistanceReq, gnss_TOD_Req),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_gnss_TOD_Req_constraint_1,
		&asn_PER_memb_gnss_TOD_Req_constr_2,
		0,
		"gnss-TOD-Req"
		},
	{ ATF_POINTER, 1, offsetof(struct LPP_GNSS_DataBitAssistanceReq, gnss_TOD_FracReq),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_gnss_TOD_FracReq_constraint_1,
		&asn_PER_memb_gnss_TOD_FracReq_constr_3,
		0,
		"gnss-TOD-FracReq"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_GNSS_DataBitAssistanceReq, dataBitInterval),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_dataBitInterval_constraint_1,
		&asn_PER_memb_dataBitInterval_constr_4,
		0,
		"dataBitInterval"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_GNSS_DataBitAssistanceReq, gnss_SignalType),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_SignalIDs,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-SignalType"
		},
	{ ATF_POINTER, 1, offsetof(struct LPP_GNSS_DataBitAssistanceReq, gnss_DataBitsReq),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_DataBitsReqSatList,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-DataBitsReq"
		},
};
static int asn_MAP_LPP_GNSS_DataBitAssistanceReq_oms_1[] = { 1, 4 };
static ber_tlv_tag_t asn_DEF_LPP_GNSS_DataBitAssistanceReq_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_LPP_GNSS_DataBitAssistanceReq_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gnss-TOD-Req at 3766 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* gnss-TOD-FracReq at 3767 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* dataBitInterval at 3768 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* gnss-SignalType at 3769 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* gnss-DataBitsReq at 3770 */
};
static asn_SEQUENCE_specifics_t asn_SPC_LPP_GNSS_DataBitAssistanceReq_specs_1 = {
	sizeof(struct LPP_GNSS_DataBitAssistanceReq),
	offsetof(struct LPP_GNSS_DataBitAssistanceReq, _asn_ctx),
	asn_MAP_LPP_GNSS_DataBitAssistanceReq_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_LPP_GNSS_DataBitAssistanceReq_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	4,	/* Start extensions */
	6	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_LPP_GNSS_DataBitAssistanceReq = {
	"LPP_GNSS-DataBitAssistanceReq",
	"LPP_GNSS-DataBitAssistanceReq",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_LPP_GNSS_DataBitAssistanceReq_tags_1,
	sizeof(asn_DEF_LPP_GNSS_DataBitAssistanceReq_tags_1)
		/sizeof(asn_DEF_LPP_GNSS_DataBitAssistanceReq_tags_1[0]), /* 1 */
	asn_DEF_LPP_GNSS_DataBitAssistanceReq_tags_1,	/* Same as above */
	sizeof(asn_DEF_LPP_GNSS_DataBitAssistanceReq_tags_1)
		/sizeof(asn_DEF_LPP_GNSS_DataBitAssistanceReq_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_LPP_GNSS_DataBitAssistanceReq_1,
	5,	/* Elements count */
	&asn_SPC_LPP_GNSS_DataBitAssistanceReq_specs_1	/* Additional specs */
};

