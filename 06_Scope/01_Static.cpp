/*
01_Static
    功能
        利用static测试变量,并输出
    目的
        1 了解局部变量,全局变量
        2 初步了解静态变量,静态函数
        3 了解静态数据的存储
*/

#include <stdio.h>

int f(int n);

/*
加 int m; 为全局变量
全局变量是定义在函数外部,通常是在程序的顶部,全局变量在整个程序生命周期内都是有效的,在任意的函数内部能访问全局变量,全局变量可以被任何函数访问,也就是说,全局变量在声明后整个程序中都是可用的
*/
int main(void)
{
    /*
    在某个函数或块的内部声明的变量称为局部变量
    它们只能被该函数或该代码块内部的语句使用
    局部变量在函数外部是不可知的
    */
    int k;
    k = f(3);                   // 先进入f(3),执行完循环 for (k = n; k > 0; k--) 后,静态变量 k=0;s=3; 函数返回 s的值,k=f(3)=3
    printf("(%d,%d)", k, f(k)); // 从左到右,先输出k的值3,后进入f(k)，k是局部变量 k=3,f(3),执行循环 由于静态变量 s=3 最后 s=6 ,函数返回s,k=f(3)=6,最后程序输出 3,6
    return 0;
}

int f(int n)
{
    /*
    加static为静态变量或函数,静态局部变量使用static修饰符定义,即使在声明时未赋初值,编译器也会把它初始化为0
    且静态局部变量存储于进程的全局数据区,即使函数返回,它的值也会保持不变
    */
    static int k, s;

    n--;
    for (k = n; k > 0; k--)
        s += k;
    return s;
}

/*
函数的使用方式与全局变量类似，在函数的返回类型前加上static，就是静态函数。其特性如下

静态函数只能在声明它的文件中可见，其他文件不能引用该函数
不同的文件可以使用相同名字的静态函数，互不影响
*/

/*输出结果
----------------------------------------------------------------------------------------------------
(3,6)
----------------------------------------------------------------------------------------------------
*/

// 2021年2月27号21点40分