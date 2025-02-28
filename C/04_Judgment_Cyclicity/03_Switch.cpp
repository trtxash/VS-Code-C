/*
03_Switch
    功能 
        利用switch输出你的成绩评分
    目的
        1 学习switch
*/

#include <stdio.h>
#include <windows.h>
/*
switch(expression)
{
    case constant-expression  :
       statement(s);
       break; // 可选的
    case constant-expression  :
       statement(s);
       break; // 可选的
  
    // 您可以有任意数量的 case 语句
    default : // 可选的
       statement(s);
}

switch 语句中的 expression 是一个常量表达式，必须是一个整型或枚举类型。
在一个 switch 中可以有任意数量的 case 语句。每个 case 后跟一个要比较的值和一个冒号。
case 的 constant-expression 必须与 switch 中的变量具有相同的数据类型，且必须是一个常量或字面量。
当被测试的变量等于 case 中的常量时，case 后跟的语句将被执行，直到遇到 break 语句为止。
当遇到 break 语句时，switch 终止，控制流将跳转到 switch 语句后的下一行。
不是每一个 case 都需要包含 break。如果 case 语句不包含 break，控制流将会 继续 后续的 case，直到遇到 break 为止。
一个 switch 语句可以有一个可选的 default case，出现在 switch 的结尾。default case 可用于在上面所有 case 都不为真时执行一个任务。default case 中的 break 语句不是必需的。
*/

int main(void)
{
    float score;
    int grade;

    printf("请输入你的成绩\n");
    scanf("%f", &score);

    if (score <= 150 && score >= 120)
        grade = 'A';

    else if (score <= 150 && score >= 120)
        grade = 'B';

    else if (score < 120 && score >= 90)
        grade = 'c';

    else if (score < 90 && score >= 0)
        grade = 'D';
    else
    {
        printf("出错");
        return 0;
    }

    switch (grade)
    {
    case 'A':
        printf("很棒！\n");
        break;

    case 'B':
        printf("做得好\n");
        break;

    case 'c':
        printf("您通过了\n");
        break;

    default:
        printf("最好再试一下\n");
        break;
    }

    return 0;
}

/*输出结果
----------------------------------------------------------------------------------------------------
请输入你的成绩
-1
出错
----------------------------------------------------------------------------------------------------
*/

// 2021年2月28号20点19分