/*
01_Array
    功能
        用a[ ][3]探究数组
    目的   
        1 学会数组
*/

#include <stdio.h>

int main()
{
    /*
    C 语言支持数组数据结构，它可以存储一个固定大小的相同类型元素的顺序集合。数组是用来存储一系列数据，但它往往被认为是一系列相同类型的变量。
    数组的声明并不是声明一个个单独的变量，比如 runoob0、runoob1、...、runoob99，而是声明一个数组变量，比如 runoob，然后使用 runoob[0]、runoob[1]、...、runoob[99] 来代表一个个单独的变量。
    所有的数组都是由连续的内存位置组成。最低的地址对应第一个元素，最高的地址对应最后一个元素。
    如果您省略掉了数组的大小，数组的大小则为初始化时元素的个数
    */
    int a[ ][3] = { {1,4}, {3,2}, {4,5,6}, {0} }; // 一个带有 x 行 3 列的数组，{ {1,4}, {3,2}, {4,5,6}, {0} } 第一层大括号表示所有，第二层第n个大括号表示第n行
    printf("%d\n", a[0][0]);
    printf("%d\n", a[0][1]);
    printf("%d\n", a[0][2]);
    printf("%d\n", a[1][0]);
    printf("%d\n", a[1][1]);
    printf("%d\n", a[1][2]);
    printf("%d\n", a[2][0]);
    printf("%d\n", a[2][1]);
    printf("%d\n", a[2][2]);

    return 0;
}

/*输出结果
----------------------------------------------------------------------------------------------------
1
4
0
3
2
0
4
5
6
----------------------------------------------------------------------------------------------------
*/

// 2021年2月28号21点04分