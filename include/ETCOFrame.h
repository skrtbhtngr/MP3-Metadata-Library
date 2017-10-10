/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //There may only be one "ETCO" frame in each tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Time stamp format"
    //$01 Absolute time, 32 bit sized, using MPEG frames as unit
    //$02 Absolute time, 32 bit sized, using milliseconds as unit
    uint8_t timestampFormat;

    //"Type of event"
    uint8_t eventType;

} ETCOFrame;

char *timestampTypeToString(uint8_t type);