/**
 * @file	mymath.c
 * @brief
 * @author 	trtxash
 * @version 0.0.1
 * @date 	2025-05-19 13:11
 */
#include "mymath.h"
#include <math.h>

/**
 * @brief	递归计算x的y次方，较快但浪费空间且不能处理浮点数,且n不能为0
 * @param 	参数说明，以’:’作为参数结束标志；
 * @arg
 * 参数里面可选择参量列举，对于可数情况可进行参量列举，同样以’:’作为参数结束标志；
 * @note  	注释，配合brief一起使用可以达到很好的注释效果；
 * @retval	返回值说明。
 */
int mypow_1(int x, int y)
{
    if (y == 1)
        return x;
    int result = 0;
    int tmp = mypow_1(x, y / 2);
    if ((y & 1) != 0) // 奇数
    {
        result = x * tmp * tmp;
    }
    else
    {
        result = tmp * tmp;
    }

    return result;
}

/**
 * @brief	循环计算x的y次方，比math快但指数不能为浮点数
 * @param 	参数说明，以’:’作为参数结束标志；
 * @arg
 * 参数里面可选择参量列举，对于可数情况可进行参量列举，同样以’:’作为参数结束标志；
 * @note  	注释，配合brief一起使用可以达到很好的注释效果；
 * @retval	返回值说明。
 */
double mypow_2(double base, int exp)
{
    double result = 1.0;

    while (exp)
    {
        if (exp % 2 == 1) // 奇指数
        {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }

    return result;
}

/**
 * @brief	多项式计算，在n点时，多项式的值。pow用math库
 * @param 	a : 多项式系数数组,n+1个元素,0-n
 * @arg
 * 参数里面可选择参量列举，对于可数情况可进行参量列举，同样以’:’作为参数结束标志；
 * @note  	注释，配合brief一起使用可以达到很好的注释效果；
 * @retval	返回值说明。
 */
double my_polynomial_1(int n, double *a, double x)
{
    double result = 0;

    for (int i = 0; i < n + 1; i++)
    {
        result += a[i] * pow(x, i);
    }

    return result;
}

/**
 * @brief	多项式计算，在n点时，多项式的值。pow自己实现
 * @param 	a : 多项式系数数组,n+1个元素,0-n
 * @arg
 * 参数里面可选择参量列举，对于可数情况可进行参量列举，同样以’:’作为参数结束标志；
 * @note  	注释，配合brief一起使用可以达到很好的注释效果；
 * @retval	返回值说明。
 */
double my_polynomial_2(int n, double *a, double x)
{
    double result = 0;

    for (int i = 0; i < n + 1; i++)
    {
        result += a[i] * mypow_2(x, i);
    }

    return result;
}

/**
 * @brief	多项式计算，在n点时，多项式的值。算法优化
 * @param 	a : 多项式系数数组,n+1个元素,0-n
 * @arg
 * 参数里面可选择参量列举，对于可数情况可进行参量列举，同样以’:’作为参数结束标志；
 * @note  	注释，配合brief一起使用可以达到很好的注释效果；
 * @retval	返回值说明。
 */
double my_polynomial_3(int n, double *a, double x)
{
    double result = a[n];

    for (int i = n - 1; i >= 0; i--)
    {
        result = a[i] + x * result;
    }

    return result;
}

/**
 * @brief	折半查找法（二分法）,数据已经排好序
 * @param
 * @arg
 * 参数里面可选择参量列举，对于可数情况可进行参量列举，同样以’:’作为参数结束标志；
 * @note  	最坏时间复杂度O(logn),可优化,见 https://www.cnblogs.com/MinPage/p/14192152.html
 * @retval	返回值说明。
 */
int BinSearch(int arr[], int len, int key)
{
    int low = 0;        // 定义初始最小
    int high = len - 1; // 定义初始最大
    int mid;            // 定义中间值
    while (low <= high)
    {
        // mid=(low+high)/2;//可能会溢出
        mid = low + (high - low) / 2; // 找中间值
        if (key == arr[mid])          // 判断mid与key是否相等
            return mid;
        else if (key > arr[mid]) // 如果key>mid  则新区间为[mid+1,high]
            low = mid + 1;
        else // 如果key<mid  则新区间为[low,mid-1]
            high = mid - 1;
    }
    return -1; // 如果数组中无目标值key，则返回 -1 ；
}