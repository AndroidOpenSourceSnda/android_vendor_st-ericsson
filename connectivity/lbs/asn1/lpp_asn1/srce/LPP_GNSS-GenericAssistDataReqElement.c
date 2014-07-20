/*
 * LPP_GNSS-GenericAssistDataReqElement.c
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

#include "LPP_GNSS-GenericAssistDataReqElement.h"

static asn_TYPE_member_t asn_MBR_LPP_GNSS_GenericAssistDataReqElement_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_ID,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-ID"
		},
	{ ATF_POINTER, 10, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, sbas_ID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_SBAS_ID,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"sbas-ID"
		},
	{ ATF_POINTER, 9, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_TimeModelsReq),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_TimeModelListReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-TimeModelsReq"
		},
	{ ATF_POINTER, 8, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_DifferentialCorrectionsReq),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_DifferentialCorrectionsReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-DifferentialCorrectionsReq"
		},
	{ ATF_POINTER, 7, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_NavigationModelReq),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_NavigationModelReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-NavigationModelReq"
		},
	{ ATF_POINTER, 6, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_RealTimeIntegrityReq),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_RealTimeIntegrityReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-RealTimeIntegrityReq"
		},
	{ ATF_POINTER, 5, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_DataBitAssistanceReq),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_DataBitAssistanceReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-DataBitAssistanceReq"
		},
	{ ATF_POINTER, 4, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_AcquisitionAssistanceReq),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_AcquisitionAssistanceReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-AcquisitionAssistanceReq"
		},
	{ ATF_POINTER, 3, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_AlmanacReq),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_AlmanacReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-AlmanacReq"
		},
	{ ATF_POINTER, 2, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_UTCModelReq),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_UTC_ModelReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-UTCModelReq"
		},
	{ ATF_POINTER, 1, offsetof(struct LPP_GNSS_GenericAssistDataReqElement, gnss_AuxiliaryInformationReq),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LPP_GNSS_AuxiliaryInformationReq,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"gnss-AuxiliaryInformationReq"
		},
};
static int asn_MAP_LPP_GNSS_GenericAssistDataReqElement_oms_1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
static ber_tlv_tag_t asn_DEF_LPP_GNSS_GenericAssistDataReqElement_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_LPP_GNSS_GenericAssistDataReqElement_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gnss-ID at 3679 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sbas-ID at 3680 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* gnss-TimeModelsReq at 3681 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* gnss-DifferentialCorrectionsReq at 3682 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* gnss-NavigationModelReq at 3683 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* gnss-RealTimeIntegrityReq at 3684 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* gnss-DataBitAssistanceReq at 3685 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* gnss-AcquisitionAssistanceReq at 3686 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* gnss-AlmanacReq at 3687 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* gnss-UTCModelReq at 3688 */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 } /* gnss-AuxiliaryInformationReq at 3689 */
};
static asn_SEQUENCE_specifics_t asn_SPC_LPP_GNSS_GenericAssistDataReqElement_specs_1 = {
	sizeof(struct LPP_GNSS_GenericAssistDataReqElement),
	offsetof(struct LPP_GNSS_GenericAssistDataReqElement, _asn_ctx),
	asn_MAP_LPP_GNSS_GenericAssistDataReqElement_tag2el_1,
	11,	/* Count of tags in the map */
	asn_MAP_LPP_GNSS_GenericAssistDataReqElement_oms_1,	/* Optional members */
	10, 0,	/* Root/Additions */
	10,	/* Start extensions */
	12	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_LPP_GNSS_GenericAssistDataReqElement = {
	"LPP_GNSS-GenericAssistDataReqElement",
	"LPP_GNSS-GenericAssistDataReqElement",
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
	asn_DEF_LPP_GNSS_GenericAssistDataReqElement_tags_1,
	sizeof(asn_DEF_LPP_GNSS_GenericAssistDataReqElement_tags_1)
		/sizeof(asn_DEF_LPP_GNSS_GenericAssistDataReqElement_tags_1[0]), /* 1 */
	asn_DEF_LPP_GNSS_GenericAssistDataReqElement_tags_1,	/* Same as above */
	sizeof(asn_DEF_LPP_GNSS_GenericAssistDataReqElement_tags_1)
		/sizeof(asn_DEF_LPP_GNSS_GenericAssistDataReqElement_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_LPP_GNSS_GenericAssistDataReqElement_1,
	11,	/* Elements count */
	&asn_SPC_LPP_GNSS_GenericAssistDataReqElement_specs_1	/* Additional specs */
};

