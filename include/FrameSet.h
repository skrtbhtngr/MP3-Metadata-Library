/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "TFrame.h"
#include "WFrame.h"
#include "AENCFrame.h"
#include "APICFrame.h"
#include "COMMFrame.h"
#include "COMRFrame.h"
#include "ENCRFrame.h"
#include "EQUAFrame.h"
#include "ETCOFrame.h"
#include "GEOBFrame.h"
#include "GRIDFrame.h"
#include "IPLSFrame.h"
#include "LINKFrame.h"
#include "MCDIFrame.h"
#include "MLLTFrame.h"
#include "OWNEFrame.h"
#include "PCNTFrame.h"
#include "POPMFrame.h"
#include "POSSFrame.h"
#include "PRIVFrame.h"
#include "RBUFFrame.h"
#include "RVADFrame.h"
#include "RVRBFrame.h"
#include "SYLTFrame.h"
#include "SYTCFrame.h"
#include "TXXXFrame.h"
#include "UFIDFrame.h"
#include "USERFrame.h"
#include "USLTFrame.h"
#include "WXXXFrame.h"

/*
    This structure contains all the possible frames
    that can be present in a tag.
    It serves as a handler for the messy code
    due to includes for different frame types.
*/
typedef struct
{
    TFrame        *tFrame;
    WFrame        *wFrame;

    AENCFrame     *aencFrame;
    APICFrame     *apicFrame;
    COMMFrame     *commFrame;
    COMRFrame     *comrFrame;
    ENCRFrame     *encrFrame;
    EQUAFrame     *equaFrame;
    ETCOFrame     *etcoFrame;
    GEOBFrame     *geobFrame;
    GRIDFrame     *gridFrame;
    IPLSFrame     *iplsFrame;
    LINKFrame     *linkFrame;
    MCDIFrame     *mcdiFrame;
    MLLTFrame     *mlltFrame;
    OWNEFrame     *owneFrame;
    PCNTFrame     *pcntFrame;
    POPMFrame     *popmFrame;
    POSSFrame     *possFrame;
    PRIVFrame     *privFrame;
    RBUFFrame     *rbufFrame;
    RVADFrame     *rvadFrame;
    RVRBFrame     *rvrbFrame;
    SYLTFrame     *syltFrame;
    SYTCFrame     *sytcFrame;
    TXXXFrame     *txxxFrame;
    UFIDFrame     *ufidFrame;
    USERFrame     *userFrame;
    USLTFrame     *usltFrame;
    WXXXFrame     *wxxxFrame;

} FrameSet;
