#include <iostream>
#include <vector>
#include <memory>  // 包含 shared_ptr 头文件

// 返回一个使用 shared_ptr 管理的 int vector
std::shared_ptr<std::vector<int>> create_shared_vector() {
    return std::make_shared<std::vector<int>>();
}

// 将输入的值保存到 vector 中
void read_values(std::shared_ptr<std::vector<int>> vec) {
    int value;
    std::cout << "请输入一些整数(输入非数字结束): ";
    while (std::cin >> value) {
        vec->push_back(value);
    }
    std::cin.clear(); // 清除错误状态
    std::cin.ignore(); // 忽略错误输入
}

// 打印 vector 中的值
void print_values(const std::shared_ptr<std::vector<int>>& vec) {
    std::cout << "你输入的值是: ";
    for (const int& val : *vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    auto vec = create_shared_vector();  // 创建由 shared_ptr 管理的 vector
    read_values(vec);                   // 从输入读取数据
    print_values(vec);                  // 打印数据
    // 不需要显式删除，shared_ptr 会自动管理内存
    return 0;
}
