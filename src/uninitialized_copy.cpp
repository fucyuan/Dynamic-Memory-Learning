#include <iostream>
#include <memory>
#include <vector>
#include <algorithm> // for std::uninitialized_copy

int main() {
    // 源数据
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 分配未初始化的内存，足够存储 vec 中的 5 个元素
    std::allocator<int> alloc;
    int* p = alloc.allocate(vec.size());

    // 使用 uninitialized_copy 拷贝元素到未初始化的内存中
    std::uninitialized_copy(vec.begin(), vec.end(), p);

    // 打印拷贝后的结果
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    // 析构元素并释放内存
    for (size_t i = 0; i < vec.size(); ++i) {
        alloc.destroy(p + i);
    }
    alloc.deallocate(p, vec.size());

    return 0;
}
