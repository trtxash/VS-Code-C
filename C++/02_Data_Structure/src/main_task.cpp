/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.1
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025年3月1号18点54分
 */

#include <iostream>
using namespace std;

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
            cout << "Invalid task number. Please enter a valid task number." << endl;
            break;
        }
    }

    return 0;
}