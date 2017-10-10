/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct PRIVFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Owner identifier"
    char *ownerId;

    //"The private data"
    uint8_t *data;

    //The tag may contain more than one "PRIV" frame,
    //but only with different contents.
    struct PRIVFrame *next;

} PRIVFrame;
