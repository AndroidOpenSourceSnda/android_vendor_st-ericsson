/*
 * SUPL_ULP_AreaEventType.c
 *
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * Author: david.gowers@stericsson.com for ST-Ericsson.
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
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "SUPL-TRIGGERED-START"
 *     found in "ULP_v2.0.0.asn"
 *     `asn1c -gen-PER -fcompound-names`
 */

#include <asn_internal.h>

#include "SUPL_ULP_AreaEventType.h"

int
AreaEventType_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
            asn_app_constraint_failed_f *ctfailcb, void *app_key) {
    /* Replace with underlying type checker */
    td->check_constraints = asn_DEF_ENUMERATED.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using ENUMERATED,
 * so here we adjust the DEF accordingly.
 */
static void
AreaEventType_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
    td->free_struct    = asn_DEF_ENUMERATED.free_struct;
    td->print_struct   = asn_DEF_ENUMERATED.print_struct;
    td->ber_decoder    = asn_DEF_ENUMERATED.ber_decoder;
    td->der_encoder    = asn_DEF_ENUMERATED.der_encoder;
    td->xer_decoder    = asn_DEF_ENUMERATED.xer_decoder;
    td->xer_encoder    = asn_DEF_ENUMERATED.xer_encoder;
    td->uper_decoder   = asn_DEF_ENUMERATED.uper_decoder;
    td->uper_encoder   = asn_DEF_ENUMERATED.uper_encoder;
    if(!td->per_constraints)
        td->per_constraints = asn_DEF_ENUMERATED.per_constraints;
    td->elements       = asn_DEF_ENUMERATED.elements;
    td->elements_count = asn_DEF_ENUMERATED.elements_count;
     /* td->specifics      = asn_DEF_ENUMERATED.specifics;    // Defined explicitly */
}

void
AreaEventType_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only) {
    AreaEventType_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
AreaEventType_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
    AreaEventType_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
AreaEventType_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode) {
    AreaEventType_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
AreaEventType_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key) {
    AreaEventType_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
AreaEventType_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size) {
    AreaEventType_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
AreaEventType_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key) {
    AreaEventType_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

asn_dec_rval_t
AreaEventType_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
    AreaEventType_1_inherit_TYPE_descriptor(td);
    return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

asn_enc_rval_t
AreaEventType_encode_uper(asn_TYPE_descriptor_t *td,
        asn_per_constraints_t *constraints,
        void *structure, asn_per_outp_t *per_out) {
    AreaEventType_1_inherit_TYPE_descriptor(td);
    return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_AreaEventType_constr_1 = {
    { APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  3 }    /* (0..3,...) */,
    { APC_UNCONSTRAINED,    -1, -1,  0,  0 },
    0, 0    /* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_AreaEventType_value2enum_1[] = {
    { 0,    12,    "enteringArea" },
    { 1,    10,    "insideArea" },
    { 2,    11,    "outsideArea" },
    { 3,    11,    "leavingArea" }
    /* This list is extensible */
};
static unsigned int asn_MAP_AreaEventType_enum2value_1[] = {
    0,    /* enteringArea(0) */
    1,    /* insideArea(1) */
    3,    /* leavingArea(3) */
    2    /* outsideArea(2) */
    /* This list is extensible */
};
static asn_INTEGER_specifics_t asn_SPC_AreaEventType_specs_1 = {
    asn_MAP_AreaEventType_value2enum_1,    /* "tag" => N; sorted by tag */
    asn_MAP_AreaEventType_enum2value_1,    /* N => "tag"; sorted by N */
    4,    /* Number of elements in the maps */
    5,    /* Extensions before this member */
    1,    /* Strict enumeration */
    0,    /* Native long size */
    0
};
static ber_tlv_tag_t asn_DEF_AreaEventType_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_AreaEventType = {
    "AreaEventType",
    "AreaEventType",
    AreaEventType_free,
    AreaEventType_print,
    AreaEventType_constraint,
    AreaEventType_decode_ber,
    AreaEventType_encode_der,
    AreaEventType_decode_xer,
    AreaEventType_encode_xer,
    AreaEventType_decode_uper,
    AreaEventType_encode_uper,
    0,    /* Use generic outmost tag fetcher */
    asn_DEF_AreaEventType_tags_1,
    sizeof(asn_DEF_AreaEventType_tags_1)
        /sizeof(asn_DEF_AreaEventType_tags_1[0]), /* 1 */
    asn_DEF_AreaEventType_tags_1,    /* Same as above */
    sizeof(asn_DEF_AreaEventType_tags_1)
        /sizeof(asn_DEF_AreaEventType_tags_1[0]), /* 1 */
    &asn_PER_type_AreaEventType_constr_1,
    0, 0,    /* Defined elsewhere */
    &asn_SPC_AreaEventType_specs_1    /* Additional specs */
};

