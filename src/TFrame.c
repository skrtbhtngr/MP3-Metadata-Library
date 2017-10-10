/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include <Frame.h>
#include "TFrame.h"

TFrame *parseTFrame(Frame *newFrame)
{
    TFrame *newTFrame = calloc(1, sizeof(TFrame));
    if(newTFrame == NULL)
        perror("Cannot allocate memory to a new TFrame object! [parseTFrame]\n");

    newTFrame->next = NULL;

    memcpy(&newTFrame->frame, newFrame, sizeof(Frame));

    newTFrame->encoding = newFrame->data[0] ? UNICODE: ISO_8859_1;

    if(newTFrame->encoding == ISO_8859_1)
        newTFrame->info = strdup((char *)newFrame->data + 1);
    else
        newTFrame->winfo = wcsdup(mbtowchar(newFrame->data + 1, newFrame->frameSize - 3));
    return newTFrame;
}
