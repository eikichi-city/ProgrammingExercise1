// プログラミング演習第6回 2164204_b4.c

#include <stdio.h>

int count_key(char a[], char b[]);   //プロトタイプ宣言

int main(void)
{
    char a[100],b[100];
    
    printf("文字列 a = ");  //探す文字列を入力
    gets(a);
    
    printf("文字列 b = ");  //探される文字列を入力
    scanf("%s",b);
    
    printf("文字列 a の中に %s は%d個ありました\n",b,count_key(a,b));   //文字列aに含まれる文字列bの数を出力
    
    return 0;
}

int count_key(char a[], char b[])
{
    int j=0,k=0,n=0;
    
    for ( int i = 0; a[i] != '\0'; i++ )
    {
        while( b[j] != '\0' )   //bの最後の文字まで繰り返す
        {
            if ( a[i] == b[j] ) //文字列bの文字が文字列aに連続で含まれているかを１文字ずつ確認する
            {
                k++;
            }
            i++;
            j++;
        }
        
        if( k == j )    //文字列aに文字列bが含まれているかを確かめる
        {
            n++;    //文字列aに含まれる文字列bの数を１増やす
            i--;    //次の文字から調べ始めるようにする
        }
        else{
            i = i-j;    //調べ始めた文字の次の文字から調べ直す
        }
        
        k = 0;
        j = 0;
        
    }
    
    return n;//戻り値としてカウントした文字列aに含まれる文字列bの数を返す
}