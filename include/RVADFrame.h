/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //Only one RVAD frame in each tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Increment/decrement"
    uint8_t incrDecr;

    //Bits 0 to 5 in the "Increment/decrement" field
    bool rightChannel;
    bool leftChannel;
    bool rightBackChannel;
    bool leftBackChannel;
    bool centerChannel;
    bool bassChannel;

    //"Bits used for volume description"
    uint8_t bitsUsed;

    //"Relative volume change, right"
    uint8_t *relVolChangeRight;

    //"Relative volume change, left"
    uint8_t *relVolChangeLeft;

    //"Peak volume right"
    uint8_t *peakVolRight;

    //"Peak volume left"
    uint8_t *peakVolLeft;

    //"Relative volume change, right back"
    uint8_t *relVolChangeRightBack;

    //"Relative volume change, left back"
    uint8_t *relVolChangeLeftBack;

    //"Peak volume right back"
    uint8_t *peakVolRightBack;

    //"Peak volume left back"
    uint8_t *peakVolLeftBack;

    //"Relative volume change, center"
    uint8_t *relVolChangeCenter;

    //"Peak volume center"
    uint8_t *peakVolCenter;

    //"Relative volume change, bass"
    uint8_t *relVolChangeBass;

    //"Peak volume bass"
    uint8_t *peakVolBass;

} RVADFrame;