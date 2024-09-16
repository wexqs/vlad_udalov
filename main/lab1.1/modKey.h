#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class modKey
{
private:
    int key1; // кол-во столбцов
public:
    modKey()=delete; // запрет конструктора без параметров
    modKey(const int& key) :key1(key) {};
    std::wstring encrypt(const std::wstring& open_text); // зашифрование
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};
