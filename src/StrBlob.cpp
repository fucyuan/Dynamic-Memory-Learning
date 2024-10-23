#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;

    // 默认构造函数
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    
    // 接受初始化列表的构造函数
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

    // 返回元素数量
    size_type size() const { return data->size(); }

    // 判断是否为空
    bool empty() const { return data->empty(); }

    // 添加元素到末尾
    void push_back(const std::string &t) { data->push_back(t); }

    // 删除最后一个元素，并检查是否为空
    void pop_back();

    // 返回第一个元素的引用
    std::string& front();

    // 返回最后一个元素的引用
    std::string& back();

private:
    std::shared_ptr<std::vector<std::string>> data;  // 用shared_ptr管理字符串向量

    // 检查索引是否合法
    void check(size_type i, const std::string &msg) const;
};

// 检查函数，如果索引超出范围则抛出异常
void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

// 返回第一个元素的引用
std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

// 返回最后一个元素的引用
std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

// 删除最后一个元素
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

// 主函数，演示 StrBlob 类的用法
int main() {


    StrBlob b1; // 空对象
    {
    StrBlob b2 = {"a", "an", "the"}; // 初始化 b2

    b1 = b2; // b1 和 b2 共享数据
    b2.push_back("about"); // 向 b2 中添加 "about"，同时影响 b1
    }
    std::cout << "b1 size: " << b1.size() << std::endl;
    // std::cout << "b2 size: " << b2.size() << std::endl;
    // 使用初始化列表创建StrBlob对象
    StrBlob blob({"Hello", "World", "!"});
    
    std::cout << "Size: " << blob.size() << std::endl;  // 输出: 3
    std::cout << "First element: " << blob.front() << std::endl;  // 输出: Hello
    std::cout << "Last element: " << blob.back() << std::endl;  // 输出: !
    
    // 移除最后一个元素
    blob.pop_back();
    std::cout << "Size after pop_back: " << blob.size() << std::endl;  // 输出: 2

    return 0;
}
