#include<stdio.h>
#include<stdlib.h>

typedef struct member{
    int  num;                    /* 登録番号 */
    char name[20];               /* 氏名 */
    char profile[60];            /* プロフィール  */
    struct member *next;
} list_mbr;

list_mbr *list(FILE *);         //リスト作成関数

void print_list(list_mbr *);    //リスト表示関数

void re_move(list_mbr *listptr, int n); //背番号探索関数

int main(int argc,char *argv[])
{
    //ファイルオープン
    FILE *fp;
    fp=fopen(argv[1],"r");

    list_mbr *listptr;  //構造体ポインタ

    listptr=list(fp);   //ファイルからリスト作成

    print_list(listptr);    //作成したリストの表示

    int n=1;
    //0が入力されるまで背番号探索
    while(n!=0)
    {
        //背番号入力して探索
        printf("登録番号は？　");
        scanf("%d",&n);
        re_move(listptr, n);
    }

    return 0;
}

list_mbr *list(FILE *fp)
{
    list_mbr *p,*newp;  //構造体変数 p:保存用 newp:追加用

    p=NULL; //最初は空
    newp=(list_mbr *)malloc(sizeof(list_mbr));  //構造体データ保存領域の確保
    //ファイルのスキャン
    while(fscanf(fp,"%d %s %s",&newp->num,newp->name,newp->profile)!=EOF)
    {
        newp->next=p;   //後ろに新しく追加
        p=newp;         //追加
        newp=(list_mbr *)malloc(sizeof(list_mbr));  //次のデータの保存領域の確保
    }
    return p;   //保存したリストを返す
}

void print_list( list_mbr *listptr )
{
    list_mbr *p1=listptr;   //引数（保存したリスト）を構造体変数に格納

    //リストが空になるまで表示
    while(p1!=NULL)
    {
        printf("%2d %-14s %s\n",p1->num,p1->name,p1->profile);  //表示
        p1=p1->next;    //次のリストへ
    }
    printf("\n");
}

void re_move(list_mbr *listptr, int n )
{
    list_mbr *p2=listptr;   //引数（保存したリスト）を構造体変数に格納
    list_mbr *q=p2->next;    //削除作業用構造体変数（最後の要素を削除するように初期値設定）
    int exist=0;  //背番号の選手がいるかのフラグ

    //リストが空になるまで探索
    while(p2!=NULL)
    {
        //入力した背番号の選手がいたら
        if(p2->num==n)
        {
            //リストからの削除
            //最後の要素を削除する場合
            if(p2->next==NULL)
            {
                //最後の要素の一つ前の要素のnextをNULLにする
                while(q->next!=p2)
                    q=q->next;
                q->next=NULL;
                free(p2);   //容量解放
            }
            //最後以外の要素を削除する場合
            else{
                q=p2->next;
                *p2=*q;
                free(q);    //容量解放
            }
            printf("---削除しました---\n");  //表示
            //リストを先頭から表示
            print_list(listptr);
            exist=1;    //フラグオン
        }
        p2=p2->next;    //次のリスト
    }
    //該当者がいない場合
    if(exist==0)
        printf("---該当者はいません---\n");
}