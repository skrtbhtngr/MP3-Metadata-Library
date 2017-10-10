/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "WFrame.h"

WFrame *parseWFrame(Frame *newFrame)
{
    WFrame *newWFrame = calloc(1, sizeof(WFrame));

    if(newWFrame == NULL)
        perror("Cannot allocate memory to a new WFrame object! [parseWFrame]\n");

    newWFrame->next = NULL;

    memcpy(&newWFrame->frame, newFrame, sizeof(Frame));

    //ISO-8859-1 encoding only is allowed for URLs!
    newWFrame->url = strdup((char *)newFrame->data + 1);

    return newWFrame;
}
