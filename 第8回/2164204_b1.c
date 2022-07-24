#include <stdio.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
};

struct student data[2240];

int main(int argc,char *argv[])
{
    int i=0;    //繰り返し用変数
    FILE *fp;   //ファイルポインタ

    fp = fopen(argv[1],"r");    //ファイルオープン
    
    while(fscanf(fp,"%d %s %d",&data[i].num,data[i].name,&data[i].score)!=EOF)  //ファイル読み込み、データ格納
    {
        printf("%4d %-20s %3d\n",data[i].num,data[i].name,data[i].score);   //格納したデータの表示
        i++;    //インクリメント
    };
    
    fclose(fp); //
    
    return 0;
}