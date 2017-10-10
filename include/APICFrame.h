/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_APIC_DESC_LEN_v2 64

typedef struct APICFrame
{

    //Inherit the basic properties of every frame.
    Frame     frame;

    //"Text encoding"
    Encoding  encoding;

    //"MIME type"
    char      *mime;

    //"Picture type"
    uint8_t   type;

    //"Description"
    //Maximum length is 64 characters
    char      *desc;
    wchar_t   *wdesc;

    //"Picture data"
    uint8_t   *picData;
    //Length of picture data
    uint32_t   len;

    //There may be several pictures attached to one file,
    //each in their individual "APIC" frame,
    //but only one with the same content descriptor.
    struct APICFrame *next;

} APICFrame;

APICFrame *parseAPICFrame(Frame *newFrame);

const char *getPicType(APICFrame *apicFrame);