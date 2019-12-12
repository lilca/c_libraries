/* エスケープコード */
#define ESC "\x1b["

/* 色定義 */
#define ESC_BLACK   0 //黒
#define ESC_RED     1 //赤
#define ESC_GREEN   2 //緑
#define ESC_YELLOW  3 //黄
#define ESC_BLUE    4 //青
#define ESC_MZENDA  5 //赤紫（マゼンタ）
#define ESC_CYAN    6 //水色（シアン）
#define ESC_WHITE   7 //白
#define ESC_STDCLR  9 //標準色

#define clear_screen () (printf("\x1b[2"))
#define clear_cur2end () (printf("\x1b[K"))
#define up_cur (n) (printf("\x1b[%1dA",n))
#define down_cur (n) (printf("\x1b[%1dB",n))
#define right_cur (n) (printf("\x1b[%1dC",n))
#define left_cur (n) (printf("\x1b[%1dD",n))
#define down_first_cur (n) (printf("\x1b[%1dE",n))
#define up_last_cur (n) (printf("\x1b[%1dF",n))
#define mov_col_cur (x) (printf("\x1b[%1dG",x))
#define move_cur (x,y) (printf("\x1b[%1d;%1dH",y,x))
#define invisible_cur () (printf("\x1b[>5h"))
#define visible_cur () (printf("\x1b[>5l"))

[2   //画面クリア
[K	  //カーソル位置から行末までをクリア 
[nA  //カーソルを上にn行移動
[nB  //カーソルを下にn行移動
[nC  //カーソルを右にn桁移動
[nD  //カーソルを左にn桁移動
[r;cH  //カーソルをr行のn桁目に移動
/* 文字強調 */
#define clear_attr () (printf("\x1b[0m"))
#define strong_attr () (printf("\x1b[1m"))
#define underline_attr () (printf("\x1b[4m"))
#define rever_attr () (printf("\x1b[7m"))
#define fcolor_attr (c) (printf("\x1b[3%1dm",c))
#define bcolor_attr (c) (printf("\x1b[4%1dm",c))
[0m	//属性を標準に戻す
[1m	//強調（太字）
[4m	//下線
[7m	//反転
[3m	//文字色（前景色または背景色）を指定
