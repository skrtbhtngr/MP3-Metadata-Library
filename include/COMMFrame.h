/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_COMM_LANGUAGE_LEN_v2 3

typedef struct COMMFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    uint8_t  encoding;

    //"Language"
    uint8_t  language[FRAME_COMM_LANGUAGE_LEN_v2];

    //"Short content description"
    char     *shortDesc;
    wchar_t  *wshortDesc;

    //"The actual text"
    char     *text;
    wchar_t  *wtext;

    //There may be more than one comment frame in each tag,
    //but only one with the same language and content descriptor.
    struct COMMFrame *next;

} COMMFrame;
