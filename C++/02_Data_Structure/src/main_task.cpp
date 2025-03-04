/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.3 and Ch.4
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025年3月4号18点15分
 */

#include <iostream>
#include <cstring> // task2
#include <limits>
#include <vector>
#include <array>
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

bool IntNumberDateInput(int &value, int min, int max);
bool FloatNumberDateInput(float &value, float min, float max);

int main()
{
    int task_num = 0;

    while (1)
    {
        cout << "Enter task number: ";
        if (IntNumberDateInput(task_num, 1, 9))
        {
            string name_first, name_last, name_temp, dessert_temp;
            char name_first_char[16], name_last_char[16], name_temp_char[32];
            Pizza *pizza_tmep = new Pizza;          // task7
            CandyBar *apple_temp = new CandyBar[3]; // task8,动态创建数组，注意格式
            vector<float> V1;                       // task9,动态创建vector，注意格式(堆)
            array<float, 3> A1;                     // task9,静态创造array，注意格式(栈)
            float temp_task9;
            int run_times;

            switch (task_num) // switch语句里不能定义变量，因分支共用变量
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
                cout << "Pizza Brand: ";
                cin >> pizza.brand;
                cout << "Pizza Diameter: ";
                cin >> pizza.diameter;
                cout << "Pizza Weight: ";
                cin >> pizza.weight;
                cout << "Pizza Brand:" << pizza.brand << ", Diameter:" << pizza.diameter << ", Weight:" << pizza.weight << endl;
                break;
            case 7:
                // Pizza *pizza_tmep = new Pizza;
                cout << "Pizza Diameter: ";
                cin >> pizza_tmep->diameter;
                cout << "Pizza Brand: ";
                cin >> pizza_tmep->brand;
                cout << "Pizza Weight: ";
                cin >> pizza_tmep->weight;
                cout << "Pizza Brand:" << pizza_tmep->brand << ", Diameter:" << pizza_tmep->diameter << ", Weight:" << pizza_tmep->weight << endl;
                // delete pizza_tmep;
                break;
            case 8:
                apple_temp[0] = {"Fruit Pie", 1.2, 250};
                apple_temp[1] = {"Chocolate Milk", 1.5, 300};
                apple_temp[2] = {"Gingerbread Cookie", 2.0, 400};

                cout << "CandyBar " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << "   Brand: " << apple_temp[i].brand << endl
                         << "       Weight: " << apple_temp[i].weight << endl
                         << "       Calories: " << apple_temp[i].calories << endl;
                }
                break;
            case 9:
                if (V1.empty())
                {
                }
                else // 非空，清空V1
                {
                    V1.clear();
                }

                // Vector
                cout << "(Vector)How many times did you run: ";
                if (IntNumberDateInput(run_times, 0, 100)) // 输入运行次数
                {
                    for (int i = 0; i < run_times; i++)
                    {
                        cout << "Enter your " << i + 1 << "th run: ";
                        if (FloatNumberDateInput(temp_task9, 0, 100))
                        {
                            V1.push_back(temp_task9);
                        }
                        else
                        {
                            i--; // 输入错误，回退到上一个输入，重新输入
                        }
                    }
                    temp_task9 = 0;
                    for (int i = 0; i < V1.size(); i++) // 计算均值和打印
                    {
                        cout << i << "th run: " << V1[i] << endl;
                        temp_task9 += V1[i];
                    }
                    temp_task9 /= V1.size(); // print average
                    cout << "Average: " << temp_task9 << endl;
                }
                else
                {
                }

                // Array
                cout << "(Array)How many times did you run: ";

                for (int i = 0; i < 3; i++)
                {
                    cout << "Enter your " << i + 1 << "th run: ";
                    if (FloatNumberDateInput(temp_task9, 0, 100))
                    {
                        A1[i] = temp_task9;
                    }
                    else
                    {
                        i--; // 输入错误，回退到上一个输入，重新输入
                    }
                }
                temp_task9 = 0;
                for (int i = 0; i < 3; i++) // 计算均值和打印
                {
                    cout << i << "th run: " << A1[i] << endl;
                    temp_task9 += A1[i];
                }
                temp_task9 /= 3; // print average
                cout << "Average: " << temp_task9 << endl;

                break;
            default:
                cout << "no task : " << task_num << endl;
                break;
            }
            delete pizza_tmep;   // task7
            delete[] apple_temp; // task8,动态删除数组，注意格式
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