/**
 * 入出力用バッファクラスのパブリックメソッド
 * @file
 */

#ifndef IOBUFFER_H
#define IOBUFFER_H

#include <stdio.h>
#include <stdlib.h>

#include <common/typedefs.h>

/**
 * I/Oバッファの構造体
 */
struct _IOBuffer {
    /// データを格納する先頭アドレス
    void* data;
    /// 格納されるデータのサイズ
    int64 size;
};
/**
 * I/Oバッファの変数型
 */
typedef struct _IOBuffer IOBuffer;

/**
 * IOBufferのコンストラクタ
 * @param なし
 * @return IOBuffer* サイズがゼロのIOBufferを返す
 * @details 特になし
 */
IOBuffer* IOBuffer_new(void);
/**
 * ファイルの内容をIOBuffer型に格納する
 * @param[in] path 読み込むファイルのパス
 * @return IOBuffer* IOBufferポインタ
 * @details 特になし
 */
IOBuffer* IOBuffer_readFile(char* path);
/**
 * IOBuffer型の内容のファイルに書き込む
 * @param[in] path 書き込むファイルのパス
 * @param[in] buf 書き込むIOBuffer
 * @return int 書き込みの結果
 * @details 特になし
 */
int IOBuffer_writeFile(char* path, IOBuffer* buf);
/**
 * IOBufferのデストラクタ
 * @param[in] buf 解放するIOBuffer
 * @return なし
 * @details 特になし
 */
void IOBuffer_free(IOBuffer* buf);

#endif