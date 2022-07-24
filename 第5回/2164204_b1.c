#include <stdio.h>
#define EOD -1

int max(int x[] );

int main(void)
{
    int x[]={31,4,17,45,0,88,24,76,52,EOD};
    
    printf("配列{");
    for(int i=0;x[i]!=EOD;i++) //配列の要素を表示
    {
        printf("%d ",x[i]);
    }
    printf("}の\n");
    printf("最大値：%d",max(x)); //配列の最大値を表示
    
    return 0;
}

int max(int x[])
{
    int max=0;
    for(int i=0;x[i]!=EOD;i++) //配列を調べる
    {
        if(x[i]>max)
        {
            max = x[i]; //最大値の更新
        }
    }
    
    return max;
}