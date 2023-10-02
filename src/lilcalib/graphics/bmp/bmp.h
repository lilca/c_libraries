/**
 * ビットマップファイルクラスのパブリックメソッド
 * @file
 */

#ifndef GRAPHICS_FORMAT_BMP
#define GRAPHICS_FORMAT_BMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <common/typedefs.h>
#include <iobuffer/iobuffer.h>
#include <graphics/format/pixels.h>

/// ビットマップファイルの拡張子
#define BMP_SUFFIX "bmp"
/// ビットマップのファイルヘッダーサイズ
#define BMP_FILEHEADER_SIZE 14
/// ビットマップの情報ヘッダーサイズ
#define BMP_INFOHEADER_SIZE 40
/// ピクセルのデータサイズが24ビット
#define BMP_DEPTH_24BIT 24
/// ピクセルのデータサイズが32ビット
#define BMP_DEPTH_32BIT 32
/// 圧縮種類 (無圧縮)
#define BMP_COMPRESSION_BI_RGB 0
/// 画素が下から上
#define BMP_WAY_BOTTOM2TOP 0
/// 画素が上から下
#define BMP_WAY_TOP2BOTTOM -1

/**
 * ビットマップの構造体
 */
struct _BMP {
    int32 fileSize;
    int32 offset;
    int32 headerSize;
    int16 way;
    int32 width;
    int32 height;
    int16 depth;
    int32 compType;
    int32 dataSize;
    int32 xPPM;
    int32 yPPM;
    int32 pallets;
    int32 impPallet;
    void* imageData;
};
/**
 * ビットマップ型
 */
typedef struct _BMP BMP;

/**
 * ビットマップファイルヘッダの構造体
 */
 struct __attribute__ ((__packed__)) _BMPFileHeader {
    char bfType[2];
    uint32 bfSize;
    uint16 bfReserved1;
    uint16 bfReserved2;
    uint32 bfOffBits;
};
/**
 * ビットマップファイルヘッダ型
 */
typedef struct _BMPFileHeader BMPFileHeader;

/**
 * ビットマップ情報ヘッダ(Windows Bitmap)の構造体
 */
struct __attribute__ ((__packed__)) _BMPInfoHeaderWB {
    uint32 bcSize;
    uint32 bcWidth;
    uint32 bcHeight;
    uint16 bcPlanes;
    uint16 bcBitCount;
    uint32 biCompression;
    uint32 biSizeImage;
    uint32 biXPixPerMeter;
    uint32 biYPixPerMeter;
    uint32 biClrUsed;
    uint32 biClrImportant;
};
/**
 * ビットマップ情報ヘッダ(Windows Bitmap)型
 */
typedef struct _BMPInfoHeaderWB BMPInfoHeaderWB;

/**
 * ビットマップ情報ヘッダ(OS/2)の構造体
 */
struct __attribute__ ((__packed__)) _BMPInfoHeaderOS2 {
    uint32 bcSize;
    uint16 bcWidth;
    uint16 bcHeight;
    uint16 bcPlanes;
    uint16 bcBitCount;
};
/**
 * ビットマップ情報ヘッダ(OS/2)型
 */
typedef struct _BMPInfoHeaderOS2 BMPInfoHeaderOS2;

/**
 * ビットマップのコンストラクタ
 * @param なし
 * @return BMP* ビットマップインスタンス
 */
BMP* BMP_new(void);
/**
 * ビットマップのイニシャライザ
 * @param[in] bmp BMP型のポインタ
 * @return なし
 */
void BMP_init(BMP* bmp);
/**
 * IOBuffer型からビットマップ型を返す
 * @param[in] buf ビットマップファイルのIOBuffer
 * @return BMP* ビットマップ
 */
BMP* BMP_importFromStream(IOBuffer* buf);
/**
 * ビットマップ型をビットマップファイル用のIOBufferに変換
 * @param[in] bmp BMP型のポインタ
 * @return IOBuffer* ビットマップファイルのIOBuffer
 */
IOBuffer* BMP_exportToStream(BMP* bmp);
/**
 * Pixels型からBMP型に変換
 * @param[in] pix Pixels型のポインタ
 * @return BMP* 変換されたBMP型
 */
BMP* BMP_importFromPixels(Pixels* pix);
/**
 * BMP型からPixels型に変換
 * @param[in] bmp BMP型のポインタ
 * @return Pixels* 変換されたPixels型
 */
Pixels* BMP_exportToPixels(BMP* bmp);
/**
 * ビットマップのデストラクタ
 * @param[in] bmp BMP型のポインタ
 * @return なし
 */
void BMP_free(BMP* bmp);
/**
 * ビットマップ内の情報を標準出力
 * @param[in] bmp BMP型のポインタ
 * @return なし
 */
void BMP_print(BMP* bmp);

#endif
