/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "ETCOFrame.h"

char *etcoFrameTimestampFormatType[] = {

        "",
        "Absolute time, 32 bit sized, using MPEG frames as unit",
        "Absolute time, 32 bit sized, using milliseconds as unit"

};

char *timestampTypeToString(uint8_t type)
{
    char *str;
    switch(type)
    {
        case 0: str = "padding (has no meaning)";
            break;
        case 1: str = "end of initial silence";
            break;
        case 2: str = "intro start";
            break;
        case 3: str = "mainpart start";
            break;
        case 4: str = "outro start";
            break;
        case 5: str = "outro end";
            break;
        case 6: str = "verse start";
            break;
        case 7: str = "refrain start";
            break;
        case 8: str = "interlude start";
            break;
        case 9: str = "theme start";
            break;
        case 10: str = "variation start";
            break;
        case 11: str = "key change";
            break;
        case 12: str = "time change";
            break;
        case 13: str = "momentary unwanted noise (Snap, Crackle & Pop)";
            break;
        case 14: str = "sustained noise";
            break;
        case 15: str = "sustained noise end";
            break;
        case 16: str = "intro end";
            break;
        case 17: str = "mainpart end";
            break;
        case 18: str = "verse end";
            break;
        case 19: str = "refrain end";
            break;
        case 20: str = "theme end";
            break;
        case 224:
        case 225:
        case 226:
        case 227:
        case 228:
        case 229:
        case 230:
        case 231:
        case 232:
        case 233:
        case 234:
        case 235:
        case 236:
        case 237:
        case 238:
        case 239: str = "not predefined sync 0-F";
            break;
        case 253: str = "audio end (start of silence)";
            break;
        case 254: str = "audio file ends";
            break;
        case 255: str = "one more byte of events follows (all the following bytes with the value $FF have the same function)";
            break;
        default:str = "reserved for future use";
    }
    return str;
}