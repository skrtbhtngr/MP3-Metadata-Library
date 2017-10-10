/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //There may only be one "POSS" frame in each tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Time stamp format"
    uint8_t  timestampFormat;

    //"Position"
    uint8_t  *position;

} POSSFrame;