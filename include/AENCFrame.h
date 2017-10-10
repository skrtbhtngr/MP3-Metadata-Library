/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct AENCFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Owner identifier"
    char     *oid;

    //There may be more than one "AENC" frames in a tag,
    //but only one with the same 'Owner identifier'. 
    struct AENCFrame   *next;

} AENCFrame;
