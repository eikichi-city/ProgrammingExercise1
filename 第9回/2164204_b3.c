#include <stdio.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
};

void quicksort(int left,int right);  //プロトタイプ宣言
void sort(struct student x[], int n);  //プロトタイプ宣言（学籍番号用）

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
        i++;    //インクリメント
    };
    
    printf("\n出力ファイル：%s\n",argv[2]);
    
    quicksort(0,i-1);    //ソート関数呼び出し
    
    sort(data,i);
    
    while(i>0)
    {
        i--;    //デクリメント
        fprintf(out_fp,"%4d %-20s %3d\n",data[i].num,data[i].name,data[i].score);   //書き込み
    }
    
    fclose(in_fp); //ファイル閉じる
    fclose(out_fp);
    
    return 0;
}

void quicksort(int left,int right)
{
    int i,j;
    struct student x,w;
    
	if (left<right) //左右関係が崩れていない場合
	{
		i = left;
		j = right;
		x = data[(left+right)/2]; //左右の中央
		
		do
		{
			while(data[i].score<x.score)  //左側が中央より小さい場合
			{
			    i++;    //中央に近づける
			}
			while(x.score<data[j].score)  //右側が中央より大きい場合
			{
			    j--;    //中央に近づける
			}
			if(i<=j)    //左右の関係が崩れていない場合
			{
				if(i<j) //ここではi!=jと同じ意味
				{
					w=data[i];    
                    data[i]=data[j];
                    data[j]=w;            //左右のデータを入れ替える
				}
				i++;    //中央に近づける
				j--;    //中央に近づける
			}
		}
		while(i<=j);    //左右の関係が崩れていない場合
		
		if(left<j)  //左右の関係が崩れていない場合
		{
		    quicksort(left,j);   //再帰呼び出し
		}
		
		if(i<right) //左右の関係が崩れていない場合
		{
		    quicksort(i,right);  //再帰呼び出し
		}
	}
}

void sort(struct student x[], int n)
{
    int i,j;
    struct student st;
 
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(x[j].score==x[i].score)
            {
                if(x[j].num>x[i].num)   //大小比較 
                {
                    st=x[j];    //入れかえ
                    x[j]=x[i]; 
                    x[i]=st;
                }    
            }
        }
    }
}