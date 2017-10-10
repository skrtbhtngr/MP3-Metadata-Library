/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_RBUF_BUFS_LEN_v2 3
#define FRAME_RBUF_OFFS_LEN_v2 4

typedef struct
{
    //There may only be one "RBUF" frame in each tag.
    
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Buffer size"
    uint8_t bufferSize[FRAME_RBUF_BUFS_LEN_v2];

    //"Embedded info flag"
    uint8_t flag;

    //"Offset to next tag"
    uint8_t offset[FRAME_RBUF_OFFS_LEN_v2];

} RBUFFrame;
