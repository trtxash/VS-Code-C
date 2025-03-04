/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.3 and Ch.4
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025年3月1号18点54分
 */

#include <iostream>
#include <limits>
using namespace std;

bool validateInput(int &value, int min, int max);

int main()
{
    int task_num = 9;
    while (1)
    {
        cout << "Enter task number: " << endl;
        if (validateInput(task_num, 1, 5))
        {
            switch (task_num)
            {
            case 1:
                // Task 1 code here
                break;
            case 2:
                // Task 2 code here
                break;
            case 3:
                // Task 3 code here
                break;
            case 4:
                // Task 4 code here
                break;
            case 5:
                // Task 5 code here
                break;
            default:
                cout << "Invalid task number:" << task_num << ". Please enter a valid task number." << endl;
                break;
            }
        }
        else
        {
            cout << "Invalid task number. Please enter a valid task number." << endl;
            cin.clear();                                         // 必须先清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值
        }
    }

    return 0;
}

// 输入验证可以封装成函数
bool validateInput(int &value, int min, int max)
{
    if (!(cin >> value))
    {
        // 处理类型错误...
        return false;
    }
    if (value < min || value > max)
    {
        // 处理范围错误...
        return false;
    }
    return true;
}
