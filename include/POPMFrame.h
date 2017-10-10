/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct POPMFrame
{
    //Inherit the basic properties of every frame.
    Frame   frame;

    //"Email to user"
    char    *email;

    //"Rating"
    //The rating is 1-255 where 1 is worst and 255 is best. 0 is unknown.
    uint8_t rating;

    //"Counter"
    uint8_t *counter;

    //There may be more than one "POPM" frame in each tag,
    //but only one with the same email address.
    struct POPMFrame *next;

} POPMFrame;
