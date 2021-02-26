/*
01-Operator
    功能
        进行加减乘除，取余运算，逻辑运算输出结果
    目的
        1 了解隐式类型转换
        2 验证加减乘除，取余运算，逻辑运算的规则
        3 进一步了解printf("")
*/

#include <stdio.h>
#include <windows.h>

int main(void)
{
    /*
    隐式类型转换
        1.为防止精度损失,如果必要的话,类型总是被提升为较宽的类型
        2.所有含有小于整形的有序类型的算术表达式在计算之前其类型都会被转换成整形

    printf输出换行格式
        printf(
            "输出控制符1"
            "输出控制符2"
            "输出控制符3",
            输出参数1,
            输出参数2,
            输出参数3);
    */
    printf(
        "下面是加减乘除\n"
        "1 + 2 + 3 = %d, 1 - 2 - 3 = %d, 1 * 2 * 3 = %d,\n" // int与int计算出int，int或float与float计算出float
        "3 / 5 = %d    , 5 / 3 = %d    , -13 / 4 = %d  ,\n"
        "16 / 5 = %d   , 16 / 5.0 = %f ,\n\n", // 注意输出控制符与实际数型一样，防止数值丢失
        1 + 2 + 3, 1 - 2 - 3, 1 * 2 * 3,
        3 / 5, 5 / 3, -13 / 4,
        16 / 5, 16 / 5.0);

    printf(
        "下面是取余\n"
        "3对3取余 = %d, 13对-3取余 = %d, -13对3取余 = %d, -13对-3取余 = %d, -13对23取余 = %d, 3对5取余 = %d\n\n",
        3 % 3, 13 % -3, -13 % 3, -13 % -3, -13 % 23, 3 % 5); // 取余输出的符号与被除数相同

    printf(
        "下面是非并或\n"
        "!1 = %d    , !0 = %d\n"
        "1 && 1 = %d, 1 && 0 = %d, 0 && 1 = %d, 0 && 0 = %d\n"    // 左边为0，输出就为0 -- 简化计算，右边忽略
        "1 || 1 = %d, 1 || 0 = %d, 0 || 1 = %d, 0 || 0 = %d\n\n", // 左边为1，输出就为1 -- 简化计算，右边忽略
        !1, !0,
        1 && 1, 1 && 0, 0 && 1, 0 && 0,
        1 || 1, 1 || 0, 0 || 1, 0 || 0);

    system("pause");

    return 0;
}

/*输出结果
----------------------------------------------------------------------------------------------------
下面是加减乘除
1 + 2 + 3 = 6, 1 - 2 - 3 = -4, 1 * 2 * 3 = 6,
3 / 5 = 0    , 5 / 3 = 1    , -13 / 4 = -3  ,
16 / 5 = 3   , 16 / 5.0 = 3.200000 ,

下面是取余
3对3取余 = 0, 13对-3取余 = 1, -13对3取余 = -1, -13对-3取余 = -1, -13对23取余 = -13, 3对5取余 = 3

下面是非并或
!1 = 0    , !0 = 1
1 && 1 = 1, 1 && 0 = 0, 0 && 1 = 0, 0 && 0 = 0
1 || 1 = 1, 1 || 0 = 1, 0 || 1 = 1, 0 || 0 = 0
----------------------------------------------------------------------------------------------------
*/

// 2021年1月13号17点08分