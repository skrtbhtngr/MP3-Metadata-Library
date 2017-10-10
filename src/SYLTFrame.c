/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "SYLTFrame.h"

#define FRAME_SYLT_LANG_LEN_v2 3

char *syltFrameTimestampFormatType[] = {

        "",
        "Absolute time, 32 bit sized, using MPEG frames as unit",
        "Absolute time, 32 bit sized, using milliseconds as unit"
};

char *syltContentType[] = {

        "is other",
        "is lyrics",
        "is text transcription",
        "is movement/part name (e.g. \"Adagio\")",
        "is events (e.g. \"Don Quijote enters the stage\")",
        "is chord (e.g. \"Bb F Fsus\")",
        "is trivia/'pop up' information"
};