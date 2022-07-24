// プログラミング演習Ⅰ第4回 2164204_ex04_2.c
#include <stdio.h>

int gcd(int a,int b);

int main(void)
{
        int a,b,w;
        
        printf("自然数aと自然数bの最大公約数を求めるプログラム\n");

        printf("(a,b) = ");
        scanf("%d %d",&a,&b);
        
        if(a<b){
            w = b;
            b = a;
            a = w;
        }
        
        printf("%dと%dの最大公約数は%d",a,b,gcd(a,b));
        
        return 0;
}

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}