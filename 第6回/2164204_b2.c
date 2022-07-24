// プログラミング演習第6回 2164204_b2.c

#include <stdio.h>

int word_copy(char *a,char *b);  //プロトタイプ宣言

int main(void)
{
    char in_str[100],out_str[100];  //コピー元の配列とコピー先の配列を定義
    
    printf("input: ");     //コピー元の配列の入力
    gets(in_str);

    word_copy(in_str,out_str); //最初の単語をコピーする関数を呼び出す
    
    printf( "output: %s length = %d",out_str,word_copy(in_str,out_str));    //コピー結果の出力
 
    return 0;
}

int word_copy(char *a,char *b)
{
    int i=0,j=0;
    
    do  //最初の空白をスキップ
    {  
        j++;
    }
    while(a[j]==' ');
    
    do  //文字数カウント、a の最初の単語をb にコピーする
    {
        b[i] =  a[i+j];
        i++;
    }
    while(a[i+j] != ' ');
    
    b[i]='\0';  //コピー先の文字列の最後を'\0'にする
    
    return i;//コピーした文字数を戻り値として返す
}
