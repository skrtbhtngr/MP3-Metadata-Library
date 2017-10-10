/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct WFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"URL"
    char     *url;

    //There can be many URL link frames
    //in a tag. So, linked list is used.
    struct WFrame   *next;

} WFrame;

WFrame *parseWFrame(Frame *newFrame);