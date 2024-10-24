#include <iostream>
#include <stdexcept>  // for std::out_of_range
#include <iterator>   // for iterator support

template<typename T>
class DynamicArray {
public:
    // 默认构造函数
    DynamicArray() : size_(0), capacity_(1), data_(new T[1]) {}

    // 带有大小的构造函数
    DynamicArray(size_t initial_size) : size_(0), capacity_(initial_size), data_(new T[initial_size]) {}

    // 深拷贝构造函数
    DynamicArray(const DynamicArray& other) {
        copy_from(other);
    }

    // 赋值运算符重载
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data_;  // 释放旧的内存
            copy_from(other);
        }
        return *this;
    }

    // 析构函数
    ~DynamicArray() {
        delete[] data_;
    }

    // 返回数组中元素的数量
    size_t size() const { return size_; }

    // 返回数组的容量
    size_t capacity() const { return capacity_; }

    // 判断数组是否为空
    bool empty() const { return size_ == 0; }

    // 添加元素到数组末尾
    void push_back(const T& value) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);  // 如果数组满了，则扩展容量为原来的两倍
        }
        data_[size_++] = value;
    }

    // 删除数组末尾的元素
    void pop_back() {
        if (empty()) {
            throw std::out_of_range("Array is empty.");
        }
        --size_;
    }

    // 插入元素到任意位置
    void insert(size_t index, const T& value) {
        if (index > size_) {
            throw std::out_of_range("Index out of range.");
        }
        if (size_ == capacity_) {
            resize(capacity_ * 2);  // 扩展容量
        }
        // 将元素向右移动
        for (size_t i = size_; i > index; --i) {
            data_[i] = data_[i - 1];
        }
        data_[index] = value;
        ++size_;
    }

    // 获取数组的第 i 个元素，带边界检查
    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range.");
        }
        return data_[index];
    }

    // 返回数组的第 i 个元素（可以用于修改）
    T& operator[](size_t index) {
        return data_[index];
    }

    // 清空数组
    void clear() {
        size_ = 0;
    }

    // 迭代器支持，允许范围 for 循环遍历
    T* begin() { return data_; }
    T* end() { return data_ + size_; }

private:
    size_t size_;     // 数组中的元素数量
    size_t capacity_; // 数组的容量
    T* data_;         // 动态分配的内存指针

    // 调整数组的大小
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];  // 拷贝旧数组中的元素到新数组中
        }
        delete[] data_;  // 释放旧的内存
        data_ = new_data;
        capacity_ = new_capacity;
    }

    // 从另一个数组深拷贝
    void copy_from(const DynamicArray& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
};

int main() {
    DynamicArray<int> arr;

    // 添加一些元素
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    // 在索引 1 插入新元素
    arr.insert(1, 99);

    // 输出数组中的元素
    std::cout << "Array contents after insertion:" << std::endl;
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 测试深拷贝
    DynamicArray<int> arr_copy = arr;
    arr_copy.push_back(50);  // 在副本中添加新元素

    std::cout << "Original array after copying:" << std::endl;
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied array with new element:" << std::endl;
    for (const auto& val : arr_copy) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
 