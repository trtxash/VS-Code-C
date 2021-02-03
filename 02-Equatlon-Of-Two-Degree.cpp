/*
02-Equatlon-Of-Two-Degree
    功能：
        给abc赋3个值，计算出一元二次方程的解
    目的：
        1 记住BODH
        2 记住八进制，十六进制数的写法
        3 学会printf的用法
        4 了解整型数，浮点数
        5 会整型数，浮点数，字符的输出
        6 了解关系运算符
*/

#include <math.h> // 含【sqrt(delta) -- 开平方根】的头文件 -- 各种数学函数和一个宏
#include <stdio.h>
#include <windows.h>

int main(void)
{
    /*
    十六进制的666 -- 0x666；八进制的666 -- 0666；浮点数的6.66 -- 666e-2
    int -- 整型 -- 4bytes；short int -- 短整型 -- 2bytes；long int -- 长整型 -- 8bytes；float -- 单精度浮点数 -- 4bytes；double -- 双精度浮点数 -- 8bytes
    float a = 1F,1看作float数据
    */
    double a = 1; // 定义变量a，将1赋值a；变量定义后在后面需要初始化
    double b = 5;
    double c = 6;
    double delta;
    double X1;
    double X2;

    delta = b * b - 4 * a * c;

    if (delta > 0) // 关系运算符： > < == != >= <=; -- 满足为1，不满足为0
    {
        X1 = (-b + sqrt(delta)) / (2 * a);
        X2 = (-b - sqrt(delta)) / (2 * a);
        printf("X1 = %lf,X2 = %lf\n", X1, X2); // printf("字符串")，printf("输出控制符"，输出参数)；printf("输出控制符1 输出控制符2"，输出参数1，输出参数2)
        /*
        %d -- 整型输出，%ld -- 长整型输出,%f -- 用来输出单精度浮点数，%lf -- 双精度浮点数，默认情况下保留小数点6位,%.100f -- 保留小数点100位
        %o -- 八进制输出，%x -- 十六进制输出，结果小写，%X -- 十六进制输出，结果大写；%#x || %#X -- 十六进制输出，结果带前缀
        %c -- 字符输出
        \n -- 换行
        */
        system("pause");
    }
    else if (delta == 0)
    {
        printf("X1 = X2 = %lf\n", X1, X2);
        system("pause");
    }
    else
    {
        printf("无解\n");
        system("pause");
    }

    return 0;
}

/*
输出结果：
--------------------------------------------------------------------------------
X1 = -2.000000,X2 = -3.000000
--------------------------------------------------------------------------------
*/

// 2021年1月10号21点00分