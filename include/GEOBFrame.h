/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct GEOBFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    uint8_t encoding;

    //"MIME type"
    char *mime;

    //"Filename"
    char *filename;
    wchar_t *wfilename;

    //"Content description"
    char *contentDesc;
    wchar_t *wcontentDesc;

    //"Encapsulated object"
    uint8_t *object;

    //There may be more than one "GEOB" frame in each tag,
    //but only one with the same content descriptor.
    struct GEOBFrame *next;

} GEOBFrame;
