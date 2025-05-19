/**
 * @file	Data structure ch1
 * @brief
 * @author 	trtxash
 * @version 0.0.1
 * @date 	2025-05-19 13:11
 */
#include "mymath.h"
#include "time.h"
#include <math.h>
#include <stdio.h>

#define LOOP_NUM 10000000
#define EXP_NUM  20

clock_t start, stop;
double myarry[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

/**
 * @brief	对函数简要描述
 * @param 	参数说明，以’:’作为参数结束标志；
 * @arg
 * 参数里面可选择参量列举，对于可数情况可进行参量列举，同样以’:’作为参数结束标志；
 * @note  	注释，配合brief一起使用可以达到很好的注释效果；
 * @retval	返回值说明。
 */
int main()
{
    double time_temp = 0;

    for (int i = 0; i < 3; i++)
    {
        time_temp = 0;
        start = clock();
        switch (i)
        {
        case 0:
            for (int j = 0; j < LOOP_NUM; j++)
            {
                time_temp += pow(3, EXP_NUM);
            }
            break;
        case 1:
            for (int j = 0; j < LOOP_NUM; j++)
            {
                time_temp += mypow_1(3, EXP_NUM); // 递归实现，浪费空间
            }
            break;
        case 2:
            for (int j = 0; j < LOOP_NUM; j++)
            {
                time_temp += mypow_2(3, EXP_NUM);
            }
            break;
        default:
            break;
        }
        stop = clock();
        printf("%lf\n", time_temp / (double)LOOP_NUM);
        printf("%d: Time taken: %lf/LOOP_NUM seconds\n", i, (double)(stop - start) / CLK_TCK);
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        time_temp = 0;
        start = clock();
        switch (i)
        {
        case 0:
            for (int j = 0; j < LOOP_NUM; j++)
            {
                time_temp += my_polynomial_1(7, myarry, 3);
            }
            break;
        case 1:
            for (int j = 0; j < LOOP_NUM; j++)
            {
                time_temp += my_polynomial_2(7, myarry, 3);
            }
            break;
        case 2:
            for (int j = 0; j < LOOP_NUM; j++)
            {
                time_temp += my_polynomial_3(7, myarry, 3);
            }
            break;
        default:
            break;
        }
        stop = clock();
        printf("%lf\n", time_temp / (double)LOOP_NUM);
        printf("%d: Time taken: %lf/LOOP_NUM seconds\n", i, (double)(stop - start) / CLK_TCK);
    }

    while (1)
    {
    }

    return 0;
}
