#include <iostream>
#include <memory>
#include <vector>
#include <algorithm> // for std::uninitialized_copy_n

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // 分配未初始化的内存，存储 3 个 int
    std::allocator<int> alloc;
    int* p = alloc.allocate(3);

    // 拷贝前 3 个元素
    std::uninitialized_copy_n(vec.begin(), 3, p);

    // 打印结果
    for (int i = 0; i < 3; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    // 析构和释放内存
    for (int i = 0; i < 3; ++i) {
        alloc.destroy(p + i);
    }
    alloc.deallocate(p, 3);

    return 0;
}
