/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

#define FRAME_COMR_VALID_LEN_v2 8

typedef struct
{
    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    Encoding encoding;

    //"Price string"
    //(three character currency code, encoded according to ISO-4217)
    char     *price;

    //"Valid until"
    //YYYYMMDD
    char     validUntil[FRAME_COMR_VALID_LEN_v2 + 1];

    //"Contact URL"
    char     *url;

    //"Received as"
    uint8_t  *receivedAs;

    //"Name of seller"
    char     *seller;
    wchar_t  *wseller;

    //"Description"
    char     *desc;
    wchar_t  *wdesc;

    //"Picture MIME type"
    char     *mime;

    //"Seller logo"
    uint8_t  *logo;

} COMRFrame;