/**
 * コンソールウィンドウのフレームのインクルード
 * @file
 */

#ifndef CW_FRAME_H
#define CW_FRAME_H

/**
 * コンソールウィンドウのフレームの構造体
*/
typedef struct {
    uint8 top;
    uint8 left;
    uint8 bottom;
    uint8 right;
    uint8 topLeft;
    uint8 bottomLeft;
    uint8 bottomRight;
    uint8 topRight;
} CWFrame;


#endif
