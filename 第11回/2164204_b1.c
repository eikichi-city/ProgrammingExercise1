#include <stdio.h>

int conversion(int a,int n);    //プロトタイプ宣言

int main(void)
{
    int a,n;    //a:変換する数 n:n進法
    
    do  //aが正の間
    {
        printf("10進数の正数を入力してください ( 0 以下で終了 ):"); //a入力
        scanf("%d",&a);
        if(a>0) //aが正なら
        {
            n=1;    //エラー防止の為に仮に置いておく
            while(n<2||n>16)    //2<=n<=16となるまで
            {
                printf("n 進数に変換しますか? ( 2 ≦ n ≦ 16 ) :");   //n入力
                scanf("%d",&n);
                if(2<=n&&n<=16)   //2<=n<=16なら
                {
                    conversion(a,n);    //aをn進数に変換する
                    printf("\n\n");
                }
                else    //エラーメッセージ
                    printf("2 ≦ n ≦ 16 ではありません\n");
            }
        }
        else    //エラーメッセージ
            printf("処理を終了します\n");
    }
    while(a>0);
    
    return 0;
}

int conversion(int a,int n)
{
    int b;  //余り用
    
    b=a%n;  //余り求める
    a=a/n;  //割られる数を商に変換

    if(a>0)                 //商が０でない限り
        conversion(a,n);    //再帰的に呼び出し次の桁の計算をする

    if(b>=0&&b<=9)      //余りが0から9ならそのまま表示
        printf("%d",b);
    else if(b>9)        //余りが９以上ならアルファベットで表示
        putchar('a'+b-10);
}
