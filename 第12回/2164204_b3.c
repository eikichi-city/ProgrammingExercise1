#include <stdio.h>

#define N 5

int data[N][N]={
{1,2,-1},     // ０ 地点から出ている道の先の地点
{0,2,3,4,-1}, // １ 〃
{0,1,3,-1},   // ２ 〃
{1,2,4,-1},   // ３ 〃
{1,3,-1}};    // ４ 〃

int pass[N];    //見つかった経路を入れる配列
int check[N];   //地点ｉを通ったかどうかを示す配列（iを通っていたらcheck[i]=1）

void answer(int n); //経路表示関数
void search(int n); //経路探索関数

int main(void)
{
    pass[0]=0;  //始点0
    check[0]=1; //0は始点だから必ず通る
    search(1);  //経路探索開始
    return 0;
}

void search(int n)
{
    int already,now;    //already:直前に通った場所 now:今通ろうとしている場所

    already=pass[n-1];  //直前に通った場所を保存

    if(already==4)  //ゴールについていたら
        answer(n);  //今までの経路を表示
    else    //ゴールについてなかったら
    {
        //次通る場所を探索
        for(int i=0;i<N;i++)
        {
            now=data[already][i];   //現在の場所から行ける場所から一つ選択
            if(now==-1) break;  //繰り返して全部行けない場合最後-1となるので今までと覆った経路は不正解
            if(check[now]!=1)   //現在選択している経路にまだ行っていない場合
            {
                pass[n]=now;    //現在選択している経路を通ってみる
                check[now]=1;   //現在選択している経路を通ったことにする
                search(n+1);    //再帰呼び出しにより現在選択している経路の次の経路を探索する
                check[now]=0;   //再帰呼び出しが繰り返し終わった後、現在の経路を通っていないことにしリセット
            }
        }
    }
}

void answer(int n)
{
    //通った経路を表示
    for(int i=0;i<n;i++)
        printf("%2d",pass[i]);
    printf("\n");
}
