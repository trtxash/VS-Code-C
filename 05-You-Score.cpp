/*
05-You-Score
    功能：
        输入你的成绩，给你一个回复
    目的：
        1 锻炼使用if else
*/

#include <stdio.h>
#include <windows.h>

int main(void)
{
    float score;

    printf("请输入你的成绩\n");
    scanf("%f", &score);

    if (score > 150) // if只管最近的一行代码，加大括号框想管的代码
    {
        printf("你在做白日梦！\n");
    }
    else if (score == 150)
    {
        printf("满分，你真棒！\n");
    }
    else if (score < 150 && score >= 120)
    {
        printf("优秀！");
    }
    else if (score < 120 && score >= 90)
    {
        printf("及格了！");
    }
    else if (score < 90 && score >= 0)
    {
        printf("不及格，下此努力！");
    }
    else
    {
        printf("还能得负分？？？！！！");
    }
    system("pause");

    return 0;
}

/*输出结果
--------------------------------------------------------------------------------
请输入你的成绩
130
优秀！
--------------------------------------------------------------------------------
*/

//2021年1月13号18点59分