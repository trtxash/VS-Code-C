/*
01_Prime_Number
    功能
        已知某一正整数其各位数字及各位数字之和均为素数，编程找出1-1000中满足条件的数结果每行5个输出
    目的
        1 测试学习
        2 复习c语言
*/

#include <stdio.h>
#include <windows.h>

int sushu(int x);   // 判断x是否为素数，并返回1或0
int hesushu(int x); // 判断x各位数之和是否为素数，并返回1或0，用到了sushu(int x)
int gesushu(int x); // 判断x的各位数是否为素数，并返回1或0，用到了sushu(int x)

int n;

int main(void)
{
    int i;

    for (n = 1; n <= 1000;)
    {
        for (i = 1; i <= 5 && n <= 1000; n++)
        {
            if (sushu(n) && hesushu(n) && gesushu(n)) // 如果三项为真，则输出
            {
                printf("%d ", n);
                i++;
            }
        }
        printf("\n"); // 和for用于控制输出为5个一行
    }
    system("pause");

    return 0;
}

int sushu(int x)
{
    int i;

    while (x == 1) // 排除1
        return 0;
    while (x == 2) // 加入2
        return 1;
    for (i = 2; i < x; i++) // 求一个数各位上数字之和，可以先让他%10得到最后个位上的数，让后让它除以10；继续将结果%10得到十位上的数；如此循环直到除10后值为0时结束
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int hesushu(int x)
{
    int sum;

    for (sum = 0; x > 0; x = x / 10)
    {
        sum += x % 10; // 用+=求总和
    }
    return sushu(sum);
}

int gesushu(int x)
{
    int m;

    for (m = 0; x > 0; x = x / 10)
    {
        m = x % 10;
        while (sushu(m) == 0)
            return 0;
    }
    return 1;
}

/*输出结果
----------------------------------------------------------------------------------------------------
2 3 5 7 23
223 227 337 353 373
557 577 733 757 773

Press any key to continue . . . 
----------------------------------------------------------------------------------------------------
*/

// 2021年3月2号3点01分