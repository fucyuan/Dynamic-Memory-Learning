#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

class StrBlob; // 先声明 StrBlob 类，因为 StrBlobPtr 要引用它

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) {}  // 默认构造函数，curr 初始化为 0
    StrBlobPtr(StrBlob &a, size_t sz = 0);  // 带参数构造函数
    
    std::string& deref() const;  // 解引用，返回当前元素
    StrBlobPtr& incr();  // 前缀递增，移动到下一个元素

private:
    std::shared_ptr<std::vector<std::string>> 
    check(std::size_t, const std::string&) const;  // 检查当前指针是否合法
    std::weak_ptr<std::vector<std::string>> wptr;  // weak_ptr，弱指针，不控制对象生命周期
    std::size_t curr;  // 当前指向的位置
};

// StrBlob 类用于管理字符串的 vector
class StrBlob {
public:
    friend class StrBlobPtr;  // 允许 StrBlobPtr 访问 StrBlob 的私有成员

    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}  // 默认构造函数，初始化一个空的 vector
    StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}

    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std::string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    StrBlobPtr begin();  // 返回指向 vector 首元素的 StrBlobPtr
    StrBlobPtr end();    // 返回指向 vector 尾元素的 StrBlobPtr

private:
    std::shared_ptr<std::vector<std::string>> data;  // shared_ptr，指向实际的数据
    void check(size_t i, const std::string &msg) const {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

// StrBlobPtr 的构造函数定义
StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz): wptr(a.data), curr(sz) {}

// check 成员函数的定义
std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();  // 检查 weak_ptr 是否还指向一个有效的 shared_ptr
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");  // 如果 ret 为空，抛出异常
    if (i >= ret->size())
        throw std::out_of_range(msg);  // 如果索引越界，抛出异常
    return ret;  // 返回指向 vector 的 shared_ptr
}

// deref 成员函数的定义
std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");  // 检查当前指针是否有效
    return (*p)[curr];  // 返回当前元素
}

// incr 成员函数的定义
StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");  // 检查是否可以递增
    ++curr;  // 递增 curr
    return *this;
}

// StrBlob 的 begin 函数定义
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

// StrBlob 的 end 函数定义
StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

int main() {
    StrBlob blob{"hello", "world", "test"};
    StrBlobPtr ptr = blob.begin();
    
    try {
        std::cout << ptr.deref() << std::endl;  // 输出 "hello"
        ptr.incr();
        std::cout << ptr.deref() << std::endl;  // 输出 "world"
        ptr.incr();
        std::cout << ptr.deref() << std::endl;  // 输出 "test"
        ptr.incr();  // 试图递增超出范围，应该会抛出异常
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;  // 捕捉并输出异常信息
    }

    return 0;
}
