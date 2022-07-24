#include<stdio.h>

#define N 256003

int main(int argc,char *argv[])
{
    FILE *infp,*outfp;  //ファイルポインタ
    int n[N],i;         //
    char str[4];
    
    infp=fopen("ex07-3_data.pgm","r");
    outfp=fopen("ex07-3_data.pbm","w");
    
    fscanf(infp,"%s",str);  //1行目の読み込み
    fscanf(infp,"%d %d",&n[0],&n[1]);   //2行目の読み込み
    
    for(i=2;i<N;i++)
    {
        fscanf(infp,"%d",&n[i]);    //数字の読み込み
    }
    
    fprintf(outfp,"%s\n",str);  //1行目の表示
    fprintf(outfp,"%d %d\n",n[0],n[1]); //2行目の表示
    fprintf(outfp,"%d\n",n[2]); //3行目の表示
    
    for(i=3;i<N;i++)    //4行目以降の表示
    {
      if(n[i]>(n[2]/2)) //225/2=112.5より値が大きかった場合
      {
          n[i]=n[2];    //255にする
      }
      else              //225/2=112.5より値が小さかった場合
      {
          n[i]=0;       //0にする
      }
      
      fprintf(outfp,"%d\n",n[i]);   //各行表示
    }
    
    fclose(infp);
    fclose(outfp);
    
    puts("ファイル「ex07-3_data.pgm」を2値化し、ファイル「ex07-3_data.pbm」に出力\n");
    
    return 0; 
}