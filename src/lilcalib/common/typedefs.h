/**
 * 共用変数＆定数の定義
 * @file
 */

#ifndef LILCALIB_TYPEDEF_H
#define LILCALIB_TYPEDEF_H

/**
 * 真(TRUE)の定数と定義
 */
#define TRUE -1
/**
 * 偽(FALSE)の定数と定義
 */
#define FALSE 0

/**
 * 1バイト(8ビット)の符号付き整数
 */
typedef char                    int8;
/**
 * 2バイト(16ビット)の符号付き整数
 */
typedef short int               int16;
/**
 * 4バイト(32ビット)の符号付き整数
 */
typedef int                     int32;
/**
 * 8バイト(64ビット)の符号付き整数
 */
typedef long long int           int64;
/**
 * 1バイト(8ビット)の符号なし整数
 */
typedef unsigned char           uint8;
/**
 * 2バイト(16ビット)の符号なし整数
 */
typedef unsigned short int      uint16;
/**
 * 4バイト(32ビット)の符号なし整数
 */
typedef unsigned int            uint32;
/**
 * 8バイト(64ビット)の符号なし整数
 */
typedef unsigned long long int  uint64;
/**
 * 4バイト(32ビット)の浮動小数
 */
typedef float                   float32;
/**
 * 8バイト(64ビット)の浮動小数
 */
typedef double                  float64;
/**
 * 16バイト(128ビット)の浮動小数
 */
typedef long double             float128;

#endif