结合具体代码来解释图片中的内容，并展示 `shared_ptr` 的定义、使用和相关操作的效果。

### 1. **`shared_ptr<T> p(q)`**
这个方法的功能是：用内置指针 `q` 初始化 `shared_ptr`，`shared_ptr` 将接管 `q` 所指向的对象的所有权，自动管理对象的生命周期。

#### 示例代码：
```cpp
#include <iostream>
#include <memory>  // 包含 shared_ptr 头文件

int main() {
    int* q = new int(42);  // 动态分配一个 int 值为 42
    std::shared_ptr<int> p(q);  // p 接管 q 所指向的对象

    std::cout << "p 所指的值: " << *p << std::endl;  // 输出 42

    // 当 p 离开作用域时，q 所指向的内存会被释放
    return 0;
}
```

#### 解释：
- `int* q = new int(42);`：`q` 是一个动态分配的指针，指向值为 42 的内存。
- `std::shared_ptr<int> p(q);`：使用内置指针 `q` 来初始化 `shared_ptr p`。现在，`p` 接管了 `q` 所指向的内存，当 `p` 不再被使用时，会自动释放 `q` 所指向的内存（不再需要手动 `delete q`）。
- `p` 离开作用域时，会自动释放内存。

### 2. **`shared_ptr<T> p(u)`**
这个方法用于将一个 `unique_ptr` 的所有权转移给 `shared_ptr`，并使 `unique_ptr` 变为空。

#### 示例代码：
```cpp
#include <iostream>
#include <memory>  // 包含 shared_ptr 和 unique_ptr 头文件

int main() {
    std::unique_ptr<int> u = std::make_unique<int>(100);  // 使用 unique_ptr 管理动态分配的 int
    std::shared_ptr<int> p(std::move(u));  // 将 u 的所有权转移给 p

    std::cout << "p 所指的值: " << *p << std::endl;  // 输出 100
    if (!u) {
        std::cout << "u 现在为空。" << std::endl;  // u 已经为空
    }

    return 0;
}
```

#### 解释：
- `std::unique_ptr<int> u = std::make_unique<int>(100);`：使用 `unique_ptr` 管理动态分配的内存，`u` 是独占所有权。
- `std::shared_ptr<int> p(std::move(u));`：将 `unique_ptr u` 的所有权转移给 `shared_ptr p`。`u` 现在为空，`p` 接管了原来 `u` 所指向的内存，`shared_ptr` 具有共享所有权。
- 当 `p` 不再被引用时，会自动释放内存，避免手动管理内存的麻烦。

### 3. **`shared_ptr<T> p(q, d)`**
这个方法允许 `shared_ptr` 使用自定义删除器来释放内存，而不是默认的 `delete`。

#### 示例代码：
```cpp
#include <iostream>
#include <memory>  // 包含 shared_ptr 头文件

// 自定义删除器，输出一条消息，并释放内存
void custom_deleter(int* p) {
    std::cout << "调用自定义删除器，释放内存。" << std::endl;
    delete p;
}

int main() {
    int* q = new int(42);  // 动态分配一个 int 值为 42
    std::shared_ptr<int> p(q, custom_deleter);  // 使用自定义删除器

    std::cout << "p 所指的值: " << *p << std::endl;  // 输出 42

    // 当 p 离开作用域时，调用 custom_deleter 来释放内存
    return 0;
}
```

#### 解释：
- `int* q = new int(42);`：动态分配一个内存，存储值为 42。
- `std::shared_ptr<int> p(q, custom_deleter);`：使用自定义删除器 `custom_deleter` 来代替默认的 `delete`，当 `p` 不再被引用时，`custom_deleter` 将被调用以释放内存。
- `custom_deleter` 会在 `p` 被销毁时被调用，并输出 "调用自定义删除器，释放内存。" 的信息。

### 4. **`p.reset()`**
`reset()` 方法可以用来释放当前对象并将 `shared_ptr` 置为空。

#### 示例代码：
```cpp
#include <iostream>
#include <memory>  // 包含 shared_ptr 头文件

int main() {
    auto p = std::make_shared<int>(42);  // 创建 shared_ptr，指向 42
    std::cout << "p 所指的值: " << *p << std::endl;  // 输出 42

    p.reset();  // 释放 p 所指的对象，并将 p 置为空
    if (!p) {
        std::cout << "p 现在为空。" << std::endl;  // 输出 p 为空
    }

    return 0;
}
```

#### 解释：
- `p` 是一个 `shared_ptr`，指向值为 42 的动态分配内存。
- `p.reset();`：调用 `reset()` 方法后，`p` 释放它所指的内存，并将 `p` 置为空。
- `!p` 表示 `p` 不再指向任何对象。

### 5. **`p.reset(q)`**
`reset(q)` 方法用于重置 `shared_ptr`，使它指向新的对象，并释放它原本管理的内存。

#### 示例代码：
```cpp
#include <iostream>
#include <memory>  // 包含 shared_ptr 头文件

int main() {
    auto p = std::make_shared<int>(42);  // 创建 shared_ptr，指向 42
    std::cout << "p 所指的值: " << *p << std::endl;  // 输出 42

    p.reset(new int(100));  // 将 p 重置为指向一个新的 int 值为 100
    std::cout << "p 现在指向的值: " << *p << std::endl;  // 输出 100

    return 0;
}
```

#### 解释：
- `p` 最初指向值为 42 的动态内存。
- `p.reset(new int(100));`：重置 `p`，现在 `p` 指向新的动态分配的内存，值为 100，原来的值 42 的内存会自动被释放。

### 6. **`p.reset(q, d)`**
`reset(q, d)` 方法允许使用自定义删除器，并重置 `shared_ptr`，使其指向新的对象。

#### 示例代码：
```cpp
#include <iostream>
#include <memory>  // 包含 shared_ptr 头文件

// 自定义删除器
void custom_deleter(int* p) {
    std::cout << "自定义删除器调用，释放内存。" << std::endl;
    delete p;
}

int main() {
    auto p = std::make_shared<int>(42);  // 创建 shared_ptr，指向 42
    std::cout << "p 所指的值: " << *p << std::endl;  // 输出 42

    p.reset(new int(100), custom_deleter);  // 使用自定义删除器，将 p 重置为指向新的值 100
    std::cout << "p 现在指向的值: " << *p << std::endl;  // 输出 100

    return 0;
}
```

#### 解释：
- `p` 最初指向值为 42 的内存。
- `p.reset(new int(100), custom_deleter);`：重置 `p`，现在 `p` 指向新的动态内存，值为 100，并且使用 `custom_deleter` 来释放内存。
- 当 `p` 不再被使用时，`custom_deleter` 将被调用以释放内存，并输出 "自定义删除器调用，释放内存。"。

### 总结：
- **`shared_ptr`** 提供了灵活的内存管理方式，可以通过 `reset` 和构造函数控制内存的分配和释放。
- **自定义删除器** 可以用于管理特殊资源（如文件、网络连接等），确保在对象销毁时正确地释放资源。
