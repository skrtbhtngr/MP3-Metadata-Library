/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct TFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    Encoding encoding;

    //"Information"
    char     *info;
    wchar_t  *winfo;

    //There can be many text information frames
    //in a tag. So, linked list is used.
    struct TFrame   *next;

} TFrame;

TFrame *parseTFrame(Frame *newFrame);