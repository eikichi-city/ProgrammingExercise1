// プログラミング演習Ⅰ第3回 2164204_x03_1.c
#include <stdio.h>

int sum(int n);

int main(void)
{
    int i,n;
    printf("n = ");
    scanf("%d",&n);
    
    printf("Σn^2 = %d",sum(n));
    return 0;
}

int sum(int n)
{
    int s=0,i;
    
    if(n>=1){
        for(i=0;i<=n;i++){
            s+=i*i;
        }
    }
    
    else{
        s=0;
    }
    
    return s;
}
