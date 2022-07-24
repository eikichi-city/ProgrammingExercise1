#include <stdio.h>

double func(double *v1,double *v2,int dim);

int main(void)
{
    int dim,i;
    double v1[10],v2[10];
    
    printf("ベクトルの次元n(最大10): = ");
    scanf("%d",&dim);
    
    printf("ベクトル1:\n");
    for(i=0;i<dim;i++)
    {
        scanf("%lf",&v1[i]);
    }
    
    printf("ベクトル2:\n");
    for(i=0;i<dim;i++)
    {
        scanf("%lf",&v2[i]);
    }
    
    printf("内積の値は%lfです。",func(&v1,&v2,dim));
    
    return 0;
}

double func(double *v1,double *v2,int dim)
{
    double ans=0;
    int i;
    
    for(i=0;i<dim;i++)
    {
        ans += v1[i] * v2[i];   //同じ成分同士の掛け算をして足し合わせる
    }
    
    return ans;
}