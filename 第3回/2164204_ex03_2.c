// プログラミング演習Ⅰ第3回 2164204_ex03_2.c
#include <stdio.h>

int sum(int n);

int main(void)
{
    int n;
    
    while(n>=0){
        printf("n = ");
        scanf("%d",&n);
        
        printf("Σn^2 = %d\n",sum(n));
    }
    
    return 0;
}

int sum(int n)
{
    int s=0,i;
    static int ss,sn=-1;
    
    if(n==sn){
        printf("Return cache data.\n");
        return ss;
    }
  
    if(n>=1){
        for(i=0;i<=n;i++){
            s+=i*i;
        }
    }
    else{
        s=0;
    }
    
    ss = s;
    sn = n;
    
    return s;
}
