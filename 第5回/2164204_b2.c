#include <stdio.h>
int counter(int x[],int n);

int main(void)
{
    int x[100];
    
    printf("0～9 の任意の整数を入力してください ( 入力終了は EOF 制御文字 ) :\n");
    
    int k=0;
    
    while(scanf( "%d",&x[k]) != EOF && k<100)
    {
        k++;
    }
    
    x[k] = -1;  //末尾にEOF
    
    for(int j=0;j<10;j++)
    {
        printf("%d の個数は %d\n",j,counter(x,j));
    }
    
    return 0;
}

int counter(int x[],int n)
{
    int c[10]={0};
    
    for(int i=0;x[i]!=EOF;i++)  //x[]を探索
    {
        if(x[i]==n)
        {
            c[n]++;
        }
    }
    
    return c[n];
}
