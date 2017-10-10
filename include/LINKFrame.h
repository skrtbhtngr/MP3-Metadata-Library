/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_LINK_FID_LEN_v2 3

typedef struct LINKFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Frame identifier"
    uint8_t fid[FRAME_LINK_FID_LEN_v2];

    //"URL"
    char *url;

    //"ID and additional data"
    char **strings;

    //There may be more than one "LINK" frame in a tag,
    //but only one with the same contents.
    struct LINKFrame *next;

} LINKFrame;
