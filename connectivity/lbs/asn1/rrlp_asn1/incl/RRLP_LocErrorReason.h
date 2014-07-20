/*
 * RRLP_LocErrorReason.h
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
 * From ASN.1 module "RRLP_Components"
 * 	found in "LPP_RRLP_Rel_10.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_RRLP_LocErrorReason_H_
#define	_RRLP_LocErrorReason_H_


#include <asn_application.h>

/* Including external dependencies */
#include <ENUMERATED.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RRLP_LocErrorReason {
	RRLP_LocErrorReason_unDefined	= 0,
	RRLP_LocErrorReason_notEnoughBTSs	= 1,
	RRLP_LocErrorReason_notEnoughSats	= 2,
	RRLP_LocErrorReason_eotdLocCalAssDataMissing	= 3,
	RRLP_LocErrorReason_eotdAssDataMissing	= 4,
	RRLP_LocErrorReason_gpsLocCalAssDataMissing	= 5,
	RRLP_LocErrorReason_gpsAssDataMissing	= 6,
	RRLP_LocErrorReason_methodNotSupported	= 7,
	RRLP_LocErrorReason_notProcessed	= 8,
	RRLP_LocErrorReason_refBTSForGPSNotServingBTS	= 9,
	RRLP_LocErrorReason_refBTSForEOTDNotServingBTS	= 10,
	/*
	 * Enumeration is extensible
	 */
	RRLP_LocErrorReason_notEnoughGANSSSats	= 11,
	RRLP_LocErrorReason_ganssAssDataMissing	= 12,
	RRLP_LocErrorReason_refBTSForGANSSNotServingBTS	= 13
} e_RRLP_LocErrorReason;

/* RRLP_LocErrorReason */
typedef ENUMERATED_t	 RRLP_LocErrorReason_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RRLP_LocErrorReason;
asn_struct_free_f RRLP_LocErrorReason_free;
asn_struct_print_f RRLP_LocErrorReason_print;
asn_constr_check_f RRLP_LocErrorReason_constraint;
ber_type_decoder_f RRLP_LocErrorReason_decode_ber;
der_type_encoder_f RRLP_LocErrorReason_encode_der;
xer_type_decoder_f RRLP_LocErrorReason_decode_xer;
xer_type_encoder_f RRLP_LocErrorReason_encode_xer;
per_type_decoder_f RRLP_LocErrorReason_decode_uper;
per_type_encoder_f RRLP_LocErrorReason_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _RRLP_LocErrorReason_H_ */
