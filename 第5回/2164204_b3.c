#include <stdio.h>

void in_arr(double arr[2][2]);
void out_arr(double arr[2][2]);
double inv(double arr[2][2]);

int main(void)
{   
    double arr[2][2];
    
    in_arr(&arr[2][2]);
    out_arr(&arr[2][2]);
    inv(&arr[2][2]);
    
    return 0;
}

void in_arr(double arr[2][2])
{
    int i,j;
    printf("2×2の行列の要素の値を入力\n");  //成分入力
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("arr[%d][%d]:",i,j);
            scanf("%lf",&arr[i][j]);
        }
    }
}

void out_arr(double arr[2][2])
{
    printf("行列:\n%4lf %4lf\n%4lf %4lf\n\n",arr[0][0],arr[0][1],arr[1][0],arr[1][1]);
}

double inv(double arr[2][2])
{
    double inv,n;
    
    inv=arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];    //逆行列の公式
    
    if(inv==0)
    {
        printf("逆行列はありません。\n");
    }
    else
    {
        n=arr[0][0];
        arr[0][0]=arr[1][1]/inv;
        arr[0][1]=arr[0][1]/inv*(-1);
        arr[1][0]=arr[1][0]/inv*(-1);
        arr[1][1]=n/inv;
        
        printf("逆行列は\n%4lf %4lf\n%4lf %4lf\n\n",arr[0][0],arr[0][1],arr[1][0],arr[1][1]);
    }
    
    return 0;
}