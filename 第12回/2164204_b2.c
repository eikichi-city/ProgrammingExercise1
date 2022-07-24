#include <stdio.h>
#define N 5
struct object {
    char name[20];  /* 名称 */
    int weight;     /* 重さ  */
};
struct object b[N] = { /* {名称,重さ} */
        {"A",7},{"B",4},{"C",5},{"D",6},{"E",3}
};

int limw = 15;/*条件重量*/
int sel[N];/*カバンにつめる品物の集合を表す配列*/

//関数のプロトタイプ宣言
void empty_set(int s[],int n);
void print_set(int i,int sel[N]);
/* 品物の組合せを求める．番号(i-1)までの品物はカバンにつめるかつめないかは決定済みとする．
* i : 次に考慮する品物の番号
* tw: これまで選んだ品物の総重量
* n : これまで選んだ品物の個数
*/
void check(int i,int tw,int sel[N],int n);

int main(void)
{
    printf("最大積載量 %dt の荷物の組み合わせは以下の通り\n",limw);
    //selを空にする
    empty_set(sel,N);
    check(0,0,sel,0);
    return 0;
}

// 品物の集合を空にする
void empty_set(int s[], int n)
{
    while(n>0)
        n--; s[n]=0;
}

//結果の表示
//n : これまで選んだ品物の個数
void print_set(int n,int sel[N])
{
    for(int j=0;j<n;j++)
        printf(" %s：%dｔ",b[sel[j]].name,b[sel[j]].weight);
    printf("\n");
}

void check(int i,int tw,int sel[N],int n)
{
    //今まで選んだ品物の次から最後まで繰り返す
    for(int j=i;j<N;j++)
    {
        //n個目露してj番目の品物を入れてみる
        sel[n]=j;
        //今までの総重量と現在選んでいる品物の重量の合計が最大積載量なら結果の表示
        if(tw+b[j].weight==limw)
            print_set(n+1,sel);
        //最大積載量を超えるならj番目の品物は入れないようにする
        if(tw+b[j].weight>limw)
            continue;
        //次の品物を入れてみるために再帰呼び出し
        check(j+1,tw+b[j].weight,sel,n+1);
    }
}