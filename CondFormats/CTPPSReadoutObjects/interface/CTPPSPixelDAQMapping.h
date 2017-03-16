/****************************************************************************
*
* 
* Authors: 
*   F.Ferro ferro@ge.infn.it
*
****************************************************************************/

#ifndef CondFormats_CTPPSReadoutObjects_CTPPSPixelDAQMapping
#define CondFormats_CTPPSReadoutObjects_CTPPSPixelDAQMapping

#include "CondFormats/Serialization/interface/Serializable.h"
#include "CondFormats/CTPPSReadoutObjects/interface/CTPPSPixelFramePosition.h"
#include "CondFormats/CTPPSReadoutObjects/interface/CTPPSPixelIndices.h"

#include <map>

//----------------------------------------------------------------------------------------------------

/**
 *\brief Contains mappind data related to a ROC.
 */
class CTPPSPixelROCInfo
{
  public:
    /// the symbolic id
    uint32_t iD;

    unsigned int roc;
    
    friend std::ostream& operator << (std::ostream& s, const CTPPSPixelROCInfo &fp);

    COND_SERIALIZABLE;
};

//----------------------------------------------------------------------------------------------------

/**
 *\brief The mapping between FramePosition and VFATInfo.
 */
class CTPPSPixelDAQMapping
{
  public:
    std::map<CTPPSPixelFramePosition, CTPPSPixelROCInfo> ROCMapping;
    
    void insert(const CTPPSPixelFramePosition &fp, const CTPPSPixelROCInfo &vi);

    COND_SERIALIZABLE;

};

#endif
