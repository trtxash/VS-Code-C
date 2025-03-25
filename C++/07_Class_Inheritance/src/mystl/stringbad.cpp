#include "stringbad.h"

StringBad::StringBad() : str(nullptr), len(0) {}

StringBad::StringBad(const char *s) : str(nullptr), len(0) {
  len = std::strlen(s);    // 设置大小
  str = new char[len + 1]; // 分配内存
  // std::strcpy(str, s);     // 拷贝字符串
  strcpy_s(str, len + 1, s); // 安全拷贝字符串
}

StringBad::~StringBad() {
  delete[] str; // 释放内存
}

std::ostream &operator<<(std::ostream &os, const StringBad &s) {
  os << s.str;
  return os;
}