﻿#include <iostream>
#include <fstream>
#include <windows.h>

char istr[81];
char ostr[81];

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Тулегенова Алиса 1381.\nВариант 25. Инвертирование введенных во входной строке цифр в десятичной СС\n и преобразование заглавных русских букв в строчные,\n остальные символы входной строки передаются в выходную строку непосредственно.\n";
    std::cout << "Введите строку: ";
    std::cin.getline(istr, 81);

    std::ofstream file("out.txt");

    __asm {
        push ds
        pop es
        mov esi, offset istr
        mov edi, offset ostr
        mov cl, 0

        check :
            lodsb
            cmp al, '\0'
            je stop

            cmp al, '0'
            jb writesym
            cmp al, '9'
            jbe inverse

            cmp al, 'Ё'
            je yo

            cmp al, 'А'
            jb writesym
            cmp al, 'Я'
            jbe change
            cmp al, 'Я'
            jg writesym

        yo :
            add al, 16
            jmp writesym

        change :
            add al, 32
            jmp writesym

        inverse :
            neg al
            add al, 105
            add cl, al - 48

        writesym :
            stosb
            jmp check
        stop :
            mov al, 32
            stosb
            mov al, cl
            stosb
    };

    std::cout << "Итог: " << ostr;
    file << ostr;
    file.close();

    return 0;
}