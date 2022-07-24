// プログラミング演習Ⅰ第1回演習課題（2）「２つのデータを入れ替えるプログラム」
#include <stdio.h>

int main(void)
{
    int a = 3, b = 7;
    
    printf("a = %d, b = %d\n", a, b);
    
    b = b - a;
    a = a + b;
    b = a - b;
    
    printf("a = %d, b = %d\n", a, b);
    
    return 0;
}
