/*
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * This code is ST-Ericsson proprietary and confidential.
 * Any use of the code for whatever purpose is subject to
 * specific written permission of ST-Ericsson SA.
 */
#ifndef _T1XHV_HOST_INTERFACE_JPEGDEC_H_
#define _T1XHV_HOST_INTERFACE_JPEGDEC_H_

#include "t1xhv_retarget.h"

typedef struct 
{
    t_ushort_value      huffman_y_code_dc[12];  /**< \brief Y DC EHUFCO table   */
    t_ushort_value      huffman_y_size_dc[12];   /**< \brief Y DC EHUFSI table */
    t_ushort_value      huffman_y_code_ac[256];  /**< \brief Y AC EHUFCO table   */
    t_ushort_value      huffman_y_size_ac[256];  /**< \brief Y AC EHUFSI table */

    t_ushort_value      huffman_cb_code_dc[12]; /**< \brief Cb DC EHUFCO table   */
    t_ushort_value      huffman_cb_size_dc[12];  /**< \brief Cb DC EHUFSI table */
    t_ushort_value      huffman_cb_code_ac[256]; /**< \brief Cb AC EHUFCO table   */
    t_ushort_value      huffman_cb_size_ac[256]; /**< \brief Cb AC EHUFSI table */

    t_ushort_value      huffman_cr_code_dc[12]; /**< \brief Cr DC EHUFCO table   */
    t_ushort_value      huffman_cr_size_dc[12];  /**< \brief Cr DC EHUFSI table */
    t_ushort_value      huffman_cr_code_ac[256]; /**< \brief Cr AC EHUFCO table   */
    t_ushort_value      huffman_cr_size_ac[256]; /**< \brief Cr AC EHUFSI table */

} ts_t1xhv_vdc_hw_table;
typedef ts_t1xhv_vdc_hw_table *tps_t1xhv_vdc_hw_table;


typedef struct 
{
	t_ushort_value      huffman_bits_dc[16];  /**< \brief Y DC EHUFCO table   */
	t_ushort_value      huffman_val_dc[12];   /**< \brief Y DC EHUFSI table */
	t_long_value      maxcode[18];		/* largest code of length k (-1 if none) */
	t_long_value      valoffset[17];		/* huffval[] offset for codes of length k */	
	t_short_value      look_nbits[256]; /* # bits, or 0 if too long */
	t_ushort_value      look_sym[256]; /* symbol, or unused */	

} ts_t1xhv_vdc_sw_dc_table;

typedef struct 
{
	t_ushort_value      huffman_bits_ac[16];  /**< \brief Y DC EHUFCO table   */
	t_ushort_value      huffman_val_ac[256];   /**< \brief Y DC EHUFSI table */
	t_long_value      maxcode[18];		/* largest code of length k (-1 if none) */
	t_long_value      valoffset[17];		/* huffval[] offset for codes of length k */	
	t_short_value      look_nbits[256]; /* # bits, or 0 if too long */
	t_ushort_value      look_sym[256]; /* symbol, or unused */	
	
} ts_t1xhv_vdc_sw_ac_table;


typedef struct 
{

ts_t1xhv_vdc_sw_dc_table  huffman_y_dc_table;
ts_t1xhv_vdc_sw_ac_table  huffman_y_ac_table;
ts_t1xhv_vdc_sw_dc_table  huffman_cb_dc_table;
ts_t1xhv_vdc_sw_ac_table  huffman_cb_ac_table;
ts_t1xhv_vdc_sw_dc_table  huffman_cr_dc_table;
ts_t1xhv_vdc_sw_ac_table  huffman_cr_ac_table;	

} ts_t1xhv_vdc_sw_table;

typedef ts_t1xhv_vdc_sw_table *tps_t1xhv_vdc_sw_table;

typedef  struct
{
ts_t1xhv_vdc_hw_table  hw_huff_table;
t_ulong_value 	sw_huff_table;
t_ulong_value 	reserved1;
}ts_t1xhv_vdc_huff_table;

typedef ts_t1xhv_vdc_huff_table *tps_t1xhv_vdc_huff_table;

/** \brief This structure defines a JPEG Decode input parameter buffers. */
typedef struct {
    t_ushort_value frame_width;               /**<\brief Destination frame width (i.e. maximum number of samples per line in the source image.
                                                The width of the destination frame (luminance part of the 4:2:0 macroblock buffer) is the smallest 
                                                multiple of 16 greater than or equal to frame_width/downsampling_factor).
                                                    \n Contraints : 1<=(frame_width/16)<=396 and (frame_width/16)*(frame_height/16)<=1200
                                                    \n Alignment : Multiple of 16.*/
    t_ushort_value frame_height;              /**<\brief Destination frame height (i.e. maximum number of lines in the source image. The height of the 
                                                destination frame (luminance part of the 4:2:0 macroblock buffer) is the smallest multiple of 16 greater 
                                                than or equal to frame_height/downsampling_factor).
                                                    \n Alignment : Multiple of 16.*/
    t_ushort_value nb_components;             /**<\brief Total number of components (i.e. total number of components for a JPEG decode subtask (Nf field
                                                of the frame header)).
                                                    \n  1: luminance only.
                                                    \n  3: YCbCr.*/
    t_ushort_value h_sampling_factor_y;       /**<\brief Luminance horizontal sampling factor (i.e. horizontal sampling factor of the luminance component 
                                                (H1 field of the frame header)).
                                                    \n Contraints : It must be either 1, 2, or 4 (3 is not supported) */
    t_ushort_value v_sampling_factor_y;       /**<\brief Luminance vertical sampling factor (i.e. horizontal sampling factor of the luminance component 
                                                (H1 field of the frame header).
                                                    \n Contraints :  It must be either 1, 2, or 4 (3 is not supported) */
    t_ushort_value h_sampling_factor_cb;      /**<\brief Cb chrominance horizontal sampling factor (i.e. horizontal sampling factor of the Cb chrominance 
                                                component for a JPEG decode subtask (H2 field of the frame header)).
                                                    \n Contraints :  It must be either 1, 2, or 4 (3 is not supported). */
    t_ushort_value v_sampling_factor_cb;      /**<\brief Cb chrominance vertical sampling factor (i.e. vertical sampling factor of the Cb chrominance 
                                                  component (V2 field of the frame header)).
                                                    \n Contraints : It must be either 1, 2, or 4 (3 is not supported) */
    t_ushort_value h_sampling_factor_cr;      /**<\brief Cr chrominance horizontal sampling factor (i.e. horizontal sampling factor of the Cr chrominance 
                                                  component (H3 field of the frame header).
                                                    \n Contraints : It must be either 1, 2, or 4 (3 is not supported) */
    t_ushort_value v_sampling_factor_cr;      /**<\brief Cr chrominance vertical sampling factor (i.e. vertical sampling factor of the Cr chrominance 
                                                  component (V3 field of the frame header).
                                                    \n Contraints : It must be either 1, 2, or 4 (3 is not supported) */
    t_ushort_value downsampling_factor;       /**<\brief Downsampling factor (i.e. downsampling factor to be used in order to perform picture downscaling
                                                  as a post-processing of a JPEG decode).
                                                    \n Contraints : It must be either 1, 2, 4 or 8 */
    t_ushort_value restart_interval;          /**<\brief Restart Interval (i.e. number of MCUs (minimum coded units) between two restart markers).*/
    t_ushort_value progressive_mode;          /**<\brief Progressive mode flag (i.e. specifies the use of the progressive process in a JPEG decode 
                                                  (corresponding to a SOF2 start of frame marker). It must be either 0 or 1.).
                                                    \n  0: sequential
                                                    \n  1: pregressive
                                                    \n Contraints : [0,1] */
    t_ushort_value nb_scan_components;        /**<\brief Number of components of the scan (i.e. number of components of the current scan
                                                  (Ns field of the scan header)).
                                                    \n Contraints : It must be either 1, 2 or 3 */
    t_ushort_value component_selector_y;      /**<\brief Luminance component selection flag (i.e. selection of the luminance component in the current scan 
                                                  (it depends on the CSi fields in the scan header).
                                                    \n  0: the Y component is not present in the current scan
                                                    \n  1: the Y component is present in the current scan (i.e. CS1=1)
                                                    \n Contraints : [0,1] */
    t_ushort_value component_selector_cb;     /**<\brief Cb chrominance component selection flag (i.e. selection of the Cb chrominance component in the current 
                                                  scan (it depends on the CSi fields in the scan header)).
                                                    \n  0: the Cb component is not present in the current scan
                                                    \n  1: the Cb component is present in the current scan (i.e. CS1=2 or CS2=2)
                                                    \n Contraints : [0,1] */
    t_ushort_value component_selector_cr;     /**<\brief Cr chrominance component selection flag (i.e. selection of the Cr chrominance component in the current
                                                  scan (it depends on the CSi fields in the scan header)).
                                                    \n  0: the Cr component is not present in the current scan
                                                    \n  1: the Cr component is present in the current scan (i.e. CS1=3 or CS2=3 or CS3=3)
                                                    \n Contraints : [0,1] */
    t_ushort_value start_spectral_selection;  /**<\brief Spectral selection start value (i.e. position of the first DCT coefficient in each block in zig-zag 
                                                  order in the current scan (Ss field in the scan header)). It is not used if progressive_mode=0.
                                                    \n Contraints : [0,63] */
    t_ushort_value end_spectral_selection;    /**<\brief Spectral selection end value (i.e. position of the last DCT coefficient in each block in zig-zag order
                                                  in the current scan (Se field in the scan header)). It is not used if progressive_mode=0.
                                                    \n Contraints : [end_spectral_selection,63] */
    t_ushort_value successive_approx_position;/**<\brief Successive approximation position (i.e. �point transform� (i.e. bit positions of the coefficients) used in 
                                                  the current scan (Ah/Al fields in the scan header). It is not used if progressive_mode=0.
                                                    \n successive_approx_position (bits 0 to 3) AH Successive approximation bit position high. It is not used if
                                                    progressive_mode=0.
                                                    \n successive_approx_position (bits 4 to 7) AL Successive approximation bit position low. It is not used if
                                                    progressive_mode=0.
                                                    \n Contraints : [0,7] for AH and AL */
     t_ushort_value ace_strength;              /**<\brief Automatic Contrast Enhancement strength (i.e. correction level of the Automatic Contrast Enhancement 
                                                  \analysis. It has an impact on the ace_offset output parameters, that can be used in a display process.
                                                    \n Contraints : [1,8] */                                        
     t_ushort_value ace_enable;                /**<\brief Automatic Contrast Enhancement enable (i.e. enables the Automatic Contrast Enhancement analysis in a 
                                                   \(it enables the computation of the ace_offset output parameters, that can be used in a display process).
                                                    \n  0: ACE disabled
                                                    \n  1: ACE enabled
                                                    \n Contraints : [0,1] */  
    t_ushort_value noslice_enable;            /**< \brief flag to enable noslice mode */         
    t_ulong_value  buffer_size;				  /**<\brief buffer_size           */

    t_ushort_value quant_y[64];                /**< \brief y quantization table   */
    t_ushort_value quant_cb[64];               /**< \brief cb quantization table   */
    t_ushort_value quant_cr[64];               /**< \brief cr quantization table   */

    ts_t1xhv_vdc_huff_table   huff_table;
    t_ushort_value window_width;               /**<\brief Crop window width */
    t_ushort_value window_height;              /**<\brief Crop window height */
    t_ushort_value window_horizontal_offset;   /**<\brief offset of window width when there's a crop*/
    t_ushort_value window_vertical_offset;     /**<\brief offset of window height when there's a crop*/
    t_ulong_value reserved_3;                  /**<\brief Reserved 32             */
    t_ulong_value reserved_4;                  /**<\brief Reserved 32             */

} ts_t1xhv_vdc_jpeg_param_in, *tps_t1xhv_vdc_jpeg_param_in;

typedef struct t1xhv_vdc_jpeg_param_inout {

    t_ulong_value  mcu_index;         /**<\brief MCU index                              */
    t_ulong_value  end_of_band_run;   /**< \brief end of band value in progressive mode */
    t_ushort_value dc_predictor_y;    /**<\brief Luma DC ppredictor                     */
    t_ushort_value dc_predictor_cb;   /**<\brief Cb chroma DC predictor                 */
    t_ushort_value dc_predictor_cr;   /**<\brief Cr Chroma DC predictot                 */
    t_ushort_value slice_pos;        /**<\brief Reserved 32                            */
    t_ulong_value  ace_count0;        /**<\brief Automatic Contrast Enhancement offet 0 */
    t_ulong_value  ace_count1;        /**<\brief Automatic Contrast Enhancement offet 1 */
    t_ulong_value  ace_count2;        /**<\brief Automatic Contrast Enhancement offet 2 */
    t_ulong_value  ace_count3;        /**<\brief Automatic Contrast Enhancement offet 3 */
    t_ulong_value  crop_mcu_index;              /**<\brief MCU index in crop                      */
    t_ulong_value  crop_mcu_index_in_row;       /**<\brief MCU index in crop in row               */
t_ushort_value mcu_index_rst;			/**<\brief mcu_index_rst							*/
    t_ushort_value rst_value;				/**<\brief restart marker value						*/
    t_ulong_value  reserved_1;				/**<\brief Reserved 32		*/		
       

} ts_t1xhv_vdc_jpeg_param_inout, *tps_t1xhv_vdc_jpeg_param_inout;

/** \brief Structure for output parameters of JPEG encode task */ 
typedef struct t1xhv_vdc_jpeg_param_out {

    t_ushort_value  error_type;                /**<\brief Error type (see t_t1xhv_decoder_info for details in \ref sdcJpegendAlgoGroup)).*/
    t_ushort_value last_slice;				   /**<\brief last_slice								*/
    t_ushort_value  ace_offset0;                /**<\brief Automatic Contrast Enhancement offset 0 (i.e. final offset 0 of the Automatic Contrast Enhancement analysis,**/
                                                /**when a scan is completed (it is equal to 0 if the scan has not been completed)).*/
    t_ushort_value  ace_offset1;                /**<\brief Automatic Contrast Enhancement offset 1 (i.e. final offset 0 of the Automatic Contrast Enhancement analysis,*/
                                                /**when a scan is completed (it is equal to 0 if the scan has not been completed)).*/
    t_ushort_value  ace_offset2;                /**<\brief Automatic Contrast Enhancement offset 2 (i.e. final offset 0 of the Automatic Contrast Enhancement analysis,**/
                                                /**when a scan is completed (it is equal to 0 if the scan has not been completed)).*/
    t_ushort_value  ace_offset3;                /**<\brief Automatic Contrast Enhancement offset 3 (i.e. final offset 0 of the Automatic Contrast Enhancement analysis,
                                                /**when a scan is completed (it is equal to 0 if the scan has not been completed)).*/
    t_ulong_value out_buff_size;    /**<\brief out_buff_size							*/

} ts_t1xhv_vdc_jpeg_param_out, *tps_t1xhv_vdc_jpeg_param_out;
#endif /* _T1XHV_HOST_INTERFACE_JPEGDEC_H_ */

