#pragma once
#include <iostream>
class BaseManager
{
public:
    virtual void loadFromFile(const std::string& filename) = 0; // 순수 가상 함수로 선언
    virtual void saveToFile(const std::string& filename) const = 0; // 순수 가상 함수로 선언
    virtual int size() const = 0; // 데이터의 크기를 반환하는 순수 가상 함수
    virtual ~BaseManager() {} // 가상 소멸자
};


