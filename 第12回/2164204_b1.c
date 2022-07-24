#include <stdio.h>

int check[10]={0};  //選んだ４つの数を保存する配列
int sel[4];         //選ばれているかをチェックする配列、ただし、int check[ 0 ] は使わない

int three_div(int n,int i); //n:sel[n] i:sel[n]の値の候補

int main(void) 
{
    printf("ab, cd\n");
    //関数呼び出し、sel[0]をi(1~9)にする
    for(int i=1;i<10;i++) 
        three_div(0, i);
    return 0;
}


int three_div(int n,int i)
{
    if (check[i]==1) return 0;    //iが既に選ばれているなら失敗
    check[i]=1; //選ぶ
    sel[n]=i;   //選んだ値を保存
    //数字を４つ選んだ時の処理
    if(n==3)
    {
        //ab,cdの組みをそれぞれ2桁の実数とした時、(ab/cd)=3となる時、ab,cdを表示
        if((sel[0]*10+sel[1])/(sel[2]*10+sel[3])==3&&((sel[0]*10+sel[1])%(sel[2]*10+sel[3]))==0) 
        {
            int x=sel[0]*10+sel[1];
            int y=sel[2]*10+sel[3];
            printf("%d, %d\n",x,y);
        }
    } 
    //まだ４つ選んでないなら、次の数字を選ぶため再帰呼び出し
    else 
        for(int j=1;j<10;j++)
            three_div(n+1,j);
    check[i] = 0;   //リセット
}
