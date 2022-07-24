// プログラミング演習Ⅰ第2回 2164204_ex02_2.c
#include <stdio.h>

int main(void)
{
    int k,l,n;
    
    printf("九九で結果が 24 になる数字の組み合わせを表示するプログラム\n");
    
    for(k=1;k<10;k++){
        for(l=1;l<10;l++){
            if(k>=5 && l>=5){
                break;
            }
            n=k*l;
            if(n==24){
                printf("解 %d %d\n",k,l);
            }
        }
    }
    
    return 0;
}
