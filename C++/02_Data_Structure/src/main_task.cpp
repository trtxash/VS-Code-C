/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.3 and Ch.4
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025年3月1号18点54分
 */

#include <iostream>
#include <cstring> // task2
#include <limits>
using namespace std;

struct CandyBar
{
    string brand;
    float weight;
    int calories;
};

struct Pizza
{
    string brand;
    float diameter;
    float weight;
};

CandyBar snack{"Mocha Munch", 2.3, 350}; // task4
CandyBar apple[3] = {
    {"Fruit Pie", 1.2, 250},
    {"Chocolate Milk", 1.5, 300},
    {"Gingerbread Cookie", 2.0, 400}}; // task5
Pizza pizza;                           // task6

bool NumberDateInput(int &value, int min, int max);

int main()
{
    int task_num = 0;
    while (1)
    {
        cout << "Enter task number: ";
        if (NumberDateInput(task_num, 1, 16))
        {
            string name_first, name_last, name_temp, dessert_temp;
            char name_first_char[16], name_last_char[16], name_temp_char[32];
            switch (task_num)
            {
            case 1:
                cout << "Enter your name: " << endl;
                cin >> name_temp; // valid,会自动逃过缓冲区第一个回车符
                cout << "Enter your favorite dessert: " << endl;
                getline(cin, dessert_temp); // valid，but a problem with getline() 不会跳过第一个回车符
                cout << "I have some delicious" << dessert_temp << " for you, " << name_temp << "!" << endl;
                break;
            case 2:
                cout << "Enter your first name: ";
                cin >> name_first_char;
                cout << "Enter your last name: ";
                cin >> name_last_char;
                strcpy(name_temp_char, name_last_char);
                strcat(name_temp_char, ", ");
                strcat(name_temp_char, name_first_char);
                cout << "Here's the information in the single string:" << name_temp_char << endl;
                break;
            case 3:
                cout << "Enter your first name: ";
                cin >> name_first;
                cout << "Enter your last name: ";
                cin >> name_last;
                name_temp = name_last + ", " + name_first;
                cout << "Here's the information in the single string:" << name_temp << endl;
                break;
            case 4:
                cout << "CandyBar \n"
                     << "Brand: " << snack.brand << endl
                     << "Weight: " << snack.weight << endl
                     << "Calories: " << snack.calories << endl;
                break;
            case 5:
                cout << "CandyBar " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << "   Brand: " << apple[i].brand << endl
                         << "       Weight: " << apple[i].weight << endl
                         << "       Calories: " << apple[i].calories << endl;
                }
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
bool NumberDateInput(int &value, int min, int max)
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
