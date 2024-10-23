#include <iostream>
#include <vector>

// 返回一个动态分配的 int vector
std::vector<int>* create_vector() {
    return new std::vector<int>();
}

// 将输入的值保存到 vector 中
void read_values(std::vector<int>* vec) {
    int value;
    std::cout << "请输入一些整数(输入非数字结束): ";
    while (std::cin >> value) {
        vec->push_back(value);
    }
    std::cin.clear(); // 清除错误状态
    std::cin.ignore(); // 忽略错误输入
}

// 打印 vector 中的值
void print_values(const std::vector<int>* vec) {
    std::cout << "你输入的值是: ";
    for (const int& val : *vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int>* vec = create_vector();  // 创建动态分配的 vector
    read_values(vec);                         // 从输入读取数据
    print_values(vec);                        // 打印数据
    delete vec;                               // 删除动态分配的 vector
    return 0;
}
