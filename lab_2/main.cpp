#include "Udalov.h"
#include <iostream>
#include <locale>
#include <codecvt>
using namespace std;
void check( wstring text, wstring key,  bool destructCipherText=false)
{
	try {
		wstring cipherText;
		wstring decryptedText;
		Cipher cipher(key);
		cipherText = cipher.encrypt(text);
		if (destructCipherText)
			cipherText.front() = towlower(cipherText.front());
		decryptedText = cipher.decrypt(cipherText);
		wcout<<L"key="<<key<<endl;
		wcout<<text<<endl;
		wcout<<cipherText<<endl;
		wcout<<decryptedText<<endl;
	} catch (const cipher_error & e) {
		wcerr<<"Error: "<<e.what()<<endl;
	}
}
void interface_program()
{
	wstring key;
	wstring text;
	unsigned op;
	wcout<<L"Введите ключ(Кол-во столбцов): ";
	wcin>>key;
	Cipher cipher(key);
	do {
		wcout<<L"Выберите операцию (0-exit, 1-encrypt, 2-decrypt, 3-setkey): ";
		wcin>>op;
		if (op > 3) {
			wcout<<L"Не может быть, попробуй другую операцию\n";
		} else if (op > 0 && op < 3) {
			wcout<<L"Введите текст: ";
			wcin>>text;
			if (op==1) {
				wcout<<L"Зашифрованный текст: "<<cipher.encrypt(text)<<endl;
			} else {
				wcout<<L"Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
			}
		} else if (op == 3) {
			wcout<<L"Введите ключ заново: ";
			wcin>>key;
			cipher.set_key(key);
		}
	} while (op!=0);
}
int main(int argc, char **argv)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
	unsigned mode_program;
	do {
		wcout<<L"Интерфейс (1) или тест программы (2)? Выход (0). Ввод:";
		wcin>>mode_program;
		if (mode_program == 1) {
			interface_program();
		} else if (mode_program == 2) {
			wstring meow = L"------------------------------";
			check(L"Россия",L"0");
			wcout<<meow<<endl;
			check(L"Россия",L"");
			wcout<<meow<<endl;
			check(L"Россия",L">!-*k");
			wcout<<meow<<endl;
			check(L"Россия",L"3",true);
			wcout<<meow<<endl;
			check(L"Россия",L"3");
			wcout<<meow<<endl;
			check(L"Рос2сия",L"3");
			wcout<<meow<<endl;
			check(L"Россия",L"3");
			wcout<<meow<<endl;
			check(L"",L"3");
			wcout<<meow<<endl;
			check(L"Россия",L"3");
			wcout<<meow<<endl;
			return 0;
		}
	} while (mode_program!=0);
	return 0;
}
