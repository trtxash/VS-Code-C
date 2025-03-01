/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.1
 * @author 	trtxash
 * @version 0.0.1
 * @date 	2025年3月1号18点54分
 */

#include <iostream>
using namespace std;

void task3_1()
{
    cout << "Three blind mice" << endl;
}

void task3_2()
{
    cout << "See how they run" << endl;
    cout << "See how they run" << endl;
}

void task5_1()
{
    cout << "Please enter a Celsius vlaue:";
    double celsius;
    cin >> celsius;
    double fahrenheit = (celsius * 1.8) + 32;
    cout << celsius << " degrees Celsius is equal to " << fahrenheit << " degrees Fahrenheit." << endl;
}

int main()
{
    while (1)
    {
        cout << "Enter task number: " << endl;
        int task_num;
        cin >> task_num;

        switch (task_num)
        {
        case 1:
            cout << "My name is trtxash,and I live in China." << endl; // Task 1 code here
            break;
        case 2:
            cout << "Enter a number." << endl; // Task 2 code here
            int num_temp;
            cin >> num_temp;
            cout << num_temp * 220 << endl;
            break;
        case 3:
            task3_1(); // Task 3 code here2
            task3_1();
            task3_2();
            break;
        case 4:
            cout << "Enter your age :"; // Task 4 code here
            int age;
            cin >> age;
            cout << "You are " << age << " years old," << 12 * age << " months old." << endl;
            break;
        case 5:
            task5_1(); // Task 5 code here
            break;
        case 6:
            cout << "不写了，累了" << endl;
            break;
        case 7:
            cout << "不写了，累了" << endl;
            break;
        default:
            cout << "Invalid task number. Please enter a valid task number." << endl;
            break;
        }
    }

    return 0;
}