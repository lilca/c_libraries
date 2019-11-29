// MARKER
#define JPEG_SOI 0xd8ff
#define JPEG_APP0 0xe0ff
#define JPEG_DQT 0xdbff
#define JPEG_SOF0 0xc0ff
#define JPEG_DHT 0xc4ff
#define JPEG_SOS 0xdaff
#define JPEG_EOI 0xd9ff

// for APP0 field
#define JPEG_JFIF_ID "JFIF"

int parseSOI(uint8* p){
    if (*((uint16*)p) != JPEG_SOI)
        return FALSE;
    p += 2;
    return TRUE;
}

int parseEOI(uint8* p){
    if (*((uint16*)p) != JPEG_EOI)
        return FALSE;
        p += 2;
    return TRUE;
}

int parseAPP0(uint8* p){
    if (*((uint16*)p) != JPEG_APP0)
        return FALSE;
    p += 2;
    fieldLength = *((uint16*)p);
    p += 2;
    if (strcmp((char*)p, JPEG_JFIF_ID) != 0)
        return FALSE;
    p += 5;
    version = *((uint16*)p);
    p += 2;
    pixelUnit = *p;
    p++;
    widthPixels = *((uint16*)p);
    p += 2;
    heightPixels = *((uint16*)p);
    p += 2;
    thumbWidth = *p++;
    thumbHeight = *p++;
    // Skip thumbnail image
    p += 24 / 3 * thumbWidth * thumbHeight;
    return TRUE;
}

int parseDQT(uint8* p) {
    if (*((uint16*)p) != JPEG_DQT)
        return FALSE;
    p += 2;
    fieldLength = *((uint16*)p);
    p += 2;
    uint8 tmp = *p++;
    dqtAccuracy = tmp >> 4;
    dqtTableID = tmp & 0x0f;
    ptrDQF = p;
    p += (dqtAccuracy + 1) * 8;
    return TRUE;
}

int parseSOF0(uint8* p) {
    if (*((uint16*)p) != JPEG_SOF0)
        return FALSE;
    p += 2;
    fieldLength = *((uint16*)p);
    p += 2;
    sampleAccuracy = *p++;
    imageHeight = *((uint16*)p);
    p += 2;
    imageWidth = *((uint16*)p);;
    p += 2;
    components = *p++;
    // いくつスキップする？
    ptrComponents = p;
    p += fieldLength - 8;
    return TRUE;
}

int parseDHT(uint8* p) {
    if (*((uint16*)p) != JPEG_DHT)
        return FALSE;
    p += 2;
    fieldLength = *((uint16*)p);
    p += 2;
    uint8 tmp = *p++;
    dhtClass = tmp >> 4;
    dqtID = tmp & 0x0f;
    ptrCodeLengthFix = p;
    p += 16;
    ptrCodeLegngthVar = p;
    p += fieldLength - 19;
    return TRUE;
}

int parseSOS(uint8* p) {
    if (*((uint16*)p) != JPEG_SOS)
        return FALSE;
    p += 2;
    fieldLength = *((uint16*)p);
    p += 2;
    components = *p++;
    // Skip
    p += components * 2;
    // Skip
    p += 3;
    return TRUE;
}