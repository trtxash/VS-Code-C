/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.5
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025年3月4号18点15分
 */

#include <iostream>
#include <limits>
#include <cctype>
#include <vector>

// cctype功能
// 判断字符是否属于特定类别（如字母、数字等）。
// isalpha(c) // 是否为字母 (a-z, A-Z)
// isdigit(c) // 是否为数字 (0-9)
// isalnum(c) // 是否为字母或数字
// isspace(c) // 是否为空白字符（空格、换行符、制表符等）
// islower(c) // 是否小写字母
// isupper(c) // 是否大写字母
// tolower(c)  // 转小写（若原为大写）
// toupper(c)  // 转大写（若原为小写）

using namespace std;

bool IntNumberDateInput(int &value, int min, int max);
bool FloatNumberDateInput(float &value, float min, float max);

int main()
{
    int task_num = 0;

    while (1)
    {
        int temp = 0;
        string str_task1;
        char ch_task1 = 0;
        vector<float> vec_task2;

        cout << "Enter task number: ";
        if (IntNumberDateInput(task_num, 1, 9))
        {
            switch (task_num) // switch语句里不能定义变量，因分支共用变量
            {
            case 1:
                cout << "Enter a string, terminated by '@' " << endl;
                cin >> str_task1;
                for (int i = 0; i < str_task1.length(); i++) // check '@'
                {
                    if (str_task1[i] == '@')
                    {
                        temp = 0;
                        break;
                    }
                    else
                    {
                        temp = 1;
                    }
                }
                if (temp == 1)
                {
                    cout << "The string does not contain '@' " << endl;
                }
                else // 有@
                {
                    while (str_task1[temp] != '@')
                    {
                        ch_task1 = str_task1[temp++];
                        if (isdigit(ch_task1))
                        {
                        }
                        else if (isalpha(ch_task1)) // 字母就大小写颠倒输出
                        {
                            if (islower(ch_task1)) // 小写就转大写
                            {
                                ch_task1 = toupper(ch_task1);
                            }
                            else
                            {
                                ch_task1 = tolower(ch_task1);
                            }
                            cout << ch_task1;
                        }
                        else if (isspace(ch_task1))
                        {
                            cout << " ";
                        }
                        else
                        {
                            cout << ch_task1;
                        }
                    }
                    cout << endl;
                }
                temp = ch_task1 = 0;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                cout << "no task : " << task_num << endl;
                break;
            }
        }
        else
        {
        }
    }

    return 0;
}

// 输入验证可以封装成函数
bool IntNumberDateInput(int &value, int min, int max)
{
    if (!(cin >> value))
    {
        // 处理类型错误...
        cout << "Invalid task number format. Please enter a valid task number." << endl;
        cin.clear();                                         // 必须先清除错误状态
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值}
        return false;
    }
    if (value < min || value > max)
    {
        // 处理范围错误...
        cout << "Invalid task number range. Please enter a valid task number." << endl;
        cin.clear();                                         // 必须先清除错误状态
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值}
        return false;
    }
    // 读取成功，清空缓冲区,防止getline()读取到换行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值}

    return true;
}

bool FloatNumberDateInput(float &value, float min, float max)
{
    if (!(cin >> value))
    {
        // 处理类型错误...
        cout << "Invalid task number format. Please enter a valid task number." << endl;
        cin.clear();                                         // 必须先清除错误状态
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值}
        return false;
    }
    if (value < min || value > max)
    {
        // 处理范围错误...
        cout << "Invalid task number range. Please enter a valid task number." << endl;
        cin.clear();                                         // 必须先清除错误状态
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值}
        return false;
    }
    // 读取成功，清空缓冲区,防止getline()读取到换行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值}

    return true;
}