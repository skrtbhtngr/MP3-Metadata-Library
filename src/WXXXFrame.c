/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "WXXXFrame.h"

WXXXFrame *parseWXXXFrame(Frame *newFrame)
{
    //WXXX has:
    //1B - text encoding
    //nB - description (in the given encoding)
    //     terminated by $00 (00)
    //nB - actual URL in (plain) ISO-8859-1
    WXXXFrame *newWXXXFrame = calloc(1, sizeof(WXXXFrame));

    if(newWXXXFrame == NULL)
    {
        perror("Cannot allocate memory to a new WXXXFrame object! [parseWXXXFrame]\n");
        return NULL;
    }

    memcpy(&newWXXXFrame->frame, &newFrame, sizeof(Frame));

    newWXXXFrame->encoding = newFrame->data[0] ? UNICODE: ISO_8859_1;


    if(newWXXXFrame->encoding == ISO_8859_1)
    {
        //ISO-8859-1 encoding
        int len = 0, i;
        while(*(newFrame->data + 1 + len++) != '\0');

        newWXXXFrame->desc = calloc(i, sizeof(char));
        for(i = 0; i < len; i++)
            newWXXXFrame->desc[i] = *(newFrame->data + 1 + i);
        newWXXXFrame->desc[i] = '\0';

        //+1 to skip encoding bit
        //+len to skip description string
        //+2 to skip teminating $00 and reach first
        //character of URL
        newWXXXFrame->url = (char *)newFrame->data + 1 + len + 2;
    }
    else
    {
        //Unicode
        wchar_t *tmp = wcsdup(mbtowchar((char *)newFrame->data + 3, newFrame->frameSize));
        int i, len=0;
        while(*(tmp + len++) != L'\0');

        newWXXXFrame->wdesc = calloc(len + 1, sizeof(wchar_t));

        for(i = 0; i < len; i++)
            newWXXXFrame->wdesc[i] = tmp[i];
        newWXXXFrame->wdesc[i] = L'\0';

        for(i = 1; ; i++)
            if((newFrame->data[i-1] == 0) && (newFrame->data[i] == 0))
                break;

        newWXXXFrame->url = (char *)newFrame->data + i + 1;
    }
    return newWXXXFrame;
}
