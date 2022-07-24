#include <stdio.h>

int func( int n );

int main()
{
    int n;
    
    printf("n=");
    scanf("%d",&n);
    
    func(n);
    
    return 0;
}

int func( int n )
{
    if( n<1000 ){
        static int i=0;
        
        if(i==0){
            printf("%d",n);
            i++;
        }
        else{
            printf("%03d",n);
        }
    }
    else{
        func(n/1000);
        printf(",");
        func(n%1000);
    }
}

