/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //There may only be one "EQUA" frame in each tag. 

    //Inherit the basic properties of every frame.
    Frame    frame;
    
    //Only one EQUA frame in each tag

    //"Adjustment bits"
    uint8_t adjBits;

    //Equalization data
    //It needs to be parsed further.
    uint8_t *data;

} EQUAFrame;