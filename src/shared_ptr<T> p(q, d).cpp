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
