/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "ID3v2Tag.h"

int main()
{
    ID3v2Tag *tag = readID3v2Tag("/Users/skrtbhtngr/bin/02. Slowdown (Original Mix).mp3");
    printAllTags(tag);
    return 0;
}



/************************************************************************************

 TFrame, WFrame, APICFrame are done
 Need to add ID3v2.4.0 support (02. Slowdown (Original Mix).mp3 is ID3v2.4)
 parse and print functionality for other frame types


 ***********************************************************************************/