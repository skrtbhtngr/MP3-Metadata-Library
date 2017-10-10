/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //Only one PCNT frame in each tag

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Counter"
    uint8_t *counter;

} PCNTFrame;