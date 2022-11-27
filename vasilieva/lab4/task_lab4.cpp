#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

char input_string[81];
char output_string[81];
int counter = 0; // �������
char vowels[32]; //������ ��������

int main() {
	std::string str_vowels = "AEIYUOaeiyuo������Ũ�����������";
	for (int i = 0; i < 32; i++) {
		vowels[i] = str_vowels[i];
	}
	system("chcp 1251 > nul");
	setlocale(LC_CTYPE, "rus");

	cout << "������� ������:";
	cin.getline(input_string, 81);

	ofstream file;
	file.open("out.txt");

	__asm {
		push ds
		pop es
		mov esi, offset input_string
		mov edx, esi // ��� �������� �������� ������ �������� ������
		mov edi, offset output_string
		sub ebx, ebx

		start :
			lodsb
			cmp al, '\0'
			je finish //��� ���������� ����� ������, ���������� ���������

			cmp al, '0'
			jl write

			jmp start

		write:
			stosb
			mov edx, esi				
			mov esi, offset vowels
			mov bl, al // ������� ������ �� �������� ������

		check:
			lodsb
			cmp al, '\0'
			je f
			cmp al, bl // ���� �� ����� , ��������� ������ ������� ����� ����������
			jne check
			add counter, 1
			jmp check

		f:
			mov esi, edx //���������� � ������� ������� � �������� ������
			jmp start

		finish :
	};

	cout << "���������� �������:";
	cout << counter;
	file << output_string;
	file.close();
	return 0;
}