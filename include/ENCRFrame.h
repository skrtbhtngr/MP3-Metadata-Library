/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct ENCRFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;
    
    //"Owner identifier"
    char    *ownerId;

    //"Method symbol"
    uint8_t encSymbol;

    //"Encryption data"
    uint8_t *encData;

    //There may be several "ENCR" frames in a tag,
    //but only one containing the same symbol
    //and only one containing the same owner identifier.
    struct ENCRFrame *next;

} ENCRFrame;
