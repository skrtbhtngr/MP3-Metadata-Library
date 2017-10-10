/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

//This function converts a multi-byte Unicode character
//string into wide character type for Unicode support.
//Little-endian assumed.
wchar_t *mbtowchar(uint8_t *str, uint32_t len)
{
    uint8_t i = 0, endian = 1;
    wchar_t *uni = calloc(len/2 + 1, sizeof(wchar_t));

    uint8_t *ptr = calloc(len + 1, sizeof(uint8_t));
    for(i = 0; i < len + 1; i++)
        ptr[i] = str[i + 2];

    if(*str == 0xFF && *(str + 1) == 0xFE)
        endian = 0;
    i = 0;
    while(*ptr != 0 || *(ptr + 1) != 0)
    {
        if(endian)      //Little-endian
            uni[i++] = ((wchar_t)(*ptr) << 8) + (wchar_t)(*(ptr + 1));
        else            //Big-endian
            uni[i++] = (wchar_t)(*ptr) + ((wchar_t)(*(ptr + 1)) << 8);
        ptr += 2;
    }
    uni[i] = L'\0';
    return uni;
}

char *frameIdToString(const char *id)
{
    if(!strcmp(id,"AENC"))       return "Audio encryption";
    else if(!strcmp(id,"APIC"))  return "Attached picture";
    else if(!strcmp(id,"COMM"))  return "Comments";
    else if(!strcmp(id,"COMR"))  return "Commercial frame";
    else if(!strcmp(id,"ENCR"))  return "Encryption method registration";
    else if(!strcmp(id,"EQUA"))  return "Equalization";
    else if(!strcmp(id,"ETCO"))  return "Event timing codes";
    else if(!strcmp(id,"GEOB"))  return "General encapsulated object";
    else if(!strcmp(id,"GRID"))  return "Group identification registration";
    else if(!strcmp(id,"IPLS"))  return "Involved people list";
    else if(!strcmp(id,"LINK"))  return "Linked information";
    else if(!strcmp(id,"MCDI"))  return "Music CD identifier";
    else if(!strcmp(id,"MLLT"))  return "MPEG location lookup table";
    else if(!strcmp(id,"OWNE"))  return "Ownership frame";
    else if(!strcmp(id,"PRIV"))  return "Private frame";
    else if(!strcmp(id,"PCNT"))  return "Play counter";
    else if(!strcmp(id,"POPM"))  return "Popularimeter";
    else if(!strcmp(id,"POSS"))  return "Position synchronisation frame";
    else if(!strcmp(id,"RBUF"))  return "Recommended buffer size";
    else if(!strcmp(id,"RVAD"))  return "Relative volume adjustment";
    else if(!strcmp(id,"RVRB"))  return "Reverb";
    else if(!strcmp(id,"SYLT"))  return "Synchronized lyric/text";
    else if(!strcmp(id,"SYTC"))  return "Synchronized tempo codes";
    else if(!strcmp(id,"TALB"))  return "Album/Movie/Show title";
    else if(!strcmp(id,"TBPM"))  return "BPM (beats per minute)";
    else if(!strcmp(id,"TCOM"))  return "Composer";
    else if(!strcmp(id,"TCON"))  return "Content type";
    else if(!strcmp(id,"TCOP"))  return "Copyright message";
    else if(!strcmp(id,"TDAT"))  return "Date";
    else if(!strcmp(id,"TDLY"))  return "Playlist delay";
    else if(!strcmp(id,"TENC"))  return "Encoded by";
    else if(!strcmp(id,"TEXT"))  return "Lyricist/Text writer";
    else if(!strcmp(id,"TFLT"))  return "File type";
    else if(!strcmp(id,"TIME"))  return "Time";
    else if(!strcmp(id,"TIT1"))  return "Content group description";
    else if(!strcmp(id,"TIT2"))  return "Title/songname/content description";
    else if(!strcmp(id,"TIT3"))  return "Subtitle/Description refinement";
    else if(!strcmp(id,"TKEY"))  return "Initial key";
    else if(!strcmp(id,"TLAN"))  return "Language(s)";
    else if(!strcmp(id,"TLEN"))  return "Length";
    else if(!strcmp(id,"TMED"))  return "Media type";
    else if(!strcmp(id,"TOAL"))  return "Original album/movie/show title";
    else if(!strcmp(id,"TOFN"))  return "Original filename";
    else if(!strcmp(id,"TOLY"))  return "Original lyricist(s)/text writer(s)";
    else if(!strcmp(id,"TOPE"))  return "Original artist(s)/performer(s)";
    else if(!strcmp(id,"TORY"))  return "Original release year";
    else if(!strcmp(id,"TOWN"))  return "File owner/licensee";
    else if(!strcmp(id,"TPE1"))  return "Lead performer(s)/Soloist(s)";
    else if(!strcmp(id,"TPE2"))  return "Band/orchestra/accompaniment";
    else if(!strcmp(id,"TPE3"))  return "Conductor/performer refinement";
    else if(!strcmp(id,"TPE4"))  return "Interpreted, remixed, or otherwise modified by";
    else if(!strcmp(id,"TPOS"))  return "Part of a set";
    else if(!strcmp(id,"TPUB"))  return "Publisher";
    else if(!strcmp(id,"TRCK"))  return "Track number/Position in set";
    else if(!strcmp(id,"TRDA"))  return "Recording dates";
    else if(!strcmp(id,"TRSN"))  return "Internet radio station name";
    else if(!strcmp(id,"TRSO"))  return "Internet radio station owner";
    else if(!strcmp(id,"TSIZ"))  return "Size";
    else if(!strcmp(id,"TSRC"))  return "ISRC (international standard recording code)";
    else if(!strcmp(id,"TSSE"))  return "Software/Hardware and settings used for encoding";
    else if(!strcmp(id,"TYER"))  return "Year";
    else if(!strcmp(id,"TXXX"))  return "User defined text information frame";
    else if(!strcmp(id,"UFID"))  return "Unique file identifier";
    else if(!strcmp(id,"USER"))  return "Terms of use";
    else if(!strcmp(id,"USLT"))  return "Unsychronized lyric/text transcription";
    else if(!strcmp(id,"WCOM"))  return "Commercial information";
    else if(!strcmp(id,"WCOP"))  return "Copyright/Legal information";
    else if(!strcmp(id,"WOAF"))  return "Official audio file webpage";
    else if(!strcmp(id,"WOAR"))  return "Official artist/performer webpage";
    else if(!strcmp(id,"WOAS"))  return "Official audio source webpage";
    else if(!strcmp(id,"WORS"))  return "Official internet radio station homepage";
    else if(!strcmp(id,"WPAY"))  return "Payment";
    else if(!strcmp(id,"WPUB"))  return "Publishers official webpage";
    else if(!strcmp(id,"WXXX"))  return "User defined URL link frame";
    else                         return "";
}

char *dec2bin(uint8_t num)
{
    char *bin = calloc(9, sizeof(char));
    memset(bin, '0', 9);
    bin[8] = '\0';
    int i = 7;
    while(num)
    {
        bin[i--] = num % 2 +'0';
        num /= 2;
    }
    return bin;
}