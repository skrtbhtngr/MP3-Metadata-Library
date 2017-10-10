/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>

#ifndef FRAME_H
#define FRAME_H

#define FRAME_FID_v2        4
#define FRAME_SIZE_v2       4
#define FRAME_FLAGS_v2      2

typedef enum
{
    ISO_8859_1,
    UNICODE

} Encoding;

typedef struct
{
    char 	  frameId[FRAME_FID_v2 + 1];
    uint8_t   size[FRAME_SIZE_v2];
    uint8_t   flags[FRAME_FLAGS_v2];

    uint32_t  frameSize;

    uint8_t   *data;

    bool      tagAlterPres;
    bool      fileAlterPres;
    bool      readOnly;
    bool      compression;
    bool      encryption;
    bool      grouping;

} Frame;

wchar_t *mbtowchar(uint8_t *str, uint32_t len);

char *frameIdToString(const char *id);

char *dec2bin(uint8_t num);

#endif
