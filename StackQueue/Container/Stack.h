#pragma once
#include <iostream>

template<typename T, int capacity = 10>
class Stack
{
public:
    Stack()
        : top(0)
    {
    }

    // 데이터 추가
    bool Push(const T& value)
    {
        if (IsFull())
            return false;

        data[top] = value;
        ++top;
        return true;
    }

    // 데이터 제거
    bool Pop(T& outValue)
    {
        if (IsEmpty())
            return false;

        --top;
        outValue = data[top];
        return true;
    }

    // 전체 초기화
    void Clear()
    {
        top = 0;
    }

    // 스택 내용 출력
    void Print(const std::string& name) const
    {
        std::cout << name << ": ";
        for (int i = 0; i < top; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }

    // 현재 저장 개수
    inline int Count() const { return top; }

    // 비어있는지 확인
    inline bool IsEmpty() const { return top == 0; }

    // 가득 찼는지 확인
    inline bool IsFull() const { return top >= capacity; }

private:
    T data[capacity] = {};
    int top = 0;
};