/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.7~ch.8
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025年3月5号1点42分
 */

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// vecotr
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

template <typename AnyType>
bool DateInput(AnyType &value, AnyType min, AnyType max);

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

    data_vec.vec_int.push_back(0);
    int &task_num = data_vec.vec_int.at(0); // 重命名为任务变量，来自vector结构体的int临时变量

    while (1)
    {
        cout << "Enter task number: ";
        if (DateInput(task_num, 1, 9))
        {
            switch (task_num) // switch语句里不能定义变量，因分支共用变量
            {
            case 1:
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

/**
 * @brief	模板函数，读入输入的数据，并进行类型和范围检查，返回是否成功
 * @param 	value 	输入数据
 * @param 	min 	最小值
 * @param 	max 	最大值
 * @arg
 * @note  	只能处理整数、浮点数、布尔型数据类型，其他类型需要自行定义模板函数；
 * @retval	True    成功
 * @retval	False   失败
 */
template <typename AnyType>
bool DateInput(AnyType &value, AnyType min, AnyType max)
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