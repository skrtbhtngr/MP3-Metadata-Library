/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //Only one IPLS frame in each tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    bool encoding;

    //"People list strings"
    //There can be several strings.
    char **list;
    wchar_t **wlist;

} IPLSFrame;