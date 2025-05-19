/**
 * @file	Basic C++ Program
 * @brief   C++ Primer Plus Ch.9~ch.10
 * @author 	TRTX-gamer
 * @version 0.0.2
 * @date 	2025-03-10-07:13
 */

#include <iostream>
#include <vector>
#include "study.h"
#include "stack.h"

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

    std::vector<bool> vec_bool;
    std::vector<char> vec_char;
    std::vector<int> vec_int;
    std::vector<float> vec_float;
    std::vector<double> vec_double;
    std::vector<std::string> vec_string;
    std::vector<DataUnion> vec_union;
};

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
template bool NumberInput<float, float, float>(float &value, float min, float max); // 指定模板类型为 float，即 Type1、Type2 和 Type3 都会被替换为 float 类型。

// 显示特化：
template <>                                                    // 显示特化，指定模板类型为 int
bool NumberInput<int, int, int>(int &value, int min, int max); // 指定模板类型为 int (因为函数后面有"<int>")

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
        std::cout << "Enter task number: ";
        if (NumberInput(task_num, 1, 9))
        {
            switch (task_num) // switch语句里不能定义变量，因分支共用变量,故定义处加大括号，定义在块内
            {
            case 1:
            {
                Student student1; // 默认初始化
                // std::cout << "student1: " << student1.name << " " << student1.age << std::endl; //报错，类的私有成员不能直接访问
                student1.introduce();
                Student student2 = {"Tom", 20}; // 自定义列表初始化
                student2.introduce();
                student1.test_this();

                Student_1 student3;
                student1.introduce();
                Student_1 student4{"Tom1", 20}; // 另一种写法
                student2.introduce();
            }
            break;
            case 2:
            {
                Stack<int> stack1; // 默认初始化
                stack1.push(10);
                stack1.push(20);
            }
            break;
            case 3:
            {
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
                std::cout << "no task : " << task_num << std::endl;
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
    // 处理类型错误...
    if (!(std::cin >> value))
    {

        std::cout << "Invalid task number format. Please enter a valid task number." << std::endl;
        std::cin.clear();              // 必须先清除错误状态
        while (std::cin.get() != '\n') // 删除没有用的输入
            continue;                  // get rid of bad input
        return false;
    }
    // 不进行范围检查
    if (min == 0 && max == 0)
    {
    }
    else
    {
        if (value < min || value > max)
        {
            // 处理范围错误...
            std::cout << "Invalid task number range. Please enter a valid task number." << std::endl;
            std::cin.clear();              // 必须先清除错误状态
            while (std::cin.get() != '\n') // 删除没有用的输入
                continue;                  // get rid of bad input
            return false;
        }
    }
    // 删除没有用的输入
    while (std::cin.get() != '\n')
        continue; // get rid of bad input

    return true;
}

/**
 * @brief	模板函数，读入输入的数据，并进行类型和范围检查，返回是否成功
 * @param 	value 	输入数据
 * @param 	min 	最小值
 * @param 	max 	最大值,都为0则不进行范围检查
 * @arg
 * @note  	只能处理整数类型
 * @retval	True    成功
 * @retval	False   失败
 */
template <> // 模板和函数重载不一样，删去这两行变为函数重载会报错
bool NumberInput<int, int, int>(int &value, int min, int max)
{
    // 处理类型错误...
    if (!(std::cin >> value))
    {

        std::cout << "Invalid task number format. Please enter a valid task number." << std::endl;
        std::cin.clear();              // 必须先清除错误状态
        while (std::cin.get() != '\n') // 删除没有用的输入
            continue;                  // get rid of bad input
        return false;
    }
    // 不进行范围检查
    if (min == 0 && max == 0)
    {
    }
    else
    {
        if (value < min || value > max)
        {
            // 处理范围错误...
            std::cout << "Invalid task number range. Please enter a valid task number." << std::endl;
            std::cin.clear();              // 必须先清除错误状态
            while (std::cin.get() != '\n') // 删除没有用的输入
                continue;                  // get rid of bad input
            return false;
        }
    }
    // 删除没有用的输入
    while (std::cin.get() != '\n')
        continue; // get rid of bad input

    return true;
}