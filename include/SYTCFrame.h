/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //Only one SYTC frame in each tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Time stamp format"
    uint8_t timestampFormat;

    //"Tempo data"
    uint8_t *tempoData;

} SYTCFrame;