﻿#include <iostream>
#include <fstream>

char input_str[81]; // Входная строчка
int letters[26] = {0}; // Массив вхождений букв (если буква есть в строке 0 меняется на её индекс)
int counter = -1; // индекс массива letters

// Вариант 12. Формирование номера введенной латинской буквы по алфавиту
// и номера позиции его первого вхождения во входной строке и выдача их на экран.

int main() {
    std::cout << "Smirnov Dmitry group - 1381\n";
    std::cout << "Task: Forming the number of the entered Latin letter in alphabetical order\nand the position number of its first occurrence in the input string\nand displaying them on the screen.\n";
    std::cout << "Enter string:\n";
    std::cin.getline(input_str, 81);

    __asm {
            push ds
            pop es
            sub ax, ax
            mov ah, 96 // Символ перед латинской буквой 'a'
    loop_s:
            mov esi, offset input_str // адрес начала строки
            inc ah // Ищем следующий латинский символ
            inc counter // увеличиваем индекс letters
            sub ecx, ecx // очищаем ecx
    loop_:
            sub al, al // очищаем al
            lodsb // загружаем символ из строки input_str в al
            inc ecx // увеличиваем кол-во считанных символов
            cmp al, '\0' // если строка закончилась идем на метку check_last_letter
            je check_last_letter
    check_letter:
            cmp al, ah
            je write_index // найден прописной символ

            mov bh, ah
            sub bh, 32
            cmp al, bh
            je write_index // найден заглавный символ

            jmp check_last_letter
            
    write_index:
            mov edi, counter
            mov ES:letters[edi * 4], ecx // записываем номер вхождения символа (маштабируем в 4 раза тк массив типа int)
            jmp loop_s // начинаем новую итерацию цикла
    check_last_letter:
            cmp ah, 'z' // если дошли до z завершаем
            je final // метка на конец вставки
            cmp al, '\0' // строка закончилась начинаем новый цикл
            je loop_s // метка на начало цикла
            jmp loop_ // продолжаем считывание строки

    final:
    };
    std::fstream file;
    file.open("./answer.txt");
    for (int i = 0; i < 26; i++)
    {
        if (letters[i] != 0) {
            std::cout << i + 1 << " " << letters[i] << std::endl;
            file << i + 1 << " " << letters[i] << std::endl;
        }
    }
    file.close();
    std::cout << "Completed!\n";
    return 0;
}