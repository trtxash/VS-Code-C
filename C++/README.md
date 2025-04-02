# VS-Code-C++ 总纲

功能

1. 记下学习那些事

---

## 搭建步骤

### cursor

1. 设置大部分与vscode相同
2. 可选-GCC编译器等，换为LLVM全家桶

---

### LLVM全家桶

1. 安装cmake辅助构建编译，安装cmake tool插件，注:新版cmake tool插件不兼容cmake插件
2. 安装LLVM，内包含clang编译器。安装clangd插件，比C/C++默认代码提示优秀很多
3. 安装ninja，clang默认生成器，也可在cmake指定为其他生成器
4. 设置好LLVM，cmake，ninja环境变量，可运行相应版本cmd命令测试
5. 安装VS build tool，选择C++套件，安装C++ MSVC库
6. 参考[网站](https://www.bilibili.com/video/BV18W421c7Cy)编写cmake，cmake tool选择clang套件，运行configure
7. 设置cmake tool选择套件为clang，如4，5，6没问题，代码提示应正常
8. 设安装codelldb插件，调试功能插件
9. 设置tasks.json，创建顺序执行任务，包含configure和build。设置launch.json，创建LLDB启动任务，预先执行前面的顺序执行任务
10. 测试F5，启动调试

---

> launch.json配置文件  

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "type": "lldb",
            "request": "launch",
            "name": "Debug",
            "program": "${workspaceFolder}/bin/main",
            "args": [],
            "cwd": "${workspaceFolder}",
            "preLaunchTask": "CMake: config and build"
        },
    ]
}
```

---

> task.json配置文件

```json
{
 "version": "2.0.0",
 "tasks": [
  {
   "label": "CMake: config and build",
   "dependsOrder": "sequence", // 按顺序执行
   "dependsOn": [
    "CMake: configure",
    "CMake: build"
   ],
   "group": "build"
  }
 ]
}

```

---

### VScode old

1. VS Code里面安装中文,c++插件
2. 可选 -- 文件->首选项->设置->搜索设置->encoding->Files：Encoding -> gbk;为防止Win下输出中文乱码,应改成当前系统用的编码(VS Code内置终端只能使用UTF-8编码，用内置终端时应改成utf-8);简体系统改成GBK;繁体系统改成BIG5;国际一般UTF-8
3. 下载,安装64位MinGW编译器(64位系统安装选项选x86_64) -- 目前windows下调试仅支持 Cygwin 和 MinGW,看大部分帖子均推荐使用MinGW,版本选择和其他参考:  
[<MinGW-w64的安装详细步骤(c/c++的编译器gcc、g++的windows版，win10、win11真实可用)>](https://blog.csdn.net/qq_44918090/article/details/132190274)  
[<Differences between msvcrt, ucrt and vcruntime libraries>](https://stackoverflow.com/questions/67848972/differences-between-msvcrt-ucrt-and-vcruntime-libraries)  
4. 配置mingw-w64环境变量,找到安装后的路径,找到并打开bin文件夹,复制路径;在桌面找到我的电脑图标->右键->属性->高级系统设置->选择"高级"选项->选择下面"环境变量"->Administrator 的用户变量,在path中新增安装mingw-w64的路径;验证mingw-w64是否安装配置成功,win+r后输入cmd后输入gcc -v,有WinGW-W64字样安装成功
5. 按[<使用 VS Code 搭建轻量美观的 C/C++开发环境>](https://www.bilibili.com/video/BV1sW411v7VZ)修改和了解VS Code的配置文件,附件为自用配置文件
6. 可安装git -- 版本控制,你的代码多版本,方便修改代码,还可一起使用GitHub网站上传下载代码
7. 开启设置同步，妈妈再也不用担心我的设置了

---

> settings.json配置文件

```json
{
    "window.zoomLevel": 0, // 窗口缩放级别
    "files.autoSave": "onFocusChange", // 自动保存
    "editor.tabCompletion": "on", // tab补选
    "C_Cpp.clang_format_sortIncludes": true, // 格式化时调整include的排序
    "files.encoding": "utf8", // 文件默认编码(为防止Win下输出中文乱码，应改成当前系统用的编码(VS Code内置终端只能使用UTF-8编码，用内置终端时应改成utf-8);简体系统改成GBK;繁体系统改成BIG5;国际一般UTF-8)
    "C_Cpp.updateChannel": "Insiders",
    "git.autofetch": true,
    "explorer.confirmDelete": false,
}
```

---

> launch.json配置文件  

```json
{
  /*
  使用 IntelliSense 了解相关属性。 
  悬停以查看现有属性的描述。
  欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
  */
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(gdb) 启动", // 配置名称，将会在启动配置的下拉菜单中显示
      "type": "cppdbg", // 配置类型，cppdbg对应cpptools提供的调试功能；可以认为此处只能是cppdbg
      "request": "launch", // 请求配置类型，可以为launch（启动）或attach（附加）
      "program": "${fileDirname}/${fileBasenameNoExtension}.exe", // 将要进行调试的程序的路径
      "args": [], // 程序调试时传递给程序的命令行参数，一般设为空即可
      "stopAtEntry": false, // 设为true时程序将暂停在程序入口处，相当于在main上打断点
      "cwd": "${workspaceFolder}", // 调试程序时的工作目录，此为工作区文件夹；改成${fileDirname}可变为文件所在目录
      "environment": [], // 环境变量
      "externalConsole": false, // 使用单独的cmd窗口，与其它IDE一致；为false时使用内置终端
      "internalConsoleOptions": "neverOpen", //控制何时打开控制台,我改为了从不打开
      "MIMode": "gdb", // 指定连接的调试器，可以为gdb或lldb。但我没试过lldb
      "miDebuggerPath": "gdb", // 调试器路径，Windows下后缀不能省略，Linux下则不要
      "setupCommands": [
        { // 模板自带，好像可以更好地显示STL容器的内容，具体作用自行Google
          "description": "为 gdb 启用整齐打印",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "C/C++: gcc.exe build active file" // 调试会话开始前执行的任务，一般为编译程序。与tasks.json的label相对应
    }
  ]
}
```

---

> task.json配置文件

```json
{
 "version": "2.0.0",
 "tasks": [
  {
   "type": "cppbuild",
   "label": "C/C++: gcc.exe build active file", // 任务名称，与launch.json的preLaunchTask相对应
   "command": "C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\gcc.exe", // 要使用的编译器，C++用g++
   "args": [
    "-g", // 生成和调试有关的信息
    "${file}",
    "-o", // 指定输出文件名，不加该参数则默认输出a.exe，Linux下默认a.out
    "${fileDirname}\\${fileBasenameNoExtension}.exe",
    // "-Wall", // 开启额外警告
    // "-static-libgcc",     // 静态链接libgcc，一般都会加上
    "-fexec-charset=UTF-8", // 生成的程序使用UTF-8编码；为防止Win下输出中文乱码，应改成当前系统用的编码(VS Code内置终端只能使用UTF-8编码，用内置终端时应改成utf-8)；简体系统改成GBK；繁体系统改成BIG5；国际一般UTF-8；
    // "-std=c11", // 要用的语言标准，根据自己的需要修改。c++可用c++14
   ],
   "options": {
    "cwd": "C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin"
   },
   "problemMatcher": [
    "$gcc"
   ], // 捕捉编译时终端里的报错信息到问题面板中，修改代码后需要重新编译才会再次触发
   "group": "build",
   "detail": "compiler: \"C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\gcc.exe\"" // 任务类型的其他信息
  }
 ]
}
```

---

## 备注

+ [vscode+cmake实战系列】环境搭建与配置](https://www.bilibili.com/video/BV1iH4y157aq)
+ [使用 VS Code 搭建轻量美观的 C/C++开发环境](https://www.bilibili.com/video/BV1sW411v7VZ)
+ [VSCode安装，配置，编译运行C++(详细整理)](https://www.jianshu.com/p/febbf1e975b6)
+ [郝斌C语言自学教程](https://www.bilibili.com/video/BV1os411h77o?p=1)
+ [C 语言教程 | 菜鸟教程](https://www.runoob.com/cprogramming/c-tutorial.html)
+ [登入Github、Git本地上传、Github客户端及Visual Studio Code上传教程](https://blog.csdn.net/qq_29493173/article/details/113092656)
+ [Git分支管理策略](https://www.ruanyifeng.com/blog/2012/07/git.html)

---

2025年2月28号22点33分
