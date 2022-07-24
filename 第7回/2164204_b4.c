#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
    int c;
    int comment = 0; //コメント判定用変数
    
    while((c=getchar())!=EOF)
    {
        if(comment) //コメント/のとき 
        {
            if(c=='\n') //改行のとき
            {
                putchar(c);
                comment=0;
            }
            continue;
        }
        else
        {
            if (c=='/') //フラグON
            {
                comment=1;
                continue;
            }
        }
        
        putchar(c); //文字出力
    }
    
    return 0;
}