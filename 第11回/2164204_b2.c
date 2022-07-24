#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
    int m,n;
    
    //ファイルポインタ
    FILE *fp;
    fp=fopen(argv[1],"w");
    
    printf("1 桁の正数 M を入力してください\n");
    printf("M = ");
    scanf("%d",&m);
    printf("1 桁の正数 N を入力してください\n");
    printf("N = ");
    scanf("%d",&n);
    printf("1 から %d までの数字を %d 個並べた処理結果をファイル %s に出力します\n",m,n,argv[1]);
    
    int i,j,k;
    int a[n];
    
    //並びの総組合せ数
    int z=pow(m,n);
    
    //全ての要素が1の配列、要素数n
    for(i=0;i<n;i++)
    {
        a[i]=1;
    }
    
    //並びの組合せ数繰り返す
    for(i=0;i<z;i++)
    {
        //要素がmをこえていないか調べる
        for(j=0;j<n;j++)
        {   
            //超えていたら、その要素を1として、その１つ前の要素を1増やす
            if(a[j]==m+1)
            {
                a[j]=1;
                a[j-1]++;
            }
        }
        
        //ファイルに書き込む
        for(k=0;k<n;k++)
        {
            fprintf(fp,"%2d",a[k]);
        }
        fprintf(fp,"\n");
        
        //一番最後の要素を1増やす
        a[n-1]++;
    }
    
    fclose(fp);
    return 0;
}