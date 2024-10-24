#include <iostream>
#include <cstring>

int main() {
    // 设置一个初始大小的动态分配的字符数组
    size_t size = 50;  // 假设最多读取 50 个字符
    char* input = new char[size];

    // 提示用户输入字符串
    std::cout << "请输入字符串: ";
    std::cin.getline(input, size);

    // 输出结果
    std::cout << "您输入的字符串是: " << input << std::endl;

    // 释放动态分配的内存
    delete[] input;

    return 0;
}
