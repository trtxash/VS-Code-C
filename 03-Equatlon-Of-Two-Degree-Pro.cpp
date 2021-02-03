/*03-Equatlon-Of-Two-Degree-Pro
    功能：
        用户赋给abc三个值，计算一元二次方程
    目的：
        1 改进一元二次方程编程
        2 了解并会用scanf("", )
        3 知道&取址符
*/
#include <math.h>
#include <stdio.h> // 含【scanf("") -- 向标准输入设备读取字符串】的头文件 -- 标准输入输出
#include <windows.h>

int main(void)
{
    double a;
    double b;
    double c;
    double delta;
    double X1;
    double X2;

    printf("a = ?\n");
    scanf("%lf", &a); // scanf("输入控制符"，输入参数) -- 输入字符转为输入控制符类型数据，然后赋给输入参数的地址的变量中
    printf("b = ?\n");
    scanf("%lf", &b); // & -- 取址符
    printf("c = ?\n");
    scanf("%lf", &c); // scanf("非输入控制符+输入控制符"，输入参数) -- 必须原样输入非输入控制符+输入字符才正确
    // scanf("%f,%f,%f\n", a, b, c) -- 要加逗号；scanf("%f %f %f\n", a, b, c) -- 要加空格
    delta = b * b - 4 * a * c;

    if (delta > 0)
    {
        X1 = (-b + sqrt(delta)) / (2 * a);
        X2 = (-b - sqrt(delta)) / (2 * a);
        printf("X1 = %lf,X2 = %lf\n", X1, X2);
        system("pause");
    }
    else if (delta == 0)
    {
        X1 = -b / (2 * a);
        printf("X1 = X2 = %lf\n", X1);
        system("pause");
    }
    else
    {
        printf("无解\n");
        system("pause");
    }

    return 0;
}

/* 输出结果：
--------------------------------------------------------------------------------
a = ?
1
b = ?
5
c = ?
6
X1 = -2.000000,X2 = -3.000000
--------------------------------------------------------------------------------
*/

// 2021年1月13号13点06分