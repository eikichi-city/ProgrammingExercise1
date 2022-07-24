// プログラミング演習第6回 2164204_b1.c

#include <stdio.h>

int str_copy( char a[], char b[] );

int main(void)
{
    char in_str[]="Yokohama National University";   //コピー元の文字列
    char out_str[100];  //コピー先の文字列
    
    printf("Input:%s\n",in_str);
    printf("Output:%s,length=%d",out_str,str_copy(in_str,out_str));
    
    return 0;
}

int str_copy( char a[], char b[] )
{
    int i=0;
    
    while(a[i] != '\0') //コピー元文字列の最後の文字まで読み込む
    {
        b[i]=a[i];  //コピー
        i++;
    }
    b[i]='\0';  //コピー先の文字列最後の文字
    
    return i;
}

