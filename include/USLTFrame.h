/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_USLT_LANG_LEN_v2 3

typedef struct USLTFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    Encoding encoding;

    //"Language"
    uint8_t  language[FRAME_USLT_LANG_LEN_v2];

    //"Content descriptor"
    char     *desc;
    wchar_t  *wdesc;

    //"Lyrics/text"
    char     *text;
    wchar_t  wtext;

    //There may be more than one 'Unsynchronised lyrics/text transcription'
    //frame in each tag, but only one with the same language
    //and content descriptor.
    struct USLTFrame *next;

} USLTFrame;
