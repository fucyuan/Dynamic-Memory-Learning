#include <iostream>
#include <memory>  // 为了使用 std::allocator
#include <string>

int main() {
    // 定义一个 allocator 对象用于管理 string 的内存
    std::allocator<std::string> alloc;

    // 设置需要分配的 string 数量
    const size_t n = 5;

    // 分配内存，但不构造对象
    std::string* const p = alloc.allocate(n);

    std::string s;
    std::string* q = p;  // 指向第一个 string 的指针

    // 从标准输入读取字符串，并在未初始化的内存中构造对象
    while (std::cin >> s && q != p + n) {
        alloc.construct(q++, s);  // 构造一个新 string 对象并赋值
    }

    // 计算实际读取的 string 数量
    const size_t size = q - p;
    std::cout << "我们读取了 " << size << " 个字符串。" << std::endl;

    // 输出所有读取的 string
    for (std::string* i = p; i != p + size; ++i) {
        std::cout << *i << std::endl;
    }

    // 析构所有构造的对象
    while (q != p) {
        alloc.destroy(--q);  // 析构对象
    }

    // 释放分配的内存
    alloc.deallocate(p, n);

    return 0;
}
