// プログラミング演習Ⅰ第2回 2164204_ex02_3.c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a,d,x,e;
    int n,f;
    
    printf("指数関数 exp(x) [eのx乗]を、級数展開を使って求めるプログラム\n");
    
    printf("x = ");
    scanf("%lf",&x);
    
    n=1;
    a=0;
    d=1;
    
    if(x < 0){
        x = fabs(x);
        f = 1;
    }
    else{
        f = 0;
    }
    
    do{
        a+=d;
        printf("%.2d %.8le\n",n,a);
        d*=x/n;
        n++;
    }while(d>0.0000001);
    
    if(f==1){
        printf("ans = %.8le",1/a);
    }
    else if(f==0){
        printf("ans = %.8le",a);
    }
    
    return 0;
}
