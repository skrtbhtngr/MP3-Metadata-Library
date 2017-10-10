/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct GRIDFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Owner identifier"
    char *ownerId;

    //"Group symbol"
    uint8_t symbol;

    //"Group dependent data"
    uint8_t *data;
    
    //There may be several "GRID" frames in a tag,
    //but only one containing the same symbol,
    //and only one containing the same owner identifier.
    struct GRIDFrame *next;

} GRIDFrame;
