#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

char input_string[81];
char output_string[81];

int main() {
	system("chcp 1251 > nul");
	setlocale(LC_CTYPE, "rus");

	cout << "������������ ������ �4; ������� �3 \n ������ ��������� ��������� ������ 1381 ��������� �����\n �������:������������ ������� ������ ������ �� ������� � ��������� ���� ������� ������." << endl;
	cout << "������� ������:";
	cin.getline(input_string, 81);

	ofstream file;
	file.open("out.txt");

	__asm{
		push ds
		pop es
		mov esi, offset input_string
		mov edi, offset output_string

		start:
			lodsb
			cmp al, '\0'
			je finish //��� ���������� ����� ������, ���������� ���������

			cmp al, 'a'
			jge check_low

			cmp al, 'A'
			jge check_up

			cmp al, '�'
			jge check_rus

			cmp al, '�'
			je write

			cmp al, '�'
			je write

			jmp start

		check_up:
			cmp al, 'Z'
			jle write
			jmp start

		check_low:
			cmp al, 'z'
			jle write
			jmp start

		check_rus:
			cmp al,'�'
			jle write
			jmp start

		write:
				stosb
				jmp start
		
		finish:
	};

	cout << "�������� ������: ";
	cout << output_string << endl;
	file << output_string;
	file.close();
	return 0;
}