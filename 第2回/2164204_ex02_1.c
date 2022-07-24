de// プログラミング演習Ⅰ第2回 2164204_ex02_1.c
#include <stdio.h>

int main(void)
{
    int n,fact,i;
    fact=1;
    
    printf("n!を求めるプログラム\n");
    
    while(n>5){
        printf("n=");
        scanf("%d",&n);
        if(n>5){
            printf("5以下の正の整数を入力してください\n");
        }
    }
    
    if(n==0){
        printf("n!=%d",fact);
    }
    else if(n<0){
        printf("nの値が負なので計算できません\n");
    }
    else{
        for(i=1;i<=n;i++){
            fact*=i;
        }
        printf("n!=%d",fact);
    }

    return 0;
}
