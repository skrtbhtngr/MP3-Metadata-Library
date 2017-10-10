/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct WXXXFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    Encoding encoding;

    //"Description"
    char     *desc;
    wchar_t  *wdesc;

    //"URL"
    char     *url;

    //There may be more than one "WXXX" frame in each tag,
    //but only one with the same description.
    struct WXXXFrame   *next;

} WXXXFrame;

WXXXFrame *parseWXXXFrame(Frame *newFrame);