# 数据类型，变量，常量总结

## 数据类型
1. 基本类型
   1. 整数类型
        | 类型           |  存储大小   |                                               值范围 |
        | :------------- | :---------: | ---------------------------------------------------: |
        | char           |   1 字节    |                              -128 到 127 或 0 到 255 |
        | unsigned char  |   1 字节    |                                             0 到 255 |
        | signed char    |   1 字节    |                                          -128 到 127 |
        | int            | 2 或 4 字节 | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647 |
        | unsigned int   | 2 或 4 字节 |                    0 到 65,535 或 0 到 4,294,967,295 |
        | short          |   2 字节    |                                    -32,768 到 32,767 |
        | unsigned short |   2 字节    |                                          0 到 65,535 |
        | long           |   4 字节    |                      -2,147,483,648 到 2,147,483,647 |
        | unsigned long  |   4 字节    |                                   0 到 4,294,967,295 |
        
        可以用
        ```
        #include <stdio.h>
        #include <limits.h>

        int main()
        {
           printf("int 存储大小 : %lu \n", sizeof(int));

           return 0;
        }
        ```
        得到对象或类型的存储字节大小  
        如：
        > int 存储大小 : 4 
   2. 浮点类型
        | 类型        | 存储大小 |         值范围         |      精度 |
        | :---------- | :------: | :--------------------: | --------: |
        | float       |  4 字节  |   1.2E-38 到 3.4E+38   |  6 位小数 |
        | double      |  8 字节  |  2.3E-308 到 1.7E+308  | 15 位小数 |
        | long double | 16 字节  | 3.4E-4932 到 1.1E+4932 | 19 位小数 |
        
        可以用
        ```
        #include <stdio.h>
        #include <float.h>
 
        int main()
        {
           printf("float 存储最大字节数 : %lu \n", sizeof(float));
           printf("float 最小值: %E\n", FLT_MIN );
           printf("float 最大值: %E\n", FLT_MAX );
           printf("精度值: %d\n", FLT_DIG );
   
           return 0;
        }
        ```
        得到输出浮点类型占用的存储空间以及它的范围值
        如：
        > float 存储最大字节数 : 4   
        float 最小值: 1.175494E-38  
        float 最大值: 3.402823E+38  
        精度值: 6

2. 枚举类型
3. void 类型
   1. 函数返回为空
   2. 函数参数为空
   3. 指针指向 void
4. 派生类型

---

### 备注
+ [C 数据类型](https://www.runoob.com/cprogramming/c-data-types.html)

---

2021年2月18日19点48分