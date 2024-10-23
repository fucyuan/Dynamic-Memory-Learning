#include <iostream>
#include <string>

int main() {
    // 定义两个标准库 string 对象
    std::string str1 = "Hello, ";
    std::string str2 = "World!";

    // 连接两个字符串
    std::string result = str1 + str2;

    // 输出结果
    std::cout << "结果: " << result << std::endl;

    return 0;
}
