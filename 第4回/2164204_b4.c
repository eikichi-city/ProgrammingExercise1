// プログラミング演習Ⅰ第4回　2164204_b4.c
#include <stdio.h>

void func(unsigned int n);

int main(void)
{
    unsigned int n;
    
    printf("n=");
    scanf("%d",&n);
    
    func( n );
    
    printf("\n");
    
    return 0;
}

void func(unsigned int n){
    int t=0;
    unsigned int m=n;
    
    do{
        m = m / 10;
        t++;
    }while(m!=0);
    
    int N[t];
    int i;
    
    for(i=0;i<t;i++){
        N[i]=n%10;
        n=n/10;
    }
    
    for(i=t-1;i>=0;i--){
        if( i%3==0 && i!=0 ){
            printf("%d,",N[i]);
        }
        else{
            printf("%d",N[i]);
        }
    }
}
