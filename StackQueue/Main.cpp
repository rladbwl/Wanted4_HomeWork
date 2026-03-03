#include <iostream>
#include <string>
#include "Container/Queue.h"
#include "Container/Stack.h"

// 입력 큐
Queue<std::string, 10> inputQueue;

// Undo / Redo 스택
Stack<std::string, 10> undoStack;
Stack<std::string, 10> redoStack;

int main()
{
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);

        // Undo 실행
        if (input == "undo")
        {
            std::string value;

            // Undo 스택에서 꺼내 Redo 스택으로 이동
            bool result = undoStack.Pop(value);
            if (result == true)
            {
                redoStack.Push(value);
            }
        }
        // Redo 실행
        else if (input == "redo")
        {
            std::string value;

            // Redo 스택에서 꺼내 Undo 스택으로 이동
            bool result = redoStack.Pop(value);
            if (result == true)
            {
                undoStack.Push(value);
            }
        }
        // 현재 상태 출력
        else if (input == "show")
        {
            undoStack.Print("Undo Stack");
            redoStack.Print("Redo Stack");
        }
        // A~E 입력 처리
        else if (input.length() == 1 && input[0] >= 'A' && input[0] <= 'E')
        {
            inputQueue.Enqueue(input);

            // 큐에 들어온 입력을 Undo 스택에 기록
            while (!inputQueue.IsEmpty())
            {
                std::string value;

                bool result = inputQueue.Dequeue(value);
                if (result == true)
                {
                    undoStack.Push(value);

                    // 새로운 입력이 들어오면 Redo 기록 초기화
                    redoStack.Clear();
                }
            }
        }
        else
        {
            std::cout << "A~E, undo, redo, show 만 입력하세요.\n";
        }
    }
}