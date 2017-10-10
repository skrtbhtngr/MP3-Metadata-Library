/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Header.h"
#include "FrameSet.h"

typedef struct
{
    char *filename;

    //ID3v2.3 tag header (10 bytes)
    Header         header;

    //Extended Header
    ExtendedHeader extendedHeader; 

    //For initial linked list of frames
    FrameSet       frameSet;

} ID3v2Tag;

ID3v2Tag *readID3v2Tag(const char * filename);

void printAllTags(ID3v2Tag *tag);