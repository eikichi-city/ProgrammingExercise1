// プログラミング演習第6回 2164204_b3.c

#include <stdio.h>

int word_copy(char a[],char b[]);  //プロトタイプ宣言

int main(void)
{
    char in_str[100],out_str[100];  //コピー元の配列とコピー先の配列を定義
    int length;
    
    printf("input: ");     //コピー元の配列の入力
    gets(in_str);

    length = word_copy(in_str,out_str); //最初の単語をコピーする関数を呼び出す
    
    printf("Output:\n%s length = %d\n",out_str,length); //コピー結果の出力
    
    in_str[0]='\0';  //コピー元の先頭をNULL文字にする
    
    length = word_copy(in_str,out_str);
    
    while(length != 0)  //文字列がコピーされている間に表示
    {
        printf("%s length = %d\n",out_str,length);    //コピー結果の出力
        length = word_copy(in_str,out_str); //関数word_copyを再度一度呼び出し、戻り値をlengthに格納
    }
 
    return 0;
}

int word_copy(char *a,char *b)
{
    int i=0,j=0;
    static char *cp;    //文字型のポインタ変数を定義
    
    if(a[0] != '\0')    //1回目の読み込み
    {
        while(a[i] == ' ')  //a[i]が空白ならばa[i]をスキップ
        {
            i++;
        }
        
        while(a[i] != ' ' && a[i] != '\0')  //文字数をカウントしbに保存
        {
            b[j] = a[i];
            i++;
            j++;
        }
        
        b[j] = '\0';    //最後をNULL文字にする
        
        cp = &a[i]; //最後の文字のアドレスを保存
    }
    else
    {
        while( cp[i] == ' ' )   //単語の文字数をカウント
        {
            i++;
        }
               
        while((cp[i] != ' ') && (cp[i] != '\0'))  //文字数をカウントしbに保存
        {
            b[j] = cp[i];
            i++;
            j++;
        }
        
        b[j] = '\0';    //最後をNULL文字にする
        
        cp = cp + i; //ポインタをコピーした単語の直後の文字へと移す
    }
    
    return j;   //jを戻り値とする
}
