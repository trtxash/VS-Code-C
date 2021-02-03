/*
02-Equatlon-Of-Two-Degree
    功能：
        给abc赋3个值，计算出一元二次方程的解
    目的：
        1 了解基本数据类型,了解整型数,浮点数；记住BODH，记住八进制，十六进制数的写法;知道计算机的科学计数法
        2 学会printf的用法，会整型数，浮点数，字符的输出
        3 了解关系运算符
*/

#include <math.h> // 含【sqrt(delta) -- 开平方根】的头文件 -- 各种数学函数和一个宏
#include <stdio.h>
#include <windows.h>

int main(void)
{
    /*
    整数类型
        char            -- 1 byte
        unsigned char   -- 1 byte
        signed char     -- 1 byte
        int             -- 2 or 4 bytes
        unsigned int    -- 2 or 4 bytes
        short           -- 2 bytes
        unsigned short  -- 2 bytes
        long            -- 4 bytes
        unsigned long   -- 4 bytes
    
    浮点类型
        float           -- 4 bytes      -- 6 位小数
        double          -- 8 bytes      -- 15 位小数
        long double     -- 16 bytes     -- 19 位小数
    
            float a = 1F,1看作float数据
    
    基本类型书写
        整数
            默认为10进制 ,10 ，20
            以0开头为8进制,045，021
            以0b开头为2进制,0b11101101
            以0x开头为16进制,0x21458adf
        小数
            单精度常量:2.3f
            双精度常量:2.3 -- 默认为双精度
        字符型常量
            用英文单引号括起来,只保存一个字符'a'、'b' 、'*' ,还有转义字符 '\n' 、'\t'
        字符串常量
            用英文的双引号引起来 可以保存多个字符"abc"
    
    科学计数法
        1.03乘10的9次方   --   1.03E+09   --   1.03e09 -- 1.03e+9
        1.03乘10的-9次方  --   1.03E-09   --   1.03e-9
    */
    double a = 1; // 定义变量a，将1赋值a；变量定义后在后面需要初始化
    double b = 5; // 命名的第一个字符必须是字母或者下划线,例如合法的命名:name_123; name123_; _name123; _123name,不能以数字开头,不能包含除字母,下划线,数字以外的其他字符
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