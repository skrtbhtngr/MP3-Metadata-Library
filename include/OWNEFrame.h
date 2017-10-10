/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include "Frame.h"

typedef struct
{
    //There may only be one "OWNE" frame in a tag.

    //Inherit the basic properties of every frame.
    Frame    frame;

    //"Text encoding"
    Encoding encoding;

    //"Price payed"
    char *pricePaid;

    //"Date of purch."
    char *purchaseDate;

    //"Seller"
    char *seller;
    wchar_t *wseller;

} OWNEFrame;