/*****************************************************************************/
/**
*  � ST-Ericsson, 2009 - All rights reserved

*  Reproduction and Communication of this document is strictly prohibited
*  unless specifically authorized in writing by ST-Ericsson
*
* \brief   AMR Encoder proxy
* \author  ST-Ericsson
*/
/*****************************************************************************/
#include "AMREncoder.h"
#include "AMRNmfHost_Encoder.h"
#ifndef HOST_ONLY
#include "AMRNmfMpc_Encoder.h"
#endif
#include "AMREnc_BitstreamPort.h"
#include "AMREnc_PcmPort.h"

#include "OMX_Symbian_ExtensionNames_Ste.h"
#include "audio_chipset_api_index.h"
#include "audio_codecs_chipset_api.h"

// UID top dictionnary (generated by trace compiler)
#include "AMR_ENC_top.h"
#include "AMR_HOST_ENC_top.h"

// TODO FIXME: manage buffers that are not 32-bit multiple (for Host proxy only)
#define SUPPORTED_BUFFER_SIZE_MULTIPLE_IN_BYTES 4

AMREncoder_RDB::AMREncoder_RDB(OMX_U32 nbOfDomains) 
	: ENS_ResourcesDB(nbOfDomains)
{
    setNbOfMemoryPresets(5);
    setMemoryPreset(1); // ALL_DDR
    for (unsigned int i=0;i<nbOfDomains;i++) {
        setDefaultNMFDomainType(RM_NMFD_PROCSIA,i);
    }
}

OMX_ERRORTYPE AMREncoder::createResourcesDB() {
    mRMP = new AMREncoder_RDB(getPortCount());
    if (mRMP == 0) {
        return OMX_ErrorInsufficientResources;
    } 
    else {
        return OMX_ErrorNone;
    }
}
OMX_ERRORTYPE amrhostencFactoryMethod(ENS_Component_p * ppENSComponent) {
    OMX_ERRORTYPE error  = OMX_ErrorNone;

    AMREncoder *amrenc = new AMREncoder(true);
    if (amrenc == 0) {
        return OMX_ErrorInsufficientResources;
    }

    error = amrenc->construct();

    if (error != OMX_ErrorNone) {
        delete amrenc;
        *ppENSComponent = 0;
        return OMX_ErrorInsufficientResources;
    } else {
        *ppENSComponent = amrenc;
    }

    AMRNmfHost_Encoder *amrenc_ProcessingComp = new AMRNmfHost_Encoder(*amrenc);

    if (amrenc_ProcessingComp == 0) {
        delete amrenc;
        return OMX_ErrorInsufficientResources;
    }

    amrenc->setProcessingComponent(amrenc_ProcessingComp);

    return error;
}

#ifndef HOST_ONLY
OMX_ERRORTYPE amrencFactoryMethod(ENS_Component_p * ppENSComponent) {
    OMX_ERRORTYPE error  = OMX_ErrorNone;

    AMREncoder *amrenc = new AMREncoder(false);
    if (amrenc == 0) {
        return OMX_ErrorInsufficientResources;
    }

    error = amrenc->construct();

    if (error != OMX_ErrorNone) {
        delete amrenc;
        *ppENSComponent = 0;
        return OMX_ErrorInsufficientResources;
    } else {
        *ppENSComponent = amrenc;
    }

    AMRNmfMpc_Encoder *amrenc_ProcessingComp = new AMRNmfMpc_Encoder(*amrenc);

    if (amrenc_ProcessingComp == 0) {
        delete amrenc;
        return OMX_ErrorInsufficientResources;
    }

    amrenc->setProcessingComponent(amrenc_ProcessingComp);

    return error;
}
#endif /* HOST_ONLY */

OMX_ERRORTYPE AMREncoder::createAMREncBitstreamPort(const OMX_AUDIO_PARAM_AMRTYPE &defaultAmrSettings)
{
  OMX_U32 supported_length = getMaxFrameSize()/8;

  if (mIsHost) {
    supported_length += (SUPPORTED_BUFFER_SIZE_MULTIPLE_IN_BYTES - 1);
    supported_length &= ~(SUPPORTED_BUFFER_SIZE_MULTIPLE_IN_BYTES - 1);
  }

    AMREnc_BitstreamPort *amrPort = 
      new AMREnc_BitstreamPort(1, OMX_DirOutput, supported_length, defaultAmrSettings, mIsHost, *this);

    if (amrPort == 0) {
        return OMX_ErrorInsufficientResources;
    }

    addPort(amrPort);

    return OMX_ErrorNone;
}

OMX_ERRORTYPE  AMREncoder::construct()
{
    OMX_ERRORTYPE error;
    OMX_AUDIO_PARAM_PCMMODETYPE defaultPcmSettings;
    OMX_AUDIO_PARAM_AMRTYPE defaultAmrSettings;

    defaultPcmSettings.nPortIndex     = 0;
    defaultPcmSettings.eNumData       = OMX_NumericalDataSigned;
    defaultPcmSettings.eEndian        = OMX_EndianLittle;
    defaultPcmSettings.bInterleaved   = OMX_TRUE;
    defaultPcmSettings.ePCMMode       = OMX_AUDIO_PCMModeLinear;
    defaultPcmSettings.nBitPerSample  = 16;

    defaultPcmSettings.nChannels      = 1;
    defaultPcmSettings.nSamplingRate  = 8000;

    defaultPcmSettings.eChannelMapping[0] = OMX_AUDIO_ChannelCF;

    defaultAmrSettings.nSize           = sizeof(OMX_AUDIO_PARAM_AMRTYPE);
    getOmxIlSpecVersion(&defaultAmrSettings.nVersion);

    defaultAmrSettings.nPortIndex      = 1;
    defaultAmrSettings.nChannels       = 1;
    defaultAmrSettings.nBitRate        = 12200;
    defaultAmrSettings.eAMRBandMode    = OMX_AUDIO_AMRBandModeNB7;
#ifdef FORCE_DTXOFF
    defaultAmrSettings.eAMRDTXMode     = OMX_AUDIO_AMRDTXModeOff;
#else
    defaultAmrSettings.eAMRDTXMode     = OMX_AUDIO_AMRDTXModeOnVAD1;
#endif
#ifdef FORCE_RTP_WHEN_FSF
    defaultAmrSettings.eAMRFrameFormat = OMX_AUDIO_AMRFrameFormatRTPPayload;
#else
    defaultAmrSettings.eAMRFrameFormat = OMX_AUDIO_AMRFrameFormatFSF;
#endif

    error = AFM_Encoder::construct(
            OMX_AUDIO_CodingAMR, getSampleFrameSize(), defaultPcmSettings);
    if (error != OMX_ErrorNone) return error;

    ENS_String<20> role = "audio_encoder.amrnb";
    role.put((OMX_STRING)mRoles[0]);
    setActiveRole(mRoles[0]);

    error = createAMREncBitstreamPort(defaultAmrSettings);
    if (error != OMX_ErrorNone) return error;

    return OMX_ErrorNone;
}

OMX_ERRORTYPE AMREncoder::getExtensionIndex(OMX_STRING cParameterName,
						     OMX_INDEXTYPE* pIndexType) const
{
    if (ENS_String<ENS_COMPONENT_NAME_MAX_LENGTH>(cParameterName) 
            == OMX_SYMBIAN_INDEX_CONFIG_AUDIO_AMRMODE_NAME) {
        *pIndexType = (OMX_INDEXTYPE)OMX_IndexConfigAudioAmrMode;
        return OMX_ErrorNone;
    }

    return AFM_Component::getExtensionIndex(cParameterName, pIndexType);
}

OMX_ERRORTYPE AMREncoder::setConfig(
        OMX_INDEXTYPE nConfigIndex,
        OMX_PTR pComponentConfigStructure)
{
    switch (nConfigIndex) {
        case OMX_IndexConfigAudioAmrMode:
            {
                CHECK_STRUCT_SIZE_AND_VERSION(pComponentConfigStructure,OMX_AUDIO_CONFIG_AMRMODETYPE);
                OMX_AUDIO_CONFIG_AMRMODETYPE *amrConfig =
                    (OMX_AUDIO_CONFIG_AMRMODETYPE *)pComponentConfigStructure;
                AMREnc_BitstreamPort * BSPort;

                if (amrConfig->nPortIndex != 1){
                    return OMX_ErrorBadParameter;
                }

                BSPort = static_cast<AMREnc_BitstreamPort *>(getPort(1));
                return BSPort->setBitRate(amrConfig->eAMRBandMode);
            }

        default:
            return AFM_Encoder::setConfig(
                    nConfigIndex, pComponentConfigStructure);
    }
}


OMX_ERRORTYPE AMREncoder::getConfig(
        OMX_INDEXTYPE nConfigIndex,
        OMX_PTR pComponentConfigStructure) const
{
    OMX_ERRORTYPE error;
    switch (nConfigIndex) {
        case OMX_IndexConfigAudioAmrMode:
            {
                const AMREnc_BitstreamPort * BSPort = static_cast<const AMREnc_BitstreamPort *>(getPort(1));
                OMX_AUDIO_PARAM_AMRTYPE amrOmxParams;
                CHECK_STRUCT_SIZE_AND_VERSION(pComponentConfigStructure,OMX_AUDIO_CONFIG_AMRMODETYPE);
                OMX_AUDIO_CONFIG_AMRMODETYPE *amrConfig =
                    (OMX_AUDIO_CONFIG_AMRMODETYPE *)pComponentConfigStructure;

                if (amrConfig->nPortIndex != 1){
                    return OMX_ErrorBadParameter;
                }

                amrOmxParams.nSize           = sizeof(OMX_AUDIO_PARAM_AMRTYPE);
                getOmxIlSpecVersion(&amrOmxParams.nVersion);

                error = BSPort->getParameter(OMX_IndexParamAudioAmr, &amrOmxParams);
                if (error != OMX_ErrorNone) return error;

                amrConfig->eAMRBandMode = amrOmxParams.eAMRBandMode;

                return OMX_ErrorNone;
            }

        default:
            return AFM_Encoder::getConfig(
                    nConfigIndex, pComponentConfigStructure);
    }
}

OMX_ERRORTYPE AMREncoder::createPcmPort(
        OMX_U32 nIndex,
        OMX_DIRTYPE eDir,
        OMX_U32 nBufferSizeMin,
        const OMX_AUDIO_PARAM_PCMMODETYPE &defaultPcmSettings)
{
    ENS_Port * port = new AMREnc_PcmPort(
                nIndex, eDir, nBufferSizeMin, defaultPcmSettings, mIsHost, *this);
    if (port == 0) {
        return OMX_ErrorInsufficientResources;
    }

    addPort(port);

    return OMX_ErrorNone;
}

OMX_U32 AMREncoder::getUidTopDictionnary(void)
{
    if (mIsHost){
        return KOstAMR_HOST_ENC_top_ID;
    }
    else{
        return KOstAMR_ENC_top_ID;
    }
}
