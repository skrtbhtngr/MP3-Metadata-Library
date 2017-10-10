/***************************************************************************
    copyright            : (C) 2017 by Sukrit Bhatnagar
    email                : skrtbhtngr@gmail.com
 ***************************************************************************/

#include <ID3v2Tag.h>

void parseFrame(ID3v2Tag *tag, Frame *newFrame)
{
    if(newFrame->frameId[0] == 'T' && (newFrame->frameId[1] != 'X' && newFrame->frameId[2] != 'X' && newFrame->frameId[3] != 'X'))
    {
        TFrame *ptr = tag->frameSet.tFrame;
        if(ptr != NULL)
            while(ptr->next != NULL)
                ptr = ptr->next;

        TFrame *tFrame = parseTFrame(newFrame);

        if(tag->frameSet.tFrame == NULL)
            tag->frameSet.tFrame = tFrame;
        else
            ptr->next = tFrame;
    }
    else if(newFrame->frameId[0] == 'W' && (newFrame->frameId[1] != 'X' && newFrame->frameId[2] != 'X' && newFrame->frameId[3] != 'X'))
    {
        WFrame *ptr = tag->frameSet.wFrame;
        if(ptr != NULL)
            while(ptr->next != NULL)
                ptr = ptr->next;

        WFrame *wFrame = parseWFrame(newFrame);

        if(tag->frameSet.wFrame == NULL)
            tag->frameSet.wFrame = wFrame;
        else
            ptr->next = wFrame;
    }
    else if(newFrame->frameId[0]=='W' && newFrame->frameId[1]=='X' && newFrame->frameId[2]=='X' && newFrame->frameId[3]=='X')
    {
        WXXXFrame *ptr = tag->frameSet.wxxxFrame;
        if(ptr != NULL)
            while(ptr->next != NULL)
                ptr = ptr->next;

        WXXXFrame *wxxxFrame = parseWXXXFrame(newFrame);

        if(tag->frameSet.wxxxFrame == NULL)
            tag->frameSet.wxxxFrame = wxxxFrame;
        else
            ptr->next = wxxxFrame;
    }
    else if(newFrame->frameId[0]=='A' && newFrame->frameId[1]=='P' && newFrame->frameId[2]=='I' && newFrame->frameId[3]=='C')
    {
        APICFrame *ptr = tag->frameSet.apicFrame;
        if(ptr != NULL)
            while(ptr->next != NULL)
                ptr = ptr->next;

        APICFrame *apicFrame = parseAPICFrame(newFrame);

        if(tag->frameSet.apicFrame == NULL)
            tag->frameSet.apicFrame = apicFrame;
        else
            ptr->next = apicFrame;
    }
}

//This function reads the ID3v2.3 Tag from the audio file
//and parses the header, extended header and frame.
ID3v2Tag *readID3v2Tag(const char * filename)
{
    //Create a new ID3v2Tag object
    ID3v2Tag *tag = calloc(1, sizeof(ID3v2Tag));

    //Copy the filename into object for later purposes
    tag->filename = strdup(filename);

    //Read the audio file in binary stream (not character stream)
    FILE *file = fopen(filename,"rb");

    //Check if the file actually exists on the system
    //or if it is readable.
    if(file == NULL)
        perror("File doesn't really exist!!\n");

    // --------------------------------------------------------------------------------
    // -------------------- Parse the header ------------------------------------------
    // --------------------------------------------------------------------------------

    //Read the tags byte-by-byte into the fields
    fread(tag->header.fileID, sizeof(char), HEADER_FID_v2, file);
    tag->header.fileID[HEADER_FID_v2]='\0';

    fread(tag->header.version, sizeof(uint8_t), HEADER_VER_v2, file);

    fread(&tag->header.flags, sizeof(uint8_t), HEADER_FLAGS_v2, file);

    fread(tag->header.size, sizeof(uint8_t), HEADER_SIZE_v2, file);

    //Set the version of ID3 Tag (v2.x.x)
    tag->header.majorVersion = tag->header.version[0];
    tag->header.revisionNumber = tag->header.version[1];

    //Default values
    tag->header.unsynchronisation=false;
    tag->header.extended=false;
    tag->header.experimental=false;

    /* 
     * Bit 7 in the 'ID3v2 flags' indicates whether or not unsynchronisation is used.
     */
    if ((tag->header.flags) >> 7 & 1)
        tag->header.unsynchronisation = true;

    /* 
     * The second bit (bit 6) indicates whether or not the header is followed by an extended header.
     */
    if ((tag->header.flags) >> 6 & 1)
    {
        //Read the ID3v2.3 extended header.

        tag->header.extended = true;

        /* 
         * The 'Extended header size', currently 6 or 10 bytes, excludes itself.
         */
        fread(tag->extendedHeader.size, sizeof(uint8_t), EXHEADER_SIZE_v2, file);

        fread(tag->extendedHeader.flags, sizeof(uint8_t), EXHEADER_FLAGS_v2, file);
        
        /* 
         * The 'Size of padding' is simply the total tag size excluding the frames and the headers,
         * in other words the padding.
         */
        fread(tag->extendedHeader.paddingSize, sizeof(uint8_t), EXHEADER_PADSIZE_v2, file);

        //Calculate the actual size of extended header from 4B "Extended header size" field
        tag->extendedHeader.exheaderSize = (uint8_t)(((uint32_t)tag->extendedHeader.size[0] << 21)\
                + ((uint32_t)tag->extendedHeader.size[1] << 14)\
                + ((uint32_t)tag->extendedHeader.size[2] << 7)\
                + (uint32_t)tag->extendedHeader.size[3]);

        /*
         * If this flag is set four bytes of CRC-32 data is appended to the extended header.
         */
        if ((tag->extendedHeader.flags[0]) >> 7 & 1)
            tag->extendedHeader.crc = true;
    }

    /* 
     * The third bit (bit 5) should be used as an 'experimental indicator'.
     * This flag should always be set when the tag is in an experimental stage. 
     */
    if ((tag->header.flags) >> 5 & 1)
        tag->header.experimental = true;

    //If synchronisation is used, 8th bit will also be set
    uint8_t shift = 8;
    if(tag->header.unsynchronisation)
        shift=7;

    /*
     * The ID3v2 tag size is the size of the complete tag after unsychronisation, including padding,
     * excluding the header but not excluding the extended header (total tag size - 10).
     */
    tag->header.tagSize = ((uint32_t)tag->header.size[0] << shift*3)\
            + ((uint32_t)tag->header.size[1] << shift*2)\
            + ((uint32_t)tag->header.size[2] << shift)\
            + tag->header.size[3]\
            + 10;

    // --------------------------------------------------------------------------------
    // -------------------- Read frames' data -----------------------------------------
    // --------------------------------------------------------------------------------


    //Read the first frame in the tag. At least one frame will be present.
    //Read all the subsequent frames, if available and append into the linked list.
    do
    {
        Frame *newFrame = calloc(1, sizeof(Frame));

        fread(newFrame->frameId, sizeof(char), FRAME_FID_v2, file);
        newFrame->frameId[FRAME_FID_v2]='\0';

        if( strlen(frameIdToString(newFrame->frameId)) == 0 )
            break;

        fread(newFrame->size, sizeof(uint8_t), FRAME_SIZE_v2, file);

        /*
         * The frame ID is followed by a size descriptor,
         * making a total header size of ten bytes in every frame.
         * The size is calculated as frame size
         * excluding frame header (frame size - 10).
         */
        fread(newFrame->flags, sizeof(uint8_t), FRAME_FLAGS_v2, file);

        newFrame->frameSize = ((uint32_t)newFrame->size[0] << shift * 3)\
                + ((uint32_t)newFrame->size[1] << shift * 2)\
                + ((uint32_t)newFrame->size[2] << shift)\
                + newFrame->size[3];

        /*
         * This flag tells the software what to do with this frame
         * if it is unknown and the tag is altered in any way.
         * This applies to all kinds of alterations,
         * including adding more padding and reordering the frames.
         */
        if ((newFrame->flags[0]) >> 7 & 1)
            newFrame->tagAlterPres = true;

        /*
         * This flag tells the software what to do with this frame
         * if it is unknown and the file, excluding the tag, is altered.
         * This does not apply when the audio is completely
         * replaced with other audio data.
         */
        if ((newFrame->flags[0]) >> 6 & 1)
            newFrame->fileAlterPres = true;

        /*
         * This flag, if set, tells the software that the
         * contents of this frame is intended to be read only.
         * Changing the contents might break something, e.g. a signature.
         * If the contents are changed, without knowledge in
         * why the frame was flagged read only and without taking
         * the proper means to compensate, e.g. recalculating the signature,
         * the bit should be cleared.
         */
        if ((newFrame->flags[0]) >> 5 & 1)
            newFrame->readOnly = true;

        /*
         * This flag indicates whether or not the frame is compressed. 
         */
        if ((newFrame->flags[1]) >> 7 & 1)
            newFrame->compression = true;

        /*
         * This flag indicates wether or not the frame is enrypted.
         * If set one byte indicating with which method it was
         * encrypted will be appended to the frame header.
         */
        if ((newFrame->flags[1]) >> 6 & 1)
            newFrame->encryption = true;

        /*
         * This flag indicates whether or not this frame belongs
         * in a group with other frames. If set a group identifier
         * byte is added to the frame header. Every frame with the
         * same group identifier belongs to the same group. 
         */
        if ((newFrame->flags[1]) >> 5 & 1)
            newFrame->grouping = true;

        newFrame->data = calloc(newFrame->frameSize, sizeof(uint8_t));

        if(newFrame->data == NULL)
            printf("Frame data is NULL! [readID3v2Tag]\n");

        fread(newFrame->data, sizeof(uint8_t), newFrame->frameSize, file);

        parseFrame(tag, newFrame);

        free(newFrame->data);

    } while(1);

    fclose(file);

    return tag;
}

void printCommonFrameInfo(Frame frame)
{
    printf("Frame ID: %s\n", frame.frameId);
    printf("[Interpreted Frame ID: %s]\n", frameIdToString(frame.frameId));
    printf("Frame size: %s %s %s %s\n",
           dec2bin(frame.size[0]),
           dec2bin(frame.size[1]),
           dec2bin(frame.size[2]),
           dec2bin(frame.size[3]));
    printf("[Interpreted Frame size: %d B]\n", frame.frameSize);
    printf("Frame flags: %s %s\n", dec2bin(frame.flags[0]), dec2bin(frame.flags[1]));
    printf("[Flags set: ");
    if(frame.compression) printf("Compression ");
    if(frame.encryption) printf("Encryption ");
    if(frame.fileAlterPres) printf("File alter preservation ");
    if(frame.grouping) printf("Grouping identity ");
    if(frame.readOnly) printf("Read only ");
    if(frame.tagAlterPres) printf("Tag alter preservation ");
    printf("]\n");
}

void printAllTags(ID3v2Tag *tag)
{
    setlocale(LC_ALL, "");

    printf("File: %s\n", tag->filename);
    printf("--------------------------------------------------------------------------------\n");

    printf("Header Information:\n");
    printf("ID3v2/file identifier: %s\n", tag->header.fileID);
    printf("ID3v2 version: %"PRIu8".%"PRIu8"\n", tag->header.version[0], tag->header.version[1]);
    printf("ID3v2 flags: %s\n", dec2bin(tag->header.flags));
    printf("ID3v2 size: %s %s %s %s\n",
           dec2bin(tag->header.size[0]),
           dec2bin(tag->header.size[1]),
           dec2bin(tag->header.size[2]),
           dec2bin(tag->header.size[3]));
    printf("[Interpreted ID3v2 header size: %"PRIu32" B (%"PRIu32" KB)]\n", tag->header.tagSize, tag->header.tagSize / 1024);
    if(tag->header.extended)
    {
        printf("Extended header size: %s %s %s %s\n",
               dec2bin(tag->extendedHeader.size[0]),
               dec2bin(tag->extendedHeader.size[1]),
               dec2bin(tag->extendedHeader.size[2]),
               dec2bin(tag->extendedHeader.size[3]));

        printf("Extended flags: %s %s\n",
               dec2bin(tag->extendedHeader.flags[0]),
               dec2bin(tag->extendedHeader.flags[1]));

        printf("Size of padding: %s %s %s %s\n",
               dec2bin(tag->extendedHeader.paddingSize[0]),
               dec2bin(tag->extendedHeader.paddingSize[1]),
               dec2bin(tag->extendedHeader.paddingSize[2]),
               dec2bin(tag->extendedHeader.paddingSize[3]));
    }

    if(tag->frameSet.tFrame != NULL)
    {
        for(TFrame *tFrame = tag->frameSet.tFrame; tFrame != NULL; tFrame = tFrame->next)
        {
            printf("--------------------------------------------------------------------------------\n");
            printCommonFrameInfo(tFrame->frame);

            printf("Frame encoding: %s\n", tFrame->encoding ? "UNICODE": "ISO_8859_1");
            if(tFrame->encoding == ISO_8859_1)
                printf("Frame data: %s\n", tFrame->info);
            else
                printf("Frame data: %ls\n", tFrame->winfo);
            printf("--------------------------------------------------------------------------------\n");
        }
    }
    if(tag->frameSet.wFrame != NULL)
    {
        for(WFrame *wFrame = tag->frameSet.wFrame; wFrame != NULL; wFrame = wFrame->next)
        {
            printf("--------------------------------------------------------------------------------\n");
            printCommonFrameInfo(wFrame->frame);

            printf("Frame data: %s\n", wFrame->url);
            printf("--------------------------------------------------------------------------------\n");
        }
    }
    if(tag->frameSet.apicFrame != NULL)
    {
        for(APICFrame *apicFrame = tag->frameSet.apicFrame; apicFrame != NULL; apicFrame = apicFrame->next)
        {
            printf("--------------------------------------------------------------------------------\n");
            printCommonFrameInfo(apicFrame->frame);

            printf("Frame encoding: %s\n", apicFrame->encoding ? "UNICODE": "ISO_8859_1");

            printf("MIME Type: %s\n", apicFrame->mime);
            printf("Picture Type: %s\n", getPicType(apicFrame));

            if(apicFrame->encoding == ISO_8859_1)
                printf("Frame description: %s\n", apicFrame->desc);
            else
                printf("Frame description: %ls\n", apicFrame->wdesc);

            //FILE *pic = fopen(strcat(tag->filename, ".jpg"), "wb");
            //fwrite(apicFrame->picData, sizeof(char), apicFrame->len, pic);
            //fclose(pic);
            printf("--------------------------------------------------------------------------------\n");
        }
    }
}