/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_SYLT_LANG_LEN_v2 3

typedef struct SYLTFrame
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    //$00     ISO-8859-1 character set is used => $00 is sync identifier.
    //$01     Unicode character set is used => $00 00 is sync identifier.
    Encoding encoding;

    //"Language"
    uint8_t language[FRAME_SYLT_LANG_LEN_v2];

    //"Time stamp format"
    uint8_t timestampFormat;

    //"Content type"
    uint8_t contentType;

    //"Content descriptor"
    char *desc;
    wchar_t *wdesc;

    //Each sync has the following structure:
    struct
    {
        //Terminated text to be synced (typically a syllable)
        //and
        //Sync identifier (terminator to above string)    $00 (00)
        char *text;
        wchar_t wtext;

        //"Time stamp"
        //Usually 2 bytes in size.
        uint8_t *timestamp;
    } sync;

    //There may be more than one "SYLT" frame in each tag,
    //but only one with the same language and content descriptor.
    struct SYLTFrame *next;

} SYLTFrame;
