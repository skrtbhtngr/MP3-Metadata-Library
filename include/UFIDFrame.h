/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_UFID_ID_MAXLEN_v2 64

typedef struct UFIDFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Owner identifier"
    char *ownerId;

    //"Identifier"
    //up to 64 bytes binary data
    uint8_t id[FRAME_UFID_ID_MAXLEN_v2];

    //There may be more than one "UFID" frame in a tag,
    //but only one with the same 'Owner identifier'.
    struct UFIDFrame *next;

} UFIDFrame;
