/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>

#include "Frame.h"

#define HEADER_FID_v2       3
#define HEADER_VER_v2       2
#define HEADER_FLAGS_v2     1
#define HEADER_SIZE_v2      4

#define EXHEADER_SIZE_v2     4
#define EXHEADER_FLAGS_v2    2
#define EXHEADER_PADSIZE_v2  4

typedef struct
{
    char      fileID[HEADER_FID_v2 + 1];
    uint8_t   version[HEADER_VER_v2];
    uint8_t   flags;
    uint8_t   size[HEADER_SIZE_v2];

    uint32_t  tagSize;
    uint8_t   majorVersion;
    uint8_t   revisionNumber;
    bool      unsynchronisation;
    bool      extended;
    bool      experimental;

} Header;

typedef struct
{
    uint8_t   size[EXHEADER_SIZE_v2];
    uint8_t   flags[EXHEADER_FLAGS_v2];
    uint8_t   paddingSize[EXHEADER_PADSIZE_v2];

    uint8_t   exheaderSize;
    bool      crc;
    
} ExtendedHeader;
