// プログラミング演習Ⅰ第2回 2164204_ex02_4.c
#include <stdio.h>

int main(void)
{
    double h,w,sb,f,sw;
    int s;
    
    printf("BMI ( 体格指数 ) 法を用いて肥満度を表示するプログラム\n");
    
    printf("身長[m] = ");
    scanf("%lf",&h);
    printf("体重[kg] = ");
    scanf("%lf",&w);
    printf("男性:1 女性:2 男女共通:その他 = ");
    scanf("%d",&s);
    if(s=1){
        sb=22;
    }
    else if(s=2){
        sb=21;
    }
    else{
        sb=21.5;
    }
    
    sw=h*h*sb;
    printf("標準体重[kg] = %lf\n",sw);
    
    f=(w/sw-1)*100;
    printf("肥満度[％] = %lf\n",f);
    
    if(f>=10){
        printf("太り過ぎ\n");
    }
    else if(f<=-10){
        printf("痩せすぎ\n");
    }
    else{
        printf("標準\n");
    }
    
    return 0;
}
