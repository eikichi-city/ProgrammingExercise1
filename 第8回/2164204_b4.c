#include <stdio.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
};

void sort_score(struct student x[], int n);  //プロトタイプ宣言
void sort_num(struct student x[], int n);

struct student data[2240];  //構造体宣言

int main(int argc,char *argv[])
{
    int i=0;    //繰り返し用変数
    FILE *in_fp,*out_fp;   //ファイルポインタ

    in_fp = fopen(argv[1],"r");    //ファイルオープン
    out_fp = fopen(argv[2],"w");
    
    printf("入力ファイル：%s\n",argv[1]);
    
    while(fscanf(in_fp,"%d %s %d",&data[i].num,data[i].name,&data[i].score)!=EOF)  //ファイル読み込み、データ格納
    {
        printf("%4d %-20s %3d\n",data[i].num,data[i].name,data[i].score);   //格納したデータの表示
        i++;    //インクリメント
    };
    
    printf("\n出力ファイル：%s\n",argv[2]);
    
    sort_score(data,i);    //スコアソート関数呼び出し
    
    sort_num(data,i);   //学籍番号ソート関数呼び出し
    
    while(i>0)
    {
        i--;    //デクリメント
        fprintf(out_fp,"%d,%s,%d\n",data[i].num,data[i].name,data[i].score);   //書き込み
        printf("%4d %-20s %3d\n",data[i].num,data[i].name,data[i].score);   //格納したデータの表示
    }
    
    fclose(in_fp); //ファイル閉じる
    fclose(out_fp);
    
    return 0;
}

void sort_score(struct student x[], int n)
{
    int i,j,M;
    struct student st;
 
    for(i=0;i<n-1;i++)  //2重ループ
    {
        M=i;
        for(j=i+1;j<n;j++)
        {
            if(x[j].score>x[M].score)   //大小比較 
            {
                M=j;    //値が最大の番号を更新
            }
        }
        st=x[M];    //入れかれ
        x[M]=x[i]; 
        x[i]=st;
    }
}

void sort_num(struct student x[], int n)
{
    int i,M;
    struct student st;
 
    for(i=0;i<n-1;i++)
    {
        M=i;
        if(x[i+1].num>x[i].num)   //大小比較 
        {
            M++;    //値を増やす
        }
        st=x[M];    //入れかえ
        x[M]=x[i]; 
        x[i]=st;
    }
}
