/**
 * @file	study.h
 * @brief   This file is test file for C++ class.
 * @author  TRTX-gamer
 * @version 0.0.1
 * @date    2025-03-09-00:02
 */
#ifndef __STUDY_H__
#define __STUDY_H__

#include <iostream>
class Student
{
    // 可以省略private关键字，因为默认就是private
private: // 成员变量（属性）
    std::string name_val;
    int age_val;

public: // 成员函数（方法）
    // 构造函数声明
    Student();                     // 用函数重载实现默认构造函数
    Student(std::string n, int a); // 带参数的构造函数
    ~Student() {}                  // 析构函数,声明和定义和构造函数类似，通常可以省略，默认由编译器自动生成（可以自动delete动态申请的内存）

    void introduce()
    {
        std::cout << "我叫" << name_val << "，今年" << age_val << "岁" << std::endl;
    }

    void test_this()
    {
        std::cout << "this指针:" << this << std::endl;
    }

    // 所有不修改对象状态的getter方法都应该声明为const，这能提高代码的：
    // 1 安全性（防止意外修改）
    // 2 可用性（支持const对象使用）
    // 3 可读性（明确方法行为）
    int age() const // const修饰符承诺该方法不会修改Student对象的状态
    {
        return age_val;
    }
};

class Student_1
{
    // 可以省略private关键字，因为默认就是private
private: // 成员变量（属性）
    std::string name_val;
    int age_val;

public: // 成员函数（方法）
    // 构造函数声明

    Student_1() // 类内直接定义默认构造函数
    {
        name_val = "未命名";
        age_val = 0;
    }

    // 带参数的构造函数（使用初始化列表）
    Student_1(std::string n, int a) : name_val(n), age_val(a) {}

    void introduce()
    {
        std::cout << "我叫" << name_val << "，今年" << age_val << "岁" << std::endl;
    }
};

// 默认构造（类外定义）
Student::Student()
{
    name_val = "未命名";
    age_val = 0;
}

// 低效写法（有赋值过程）
// Student::Student(std::string n, int a) {
//     name_val = n; // 这里其实是赋值操作，不是初始化
//     age_val = a;
// }

Student::Student(std::string n, int a) : name_val(n), age_val(a) {} // 带参构造函数，直接初始化列表，比默认构造后幅值更高效
//                                     ↑ 这个冒号开始成员初始化列表

#endif