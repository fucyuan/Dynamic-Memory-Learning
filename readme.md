

# Dynamic Memory Learning - C++ Primer Chapter 12

This project is part of my journey in learning C++ dynamic memory management, following Chapter 12 of the *C++ Primer*. The focus is on understanding the use of dynamic memory, smart pointers (`shared_ptr`, `unique_ptr`), weak pointers, and the `allocator` class, along with other dynamic memory management techniques.

## Project Structure

The project is divided into the following directories:

### 1. `build/`
This directory contains the compiled executables from the source files. Each executable represents a specific program related to dynamic memory concepts.

- **AllocatorStringManager.exe**: Manages dynamic memory with the `allocator` class for string management.
- **CharArrayStringConcatenator.exe**: Concatenates strings using dynamically allocated character arrays.
- **DynamicArray V2.exe**: Demonstrates an advanced dynamic array with manual memory management.
- **DynamicCharArrayInputReader.exe**: Reads input into a dynamic character array.
- **dynamic_vector_manual_delete**: Handles dynamic vectors with manual memory management.
- **dynamic_vector_shared_ptr**: Demonstrates usage of `shared_ptr` with dynamic vectors.
- **FileToStrBlobPrinter.exe**: Reads a file into a `StrBlob` and prints its content.
- **StrBlobPtr.exe**: Demonstrates `StrBlobPtr` class for accessing elements of a `StrBlob`.
- **uninitialized_copy.exe**, **uninitialized_copy_n.exe**, **uninitialized_fill.exe**: Illustrate different uses of `uninitialized_copy`, `uninitialized_copy_n`, and `uninitialized_fill` for managing uninitialized memory.

### 2. `doc/`
This directory contains documentation and notes related to the exercises and explanations from Chapter 12 of *C++ Primer*.

- **练习解答.md**: Solutions to the exercises in Chapter 12.
- **allocator 类.md**, **allocator 类.pdf**: Notes and explanations on the `allocator` class.
- **shared_ptr.md**: Explanation and use cases of `shared_ptr` in C++.

### 3. `src/`
The source code directory contains `.cpp` files that demonstrate various aspects of dynamic memory management in C++. These files are compiled to the executables located in the `build/` directory.

- **AllocatorStringManager.cpp**: Example of using the `allocator` class for string management.
- **CharArrayStringConcatenator.cpp**: String concatenation using dynamically allocated character arrays.
- **DynamicArray.cpp**: Basic implementation of dynamic arrays in C++.
- **DynamicArray V2.cpp**: A more advanced version of dynamic arrays with better memory handling.
- **DynamicCharArrayInputReader.cpp**: Reads input into a dynamically allocated char array.
- **dynamic_vector_manual_delete.cpp**: Manual memory management in dynamic vectors.
- **dynamic_vector_shared_ptr.cpp**: Demonstrates `shared_ptr` usage with dynamic vectors.
- **FileToStrBlobPrinter.cpp**: Reads a file into a `StrBlob` object and prints it.
- **StrBlob.cpp**: Implementation of the `StrBlob` class.
- **StrBlobPtr.cpp**: Implementation of the `StrBlobPtr` class for navigating through a `StrBlob`.
- **StringObjectConcatenator.cpp**: Concatenates strings using `std::string` objects.
- **uninitialized_copy.cpp**, **uninitialized_copy_n.cpp**, **uninitialized_fill.cpp**: Demonstrates the use of the `allocator` to handle uninitialized memory operations.

### Input File:
- **input.txt**: Example input file used for file reading operations in programs like `FileToStrBlobPrinter`.

## Compilation

To compile the source code, use the following commands (assuming you are in the root directory of the project):

```bash
g++ src/AllocatorStringManager.cpp -o build/AllocatorStringManager.exe
g++ src/CharArrayStringConcatenator.cpp -o build/CharArrayStringConcatenator.exe
# Add more as needed for other source files
```

## Learning Objectives

- Understand the concepts of dynamic memory in C++.
- Learn how to safely manage dynamic memory using smart pointers (`shared_ptr`, `unique_ptr`, and `weak_ptr`).
- Master the use of the `allocator` class for more fine-grained control over memory allocation.
- Explore the differences between manual memory management and smart pointer-based memory management.
- Develop skills in managing memory in both basic types (like `char` arrays) and complex types (like `std::vector`).

