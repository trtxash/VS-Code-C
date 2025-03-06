/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.5~ch.6
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025年3月5号1点42分
 */

#include <iostream>
#include <limits>
#include <cctype>
#include <vector>
#include <fstream> // task3，相关函数直接问AI，太多了不写
#include <ctime>   // task3

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
        // ofstream file("test.txt");
        fstream file_task3; // 双向文件流（读写文件）

        int temp_int = 0;
        float temp_float = 0;
        double temp_double = 0;
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
                        temp_int = 0;
                        break;
                    }
                    else
                    {
                        temp_int = 1;
                    }
                }
                if (temp_int == 1)
                {
                    cout << "The string does not contain '@' " << endl;
                }
                else // 有@
                {
                    while (str_task1[temp_int] != '@')
                    {
                        ch_task1 = str_task1[temp_int++];
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
                temp_int = ch_task1 = 0;
                break;
            case 2:
                cout << "(Vector)How many numbers do you want to enter: ";
                if (IntNumberDateInput(temp_int, 1, 10)) // 输入运行次数
                {
                    for (int i = 0; i < temp_int; i++)
                    {
                        cout << "Enter your " << i + 1 << "th number: ";
                        if (FloatNumberDateInput(temp_float, 0, 100))
                        {
                            vec_task2.push_back(temp_float);
                        }
                        else
                        {
                            i--; // 输入错误，回退到上一个输入，重新输入
                        }
                    }
                    temp_double = 0;
                    for (int i = 0; i < vec_task2.size(); i++) // 计算均值和打印
                    {
                        cout << i << "th number: " << vec_task2[i] << endl;
                        temp_double += vec_task2[i];
                    }
                    temp_double /= vec_task2.size(); // print average
                    cout << "Average: " << temp_double << endl;
                }
                else
                {
                }
                temp_float = temp_int = temp_double = 0;
                break;
            case 3:
                srand(time(NULL));                     // 随机数种子，保证每次运行都不一样
                file_task3.open("test.txt", ios::out); // 打开文件,模式写,文件不存在则创建，读写不会创建文件
                // file_task3.open("test.txt", ios::out | ios::in); // 打开文件,模式读写
                if (!file_task3.is_open())
                {
                    exit(EXIT_FAILURE); // 文件打开失败
                }
                else
                {
                    // 写入文件,i行（1~100），j列（1~i），随机数字和字母
                    // 生成随机数字或字母
                    char random_char;
                    temp_int = 0;

                    for (int i = 1; i <= 100; i++)
                    {
                        for (int j = 1; j <= i; j++)
                        {
                            temp_int++;
                            int random_type = rand() % 3; // 0: 数字, 1: 大写字母, 2: 小写字母

                            switch (random_type)
                            {
                            case 0:
                                random_char = '0' + rand() % 10; // 生成随机数字
                                break;
                            case 1:
                                random_char = 'A' + rand() % 26; // 生成随机大写字母
                                break;
                            case 2:
                                random_char = 'a' + rand() % 26; // 生成随机小写字母
                                break;
                            default:
                                random_char = ' '; // 默认情况
                                break;
                            }
                            file_task3 << random_char;
                        }
                        file_task3 << endl; // 每行结束后换行
                    }
                    cout << temp_int << " random numbers and letters generated and saved to file." << endl;

                    temp_int = 0;
                    file_task3.close(); // 关闭文件
                    if (file_task3.is_open())
                        exit(EXIT_FAILURE); // 文件关闭失败

                    file_task3.open("test.txt", ios::out | ios::in); // 打开文件,模式读写
                    if (!file_task3.is_open())
                        exit(EXIT_FAILURE); // 文件打开失败
                    // file_task3.seekg(0, ios::beg); // 回到文件开头，打开文件会自动定位到文件开头
                    while (!file_task3.eof()) // 循环读取文件内容
                    {
                        file_task3.get(random_char); // 读取一个字符
                        cout << random_char;
                        if (random_char != '\n')
                            temp_int++;
                    }
                    cout << temp_int << " random numbers checked from file." << endl;
                }
                file_task3.close(); // 关闭文件
                if (file_task3.is_open())
                {
                    exit(EXIT_FAILURE); // 文件关闭失败
                }
                temp_float = temp_int = temp_double = 0;
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