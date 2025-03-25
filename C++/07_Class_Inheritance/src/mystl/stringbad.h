/**
 * @file	stringbad.h
 * @brief   字符串类模板实现，用堆模拟实现字符串
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025-03-25 16:58
 */
#ifndef STRINGBAD_H
#define STRINGBAD_H

#include <iostream>

#ifdef _WIN32
#define MYSTL_EXPORT __declspec(dllexport) // 定义 DLL 接口,windows下使用
#else
#define MYSTL_EXPORT
#endif

class MYSTL_EXPORT StringBad {
private:
  char *str; // 堆内存指针
  int len;   // 字符串长度
             // static int num_strings;
public:
  StringBad(); // 默认构造函数
  StringBad(const char *s);
  ~StringBad();

  /* 重载运算符 */

  /* 友元函数 */
  friend MYSTL_EXPORT std::ostream &operator<<(std::ostream &os,
                                               const StringBad &s);
};

#endif