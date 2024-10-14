#include "Udalov.h"

#include <cctype>
#include <codecvt>
#include <iostream>
#include <locale>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText = false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        TiMP cipher(key);
        cipherText = cipher.encrypt(Text);
        if(destructCipherText)
            cipherText.front() = towlower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout << L"key=" << key << endl;
        wcout << Text << endl;
        wcout << cipherText << endl;
        wcout << decryptedText << endl;
    } catch(const cipher_error& e) {
        wcerr << "Error: " << e.what() << endl;
    }
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"РОССИЯ", L"КИТАЙ");
    check(L"КИТАЙ", L"");
    check(L"КИТАЙ", L"РОССИЯ321");
    check(L"К И Т А Й", L"РОССИЯ");
    check(L"321", L"РОССИЯ");
}
