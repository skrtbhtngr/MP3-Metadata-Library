/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //Only one MLLT frame in each tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"MPEG frames between reference"
    uint8_t framesRef[2];

    //"Bytes between reference"
    uint8_t bytesRef[3];

    //"Milliseconds between reference"
    uint8_t msRef[3];

    //"Bits for bytes deviation"
    uint8_t bitsBytesDev;

    //"Bits for milliseconds deviation"
    uint8_t bitsMsDev;

    //Reference data
    //This thing remains to be coded!
    uint8_t *refData;

} MLLTFrame;