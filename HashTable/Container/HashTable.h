#pragma once

#include <vector>
#include <iostream>

// 아이템 정보 구조체
struct Item
{
    std::string name;
    std::string type;
    int value;
};

// 해시테이블 클래스 (체이닝 방식)
class HashTable
{
private:
    using Entry = Item;

public:
    HashTable() = default;
    ~HashTable() = default;

    // 아이템 추가
    bool Add(const std::string& name, const std::string& type, int value);

    // 아이템 삭제
    bool Delete(const std::string& name);

    // 아이템 검색
    bool Find(const std::string& name, Entry& outItem) const;

    // 전체 아이템 출력
    void Print() const;

    // 비어있는지 확인
    bool IsEmpty() const;

private:
    // 버킷 개수 (소수 사용)
    static const int bucketCount = 19;

    // 체이닝용 2차 저장소
    std::vector<Entry> table[bucketCount];

    // 해시 함수
    int GenerateHash(const std::string& key) const;
};