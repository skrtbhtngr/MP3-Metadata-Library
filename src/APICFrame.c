/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "APICFrame.h"

char *apicFrameType[] = {

        "Other",
        "32x32 pixels 'file icon' (PNG only)",
        "Other file icon",
        "Cover (front)",
        "Cover (back)",
        "Leaflet page",
        "Media (e.g. lable side of CD)",
        "Lead artist/lead performer/soloist",
        "Artist/performer",
        "Conductor",
        "Band/Orchestra",
        "Composer",
        "Lyricist/text writer",
        "Recording Location",
        "During recording",
        "During performance",
        "Movie/video screen capture",
        "Illustration",
        "Band/artist logotype",
        "Publisher/Studio logotype"
};

APICFrame *parseAPICFrame(Frame *newFrame)
{
    APICFrame *newAPICFrame = calloc(1, sizeof(APICFrame));
    if(newAPICFrame == NULL)
    {
        perror("Cannot allocate memory to a new APICFrame object! [parseAPICFrame]\n");
        return NULL;
    }

    newAPICFrame->next = NULL;

    memcpy(&newAPICFrame->frame, newFrame, sizeof(Frame));

    uint32_t i, k, len = 0;

    newAPICFrame->encoding = newFrame->data[0] ? UNICODE: ISO_8859_1;

    //MIME type string does not depend on the encoding.
    //It is in (plain) ISO-8859-1.
    //It cannot be more than 64 characters
    newAPICFrame->mime = calloc(64, sizeof(char));
    for(i = 1, k = 0;; i++)
    {
        newAPICFrame->mime[k++] = newFrame->data[i];
        if(newFrame->data[i] == '\0')
            break;
    }
    newAPICFrame->type = newFrame->data[++i];
    i++;

    if(newAPICFrame->encoding == ISO_8859_1)
    {
        newAPICFrame->desc = calloc(FRAME_APIC_DESC_LEN_v2 + 1, sizeof(char));
        k = 0;
        for(;; i++)
        {
            newAPICFrame->desc[k++] = newFrame->data[i];
            if(newFrame->data[i] == '\0')
                break;
        }
        i++;
    }
    else
    {
        newAPICFrame->wdesc = mbtowchar((char *)newFrame->data + i, FRAME_APIC_DESC_LEN_v2);
        //Add 2 for the NULL delimiter for Unicode
        i += 2 + wcslen(newAPICFrame->wdesc) * 2;
    }

    newAPICFrame->len = newFrame->frameSize - i;
    newAPICFrame->picData = calloc(newAPICFrame->len + 1, sizeof(uint8_t));
    memcpy(newAPICFrame->picData, newFrame->data + i, newAPICFrame->len);

    return newAPICFrame;
}

const char *getPicType(APICFrame *apicFrame)
{
    return apicFrameType[apicFrame->type];
}