/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct TXXXFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    Encoding encoding;

    //"Description"
    char     *desc;
    wchar_t  *wdesc;

    //"Value"
    char     *value;
    wchar_t  *wvalue;

    //There may be more than one "WXXX" frame in each tag,
    //but only one with the same description.
    struct TXXXFrame   *next;

} TXXXFrame;
