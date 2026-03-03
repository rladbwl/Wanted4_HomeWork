#include "HashTable.h"
#include <iostream>

// 문자열을 정수 해시값으로 변환
int HashTable::GenerateHash(const std::string& key) const
{
    int hash = 0;
    const int length = static_cast<int>(key.length());

    for (int ix = 0; ix < length; ++ix)
    {
        hash = hash * 31 + key[ix];
    }

    return std::abs(hash);
}

// 아이템 추가 (중복 키 허용 안함)
bool HashTable::Add(const std::string& name, const std::string& type, int value)
{
    int bucketIndex = GenerateHash(name) % bucketCount;

    std::vector<Entry>& bucket = table[bucketIndex];

    // 같은 이름 존재 여부 확인
    for (const auto& item : bucket)
    {
        if (item.name == name)
        {
            return false;
        }
    }

    bucket.push_back({ name, type, value });
    return true;
}

// 이름으로 아이템 삭제
bool HashTable::Delete(const std::string& name)
{
    int bucketIndex = GenerateHash(name) % bucketCount;

    std::vector<Entry>& bucket = table[bucketIndex];

    for (size_t i = 0; i < bucket.size(); ++i)
    {
        if (bucket[i].name == name)
        {
            bucket.erase(bucket.begin() + i);
            return true;
        }
    }

    return false;
}

// 이름으로 아이템 검색
bool HashTable::Find(const std::string& name, Entry& outItem) const
{
    int bucketIndex = GenerateHash(name) % bucketCount;

    const std::vector<Entry>& bucket = table[bucketIndex];

    for (const auto& item : bucket)
    {
        if (item.name == name)
        {
            outItem = item;
            return true;
        }
    }

    return false;
}

// 전체 아이템 출력
void HashTable::Print() const
{
    for (const auto& bucket : table)
    {
        for (const auto& item : bucket)
        {
            std::cout
                << "Name: " << item.name
                << " | Type: " << item.type
                << " | Value: " << item.value
                << "\n";
        }
    }
}

// 해시테이블이 비어있는지 확인
bool HashTable::IsEmpty() const
{
    for (const auto& bucket : table)
    {
        if (!bucket.empty())
            return false;
    }
    return true;
}