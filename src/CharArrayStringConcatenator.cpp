#include <iostream>
#include <cstring>

int main() {
    // 定义两个字符串字面常量
    const char* str1 = "Hello, ";
    const char* str2 = "World!";
    
    // 计算总长度，并动态分配 char 数组
    size_t len = std::strlen(str1) + std::strlen(str2) + 1;  // +1 是为了 '\0'
    char* result = new char[len];

    // 将两个字符串拷贝到动态分配的数组中
    std::strcpy(result, str1);
    std::strcat(result, str2);

    // 输出结果
    std::cout << "结果: " << result << std::endl;

    // 释放动态分配的内存
    delete[] result;

    return 0;
}
