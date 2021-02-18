/*
05-Operator+
    功能：
        看++x,x++的区别,验证逗号表达式的运算逻辑
    目的：
        1 学习++x,x++
        2 学习逗号表达式
*/

#include <stdio.h>
#include <windows.h>

int main(void)
{
    /*
    x++表示x自增1后再参与其它运算
    ++x是x参与运算后,x的值再自增1
    */
    int a;
    int b = 5;
    a = b++; // b++现在是后自增,参与运算是5赋给了a,b再变为6
    printf("a = %d, b = %d\n", a, b);

    int c;
    int d = 10;
    c = ++d; // ++d现在是先自增,参与运算是11赋给了c,d先变为11
    printf("c = %d, d = %d\n", c, d);

    system("pause");

    return 0;
}

/*输出结果
----------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------
*/

//2021年2月18号17点06分