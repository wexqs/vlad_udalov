#pragma once
#include <codecvt>
#include <locale>
#include <map>
#include <string>
#include <vector>
class TiMP
{
private:
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::map<wchar_t, int> alphaNum;
    std::vector<int> key;
    std::vector<int> convert(const std::wstring& ws);
    std::wstring convert(const std::vector<int>& v);
    std::wstring getValidKey(const std::wstring& ws);
    std::wstring getValidOpenText(const std::wstring& ws);
    std::wstring getValidCipherText(const std::wstring& ws);

public:
    TiMP() = delete;
    TiMP(const std::wstring& wskey);
    std::wstring encrypt(const std::wstring& open_text);
    std::wstring decrypt(const std::wstring& cipher_text);
};
class cipher_error : public std::invalid_argument
{
public:
    explicit cipher_error(const std::string& what_arg)
        : std::invalid_argument(what_arg)
    {
    }
    explicit cipher_error(const char* what_arg)
        : std::invalid_argument(what_arg)
    {
    }
};
