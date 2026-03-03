#include "Container/HashTable.h"
#include <iostream>
#include <sstream>
#include <fstream>

void LoadFile(const std::string& filename, HashTable& table)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "파일 열기 실패\n";
        return;
    }

    //std::ifstream file(filename);
    std::string line;
    // 한 줄씩 읽어서 파싱
    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string name, type, valueStr;

        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, valueStr, ',');

        int value = std::stoi(valueStr);
        // 해시테이블에 추가
        table.Add(name, type, value);
    }
}

int main()
{
    HashTable table;

    // 프로그램 시작 시 파일 로딩
    LoadFile("../items.txt", table);

    while (true)
    {
        std::string input;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        std::string command;
        ss >> command;
        // 아이템 검색
        if (command == "find")
        {
            std::string name;
            ss >> name;

            Item item;
            if (table.Find(name, item))
            {
                std::cout
                    << "Name: " << item.name
                    << " | Type: " << item.type
                    << " | Value: " << item.value << "\n";
            }
            else
            {
                std::cout << "아이템 없음\n";
            }
        }
        // 아이템 삭제
        else if (command == "remove")
        {
            std::string name;
            ss >> name;

            if (table.Delete(name))
                std::cout << "삭제 성공\n";
            else
                std::cout << "아이템 없음\n";
        }
        // 목록 출력
        else if (command == "list")
        {
            table.Print();
        }
        // 프로그램 종료
        else if (command == "exit")
        {
            break;
        }
        else
        {
            std::cout << "다시 입력해주세요\n";
        }
    }

    return 0;
}