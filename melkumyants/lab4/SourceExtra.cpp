#include <iostream>
#include <fstream>
char input_str[81];
char output_str[81];
int k =-1;


int main() {
	system("chcp 1251 > nul");
	setlocale(LC_CTYPE, "rus");

	std::cout << "���������� ������ 1381\n�������: �������� �������� �������� �������� � ����\n";

	std::cout << "������� ������\n";
	std::cin.getline(input_str, 81);

	std::ofstream file;
	file.open("res.txt");

	__asm {
		push ds
		pop es
		mov esi, offset input_str
		mov edi, offset output_str

		count :
		add k, 1
			jmp check

		check :
		lodsb
			cmp al, '\0'
			je finish
			cmp al, '�'
			je check
			cmp al, '�'
			je check
			cmp al, '�'
			jl write
			cmp al, '�'
			jle check
			cmp al, '0'
			jl write
			cmp al, '9'
			jle check


			
			write :
		stosb
			and al, 11011111b
					cmp al, 'A'
					je count
					cmp al, 'E'
					je count
					cmp al, 'I'
					je count
					cmp al, 'O'
					je count
					cmp al, 'U'
					je count
					cmp al, 'Y'
					je count
				jmp check

\


		finish:
	};

	std::cout << "������ ��� �������� �������� �������� � ����\n";
	std::cout << output_str << '\n';
	std::cout << "���������� ������� � ������\n";
	std::cout << k;
	file << output_str;
	file.close();

	return 0;
}