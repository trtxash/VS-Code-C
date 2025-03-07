/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.7~ch.8
 * @author 	TRTX-gamer
 * @version 0.0.2
 * @date 	2025年3月7号15点52分
 */

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

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
///////////////////////////////////////////////////////////////////////////////////////////////////
// vecotr功能
// 应避免长期持有vector元素的引用，或在可能改变容量的操作后及时更新引用。
// 应避免长期持有vector元素的引用，或在可能改变容量的操作后及时更新引用。
// 应避免长期持有vector元素的引用，或在可能改变容量的操作后及时更新引用。
// vector<int> vec;                    // 创建一个空的 int 类型 vector
// vector<int> vec2(10);               // 创建一个包含 10 个元素的 vector，默认值为 0
// vector<int> vec3(10, 5);            // 创建一个包含 10 个元素的 vector，每个元素初始化为 5
// vector<int> vec4 = {1, 2, 3, 4, 5}; // 使用初始化列表创建 vector

// vec.push_back(10);               // 在 vector 末尾添加元素 10
// vec.insert(vec.begin() + 2, 20); // 在索引 2 的位置插入元素 20

// int first = vec[0];       // 通过下标访问元素
// int second = vec.at(1);   // 通过 at() 函数访问元素，会进行边界检查
// int last = vec.back();    // 访问最后一个元素
// int first2 = vec.front(); // 访问第一个元素

// vec.pop_back();             // 删除最后一个元素
// vec.erase(vec.begin() + 2); // 删除索引 2 的元素
// vec.clear();                // 清空 vector 中的所有元素

// int size = vec.size();         // 获取 vector 中元素的数量
// int capacity = vec.capacity(); // 获取 vector 的容量（可以存储的元素数量）
// bool isEmpty = vec.empty();    // 判断 vector 是否为空

// vec.resize(15);      // 将 vector 的大小调整为 15，新元素默认值为 0
// vec.resize(20, 100); // 将 vector 的大小调整为 20，新元素初始化为 100

// vec5.swap(vec6); // 交换 vec5 和 vec6 的内容

// vec.assign(5, 10); // 将 vector 的内容替换为 5 个值为 10 的元素
// vec.reserve(100);  // 预分配 100 个元素的空间，避免频繁重新分配内存
struct DataVectorStruct
{
    union DataUnion
    {
        bool b;
        char ch;
        int i;
        float f;
        double d;
    };

    vector<bool> vec_bool;
    vector<char> vec_char;
    vector<int> vec_int;
    vector<float> vec_float;
    vector<double> vec_double;
    vector<string> vec_string;
    vector<DataUnion> vec_union;
};

struct CandyBar // task2
{
    string brand;
    float weight;
    int calories;
};

CandyBar candy1 = {}; // task2

// 结构为：
// -模板
// --隐式实例化
// --显示实例化
// -显示特化

// 隐式实例化：
// 指利用模板，编译器自动生成，完成实例化（也就要有AnyType，否则如果有显式，则不能作为显示的模板）
template <typename Type1, typename Type2, typename Type3> // 变量可以多个
bool NumberInput(Type1 &value, Type2 min, Type3 max);     // 模板，一组template一组声明
// 显式实例化
// 指利用模板，手动声明，完成实例化（也就不能AnyTypepe）
// 建议用显示实例化，因：当隐式实例化时，编译器可能无法确定模板参数，导致编译错误，且
template bool NumberInput(int &value, float min, float max);
template bool NumberInput<float>(float &value, float min, float max); // 指定模板类型为 float，即 Type1、Type2 和 Type3 都会被替换为 float 类型。

// 显示特化：
template <>                                          // 显示特化，指定模板类型为 int
bool NumberInput<int>(int &value, int min, int max); // 指定模板类型为 int (因为函数后面有"<int>")

void task1(string *s, int mode);
void task2(CandyBar &candy, const char *ch = "Millenium Munch", const double d = 2.85, const int i = 350);
void task3(string &s);

/**
 * @brief	对函数简要描述
 * @param 	参数说明，以’:’作为参数结束标志；
 * @arg		参数里面可选择参量列举，对于可数情况可进行参量列举，同样以’:’作为参数结束标志；
 * @note  	注释，配合brief一起使用可以达到很好的注释效果；
 * @retval	返回值说明。
 */
int main()
{
    DataVectorStruct data_vec = {};

    data_vec.vec_int.reserve(10); // 预分配足够空间，避免频繁重新分配内存，确保引用不会因vector扩容失效。
    data_vec.vec_string.reserve(10);

    data_vec.vec_int.push_back(0);
    int &task_num = data_vec.vec_int.back(); // 重命名为任务变量，来自vector结构体的int临时变量

    while (1)
    {
        // int mode_num = 0;
        cout << "Enter task number: ";
        if (NumberInput(task_num, 1, 9))
        {
            switch (task_num) // switch语句里不能定义变量，因分支共用变量,故定义处加大括号，定义在块内
            {
            case 1:
            {
                cout << "Enter mode number: ";
                data_vec.vec_int.push_back(0);
                int &mode_num = data_vec.vec_int.back();
                while (!NumberInput(mode_num, 0, 0))
                    continue; // 输入错误，重新输入

                data_vec.vec_string.push_back("Hello, world!");
                string *s = &data_vec.vec_string.back();
                task1(s, mode_num); // 调用task1函数，打印字符串s多次

                data_vec.vec_int.pop_back(); // 删除临时变量
                data_vec.vec_string.pop_back();
            }
            break;
            case 2:
            {
                task2(candy1);
            }
            break;
            case 3:
            {
                string s = {};
                while (1)
                {
                    cout << "Enter a string: (q to quit)";
                    getline(cin, s);
                    if ((s[0] == 'q' || s[0] == 'Q') && s.size() == 1) // string直接就是“q”或“Q”
                    {
                        cout << "Bye!" << endl;
                        break;
                    }

                    task3(s);
                    cout << s << endl;
                }
            }
            break;
            case 4:
            {
            }
            break;
            case 5:
            {
            }
            break;
            case 6:
            {
            }
            break;
            case 7:
            {
            }
            break;
            case 8:
            {
            }
            break;
            case 9:
            {
            }
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

    data_vec.vec_int.pop_back();
    return 0;
}

/**
 * @brief	任务3的实现
 * @param
 * @arg
 * @note    默认参数写在函数声明处
 * @retval
 */
void task3(string &s)
{
    for (int i = 0; i < s.length(); i++) // sizeof(string)在编译期确定，与字符串内容无关；length()在运行时计算，随字符串长度变化
    {
        if (isalpha(s[i]))
        {
            if (islower(s[i])) // 小写就转大写
            {
                s[i] = toupper(s[i]);
            }
        }
    }
}

/**
 * @brief	任务2的实现
 * @param
 * @arg
 * @note    默认参数写在函数声明处
 * @retval
 */
void task2(CandyBar &candy, const char *ch, const double d, const int i)
{
    candy.brand = ch;
    candy.weight = d;
    candy.calories = i;
    cout << "Brand: " << candy.brand << endl;
    cout << "Weight: " << candy.weight << endl;
    cout << "Calories: " << candy.calories << endl;
}

/**
 * @brief	任务1的实现
 * @param 	s 	    字符串指针
 * @param 	mode 	模式，非零则字符串打印次数为此函数调用次数，否则打印次数为1
 * @arg
 * @note
 * @retval
 */
void task1(string *s, int mode)
{
    static int count = 0;
    count++;
    if (count >= 2147483647)
    {
        count = 0;
    }
    if (mode)
    {
        for (int i = 0; i < count; i++)
        {
            cout << *s << " (" << count << " times)" << endl;
        }
    }
    else
    {
        cout << *s << " (" << count << " times)" << endl;
    }
}

/**
 * @brief	模板函数，读入输入的数据，并进行类型和范围检查，返回是否成功
 * @param 	value 	输入数据
 * @param 	min 	最小值
 * @param 	max 	最大值,都为0则不进行范围检查
 * @arg
 * @note  	只能处理整数、浮点数、布尔型数据类型，其他类型需要自行定义模板函数；
 * @retval	True    成功
 * @retval	False   失败
 */
template <typename Type1, typename Type2, typename Type3>
bool NumberInput(Type1 &value, Type2 min, Type3 max)
{
    if (!(cin >> value))
    {
        // 处理类型错误...
        cout << "Invalid task number format. Please enter a valid task number." << endl;
        cin.clear();              // 必须先清除错误状态
        while (cin.get() != '\n') // 删除没有用的输入
            continue;             // get rid of bad input
        return false;
    }
    if (min == 0 && max == 0) // 不进行范围检查
    {
    }
    else
    {
        if (value < min || value > max)
        {
            // 处理范围错误...
            cout << "Invalid task number range. Please enter a valid task number." << endl;
            cin.clear();              // 必须先清除错误状态
            while (cin.get() != '\n') // 删除没有用的输入
                continue;             // get rid of bad input
            return false;
        }
    }
    while (cin.get() != '\n') // 删除没有用的输入
        continue;             // get rid of bad input
    // // 读取成功，清空缓冲区,防止getline()读取到换行符
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值}

    return true;
}

// bool NumberInput(int &value, int min, int max)
// {
//     if (!(cin >> value))
//     {
//         // 处理类型错误...
//         cout << "Invalid task number format. Please enter a valid task number." << endl;
//         cin.clear();              // 必须先清除错误状态
//         while (cin.get() != '\n') // 删除没有用的输入
//             continue;             // get rid of bad input
//         return false;
//     }
//     if (min == 0 && max == 0) // 不进行范围检查
//     {
//     }
//     else
//     {
//         if (value < min || value > max)
//         {
//             // 处理范围错误...
//             cout << "Invalid task number range. Please enter a valid task number." << endl;
//             cin.clear();              // 必须先清除错误状态
//             while (cin.get() != '\n') // 删除没有用的输入
//                 continue;             // get rid of bad input
//             return false;
//         }
//     }
//     while (cin.get() != '\n') // 删除没有用的输入
//         continue;             // get rid of bad input
//     // // 读取成功，清空缓冲区,防止getline()读取到换行符
//     // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 表示流的最大可能长度（通常是2^63-1）彻底地清除输入缓冲区的残留内容,不同系统的输入缓冲区最大值可能不同，使用标准库方法无需硬编码数值}

//     return true;
// }