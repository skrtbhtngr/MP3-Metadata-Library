/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_RVRB_REVL_LEN_v2 2
#define FRAME_RVRB_REVR_LEN_v2 2

typedef struct
{
    //Only one RVRB frame in each tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Reverb left (ms)"
    uint8_t revLeft[FRAME_RVRB_REVL_LEN_v2];

    //"Reverb right (ms)"
    uint8_t revRight[FRAME_RVRB_REVR_LEN_v2];

    //"Reverb bounces, left"
    uint8_t revBouncesLeft;

    //"Reverb bounces, right"
    uint8_t revBouncesRight;

    //"Reverb feedback, left to left"
    uint8_t revFeedbackLL;

    //"Reverb feedback, left to right"
    uint8_t revFeedbackLR;

    //"Reverb feedback, right to right"
    uint8_t revFeedbackRR;

    //"Reverb feedback, right to left"
    uint8_t revFeedbackRL;

    //"Premix left to right"
    uint8_t premixLR;

    //"Premix right to left"
    uint8_t premixRL;

} RVRBFrame;