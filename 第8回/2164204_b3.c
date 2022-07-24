#include <stdio.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
};

void sort(struct student x[], int n);  //プロトタイプ宣言

struct student data[2240];  //構造体宣言

static int c1=0,c2=0;   //カウント用変数

int main(int argc,char *argv[])
{
    int i=0;    //繰り返し用変数
    FILE *in_fp,*out_fp;   //ファイルポインタ

    in_fp = fopen(argv[1],"r");    //ファイルオープン
    out_fp = fopen(argv[2],"w");
    
    while(fscanf(in_fp,"%d %s %d",&data[i].num,data[i].name,&data[i].score)!=EOF)  //ファイル読み込み、データ格納
    {
        i++;    //インクリメント
    };
    
    sort(data,i);    //ソート関数呼び出し
    
    printf("比較回数=%d  入れ替え回数=%d",c1,c2);
    
    while(i>0)
    {
        i--;
        fprintf(out_fp,"%4d %-20s %3d\n",data[i].num,data[i].name,data[i].score);   //ファイルに書き込む
    }
    
    fclose(in_fp); //ファイル閉じる
    fclose(out_fp);
    
    return 0;
}

void sort(struct student x[], int n)
{
    int i,j,M;
    struct student st;
 
    for(i=0;i<n-1;i++)  //2重ループ
    {
        M=i;
        for(j=i+1;j<n;j++)
        {
            c1++;   //比較回数
            if(x[j].score>x[M].score)   //大小比較 
            {
                M=j;    //値が最大の番号を更新
            }
        }
        st=x[M];    //入れかれ
        x[M]=x[i]; 
        x[i]=st;
        c2++;   //入れ替え回数
    }
}
