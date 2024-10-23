#include <iostream>
#include <stdexcept>  // for std::out_of_range

template<typename T>
class DynamicArray {
public:
    // 默认构造函数
    DynamicArray() : size_(0), capacity_(1), data_(new T[1]) {}

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
        delete[] data_;
        size_ = 0;
        capacity_ = 1;
        data_ = new T[capacity_];
    }

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
};

int main() {
    DynamicArray<int> arr;

    // 添加一些元素
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    // 输出数组中的元素
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "Element at index " << i << ": " << arr[i] << std::endl;
    }

    // 删除最后一个元素
    arr.pop_back();
    std::cout << "After pop_back, size: " << arr.size() << std::endl;

    // 访问数组中的第一个元素
    std::cout << "First element: " << arr.at(0) << std::endl;

    // 清空数组
    arr.clear();
    std::cout << "After clear, size: " << arr.size() << ", capacity: " << arr.capacity() << std::endl;

    return 0;
}
