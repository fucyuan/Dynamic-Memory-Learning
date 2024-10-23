#include <iostream>
#include <memory>
#include <algorithm> // for std::uninitialized_fill

int main() {
    std::allocator<int> alloc;

    // 分配存储 5 个 int 的内存
    int* p = alloc.allocate(5);

    // 使用 uninitialized_fill 将 5 个位置填充为 42
    std::uninitialized_fill(p, p + 5, 42);

    // 打印结果
    for (int i = 0; i < 5; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    // 析构并释放内存
    for (int i = 0; i < 5; ++i) {
        alloc.destroy(p + i);
    }
    alloc.deallocate(p, 5);

    return 0;
}
