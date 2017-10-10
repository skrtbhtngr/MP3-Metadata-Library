/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //Only one MCDI frame in each tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"CD TOC"
    uint8_t *cdTOC;

} MCDIFrame;