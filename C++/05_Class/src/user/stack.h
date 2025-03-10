/**
 * @file	stack.h
 * @brief   栈类模板实现，用链表，利用堆模拟实现栈
 * @author 	TRTX-gamer
 * @version 0.0.1
 * @date 	2025-03-10-16:58
 */
#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack
{
private:
    struct Node // 栈节点
    {
        T data;                                              // 数据
        Node *next;                                          // 指向下一个节点的指针，链表结构
        Node(const T &value) : data(value), next(nullptr) {} // 构造函数，nullptr表示空指针常量，替代传统的NULL宏
    };

    Node *topNode;    // 栈顶节点
    size_t stackSize; // 栈大小

public:
    // 构造函数
    Stack() : topNode(nullptr), stackSize(0) {}

    // 拷贝构造函数
    Stack(const Stack &other) : topNode(nullptr), stackSize(0)
    {
        Node *curr = other.topNode;
        Node *last = nullptr;
        while (curr)
        {
            Node *newNode = new Node(curr->data);
            if (!topNode)
                topNode = newNode;
            if (last)
                last->next = newNode;
            last = newNode;
            curr = curr->next;
            stackSize++;
        }
    }

    // 赋值运算符
    Stack &operator=(const Stack &other)
    {
        if (this != &other)
        {
            Stack tmp(other);
            swap(tmp);
        }
        return *this;
    }

    // 析构函数，释放内存
    ~Stack()
    {
        while (!empty())
        {
            pop();
        }
    }

    // 交换函数
    void swap(Stack &other) noexcept
    {
        using std::swap;
        swap(topNode, other.topNode);
        swap(stackSize, other.stackSize);
    }

    // 压栈
    void push(const T &value)
    {
        Node *newNode = new Node(value);
        newNode->next = topNode; // 新节点的下一个节点指向原栈顶节点（这里的next可能指压下的下？）
        topNode = newNode;       // 栈顶节点指向新节点，栈顶元素变为新元素，这两行模拟原topNode被压下
        stackSize++;
    }

    // 弹栈
    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
    }

    // 查看栈顶元素
    T &top()
    {
        if (empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return topNode->data;
    }

    // 常函数版本
    const T &top() const
    {
        if (empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return topNode->data;
    }

    // 判空
    bool empty() const noexcept
    {
        return topNode == nullptr;
    }

    // 获取大小
    size_t size() const noexcept
    {
        return stackSize;
    }
};

#endif // STACK_H
