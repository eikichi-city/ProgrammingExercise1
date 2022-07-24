// プログラミング演習Ⅰ第1回演習課題（2）「２つのデータを入れ替えるプログラム」
#include <stdio.h>

int main(void)
{
    int a = 3, b = 7;
    int c;
    
    printf("a = %d, b = %d\n", a, b);
    
    c = a;
    a = b;
    b = c;
    
    printf("a = %d, b = %d\n", a, b);
    
    return 0;
}
