### 1. **隐式实例化（Implicit Instantiation）**

- **定义**：编译器根据代码中模板的使用情况，自动生成特定类型的模板实例。
- **特点**：无需手动声明，由编译器按需生成。
- **示例**：

  ```cpp
  template <typename T>
  void print(T value) { cout << value; }

  int main() {
    print(10);       // 隐式实例化 print<int>
    print("hello");  // 隐式实例化 print<const char*>
  }
  ```

---

### 2. **显式实例化（Explicit Instantiation）**

- **定义**：程序员主动指示编译器生成某个特定类型的模板实例。
- **作用**：减少编译时间（避免重复实例化），或控制代码生成位置。
- **示例**：

  ```cpp
  template <typename T>
  void print(T value) { /* ... */ }

  // 显式实例化声明
  template void print<int>(int);    // 生成 int 版本的 print
  template void print<double>(double); // 生成 double 版本的 print
  ```

---

### 3. **显式特化（Explicit Specialization，常误称“显示具体化”）**

- **定义**：为特定类型提供完全独立的模板实现，覆盖通用模板。
- **特点**：针对特殊类型优化行为，语法需用 `template<>`。
- **示例**：

  ```cpp
  template <typename T>
  void print(T value) { cout << "Generic: " << value; }

  // 显式特化 int 版本
  template<>
  void print<int>(int value) { 
    cout << "Specialized int: " << value; 
  }

  int main() {
    print(10);   // 调用特化版本，输出 "Specialized int: 10"
    print(3.14); // 调用通用模板，输出 "Generic: 3.14"
  }
  ```

---

### 关键区别

| **概念**         | **行为**                             | **语法**                     |
|------------------|--------------------------------------|-----------------------------|
| 隐式实例化       | 编译器自动生成实例                   | 自动推断类型（如 `print(10)`） |
| 显式实例化       | 手动要求编译器生成实例               | `template void func<int>()`  |
| 显式特化         | 为特定类型提供完全不同的实现         | `template<> void func<int>()` |

---

### 总结

- **隐式 vs 显式实例化**：前者由编译器自动完成，后者需手动声明。
- **显式实例化 vs 显式特化**：实例化生成通用模板的代码，特化则提供完全不同的实现。
- 术语纠正：“显示具体化”应为 **显式特化**，需注意用词准确性。

#### 其他注意事项

- 应避免长期持有vector元素的引用，或在可能改变容量的操作后及时更新引用。
- switch语句里不能定义变量，因分支共用变量,故定义处加大括号，定义在块内
