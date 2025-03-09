/**
 * @file	study.h
 * @brief   This file is test file for C++ class.
 * @author  TRTX-gamer
 * @version 1.00
 * @date    2025-03-09-00:02
 */
#ifndef __STUDY_H__
#define __STUDY_H__

#include <iostream>
class Student
{
    // 可以省略private关键字，因为默认就是private
private: // 成员变量（属性）
    std::string name;
    int age;

public: // 成员函数（方法）
    // 构造函数声明
    Student();                     // 用函数重载实现默认构造函数
    Student(std::string n, int a); // 带参数的构造函数

    ~Student() {} // 析构函数,声明和定义和构造函数类似，通常可以省略，默认由编译器自动生成（可以自动delete动态申请的内存）

    void introduce()
    {
        std::cout << "我叫" << name << "，今年" << age << "岁" << std::endl;
    }
};

class Student_1
{
    // 可以省略private关键字，因为默认就是private
private: // 成员变量（属性）
    std::string name;
    int age;

public: // 成员函数（方法）
    // 构造函数声明

    Student_1() // 类内直接定义默认构造函数
    {
        name = "未命名";
        age = 0;
    }

    // 带参数的构造函数（使用初始化列表）
    Student_1(std::string n, int a) : name(n), age(a) {}

    void introduce()
    {
        std::cout << "我叫" << name << "，今年" << age << "岁" << std::endl;
    }
};

// 默认构造（类外定义）
Student::Student()
{
    name = "未命名";
    age = 0;
}

// 低效写法（有赋值过程）
// Student::Student(std::string n, int a) {
//     name = n; // 这里其实是赋值操作，不是初始化
//     age = a;
// }

Student::Student(std::string n, int a) : name(n), age(a) {} // 带参构造函数，直接初始化列表，比默认构造后幅值更高效
//                                     ↑ 这个冒号开始成员初始化列表

#endif