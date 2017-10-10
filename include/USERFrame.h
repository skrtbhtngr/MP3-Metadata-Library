/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_USER_LANG_LEN_v2 3

typedef struct
{
    //There may only be one "USER" frame in a tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    Encoding encoding;

    //"Language"
    uint8_t  language[FRAME_USER_LANG_LEN_v2];

    //"The actual text"
    char     *text;
    wchar_t  *wtext;

} USERFrame;
