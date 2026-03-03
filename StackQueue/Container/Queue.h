#pragma once
#include <iostream>

template<typename T, int capacity = 10>
class Queue
{
public:

    // 데이터 추가
    bool Enqueue(const T& value)
    {
        if (IsFull())
            return false;

        rear = (rear + 1) % (capacity + 1);
        data[rear] = value;
        return true;
    }

    // 데이터 제거
    bool Dequeue(T& outValue)
    {
        if (IsEmpty())
            return false;

        front = (front + 1) % (capacity + 1);
        outValue = data[front];
        data[front] = T();   // 초기화
        return true;
    }

    // 다음 데이터 확인 (삭제 안함)
    bool Peek(T& outValue)
    {
        if (IsEmpty())
            return false;

        outValue = data[(front + 1) % (capacity + 1)];
        return true;
    }

    // 큐 전체 출력
    void Print()
    {
        std::cout << "큐 내용 출력 : ";

        const int max = (front < rear)
            ? rear
            : (rear + (capacity + 1));

        for (int ix = front + 1; ix <= max; ++ix)
        {
            std::cout << " " << data[ix % (capacity + 1)];
        }

        std::cout << "\n";
    }

    // 비어있는지 확인
    inline bool IsEmpty()
    {
        return rear == front;
    }

    // 가득 찼는지 확인
    inline bool IsFull()
    {
        return (rear + 1) % (capacity + 1) == front;
    }

    // 최대 저장 개수 반환
    inline bool Capacity()
    {
        return capacity;
    }

private:
    int front = 0;
    int rear = 0;
    T data[capacity + 1] = {};
};