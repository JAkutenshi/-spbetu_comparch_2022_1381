#include <iostream>
#include <fstream>
#include <random>

extern "C" void FUNC(int* array, int array_size, int* LGrInt, int NInt, int* result_array);


int main() {
	system("chcp 1251 > nul");
	setlocale(LC_CTYPE, "rus");
	std::ofstream file("out.txt");
	int NumRanDat;

	std::cout << "������� ���������� ��������������� �����\n";
	std::cin >> NumRanDat;

	int Xmax, Xmin;
	std::cout << "������� ����������� �������\n";
	std::cin >> Xmin;
	std::cout << "������� ������������ ��������\n";
	std::cin >> Xmax;

	if (Xmax < Xmin) {
		std::cout << "�������� ��������\n";
		return 0;
	}

	int NInt;
	std::cout << "������� ���������� ����������\n";
	std::cin >> NInt;

	if (NInt <= 0) {
		std::cout << "�������� ��������\n";
		return 0;
	}

	int* LGrInt = new int[NInt];
	std::cout << "������� ����� �������\n";
	for (int i = 0; i < NInt; i++) {
		std::cin >> LGrInt[i];
	}


	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_int_distribution<> dis(Xmin, Xmax);
	int* arr = new int[NumRanDat];
	for (int i = 0; i < NumRanDat; i++) {
		arr[i] = dis(gen);
	}

	for (int i = 0; i < NumRanDat; i++) {
		file << arr[i] << ' ';
	}
	file << '\n';

	int* result_arr = new int[NInt];
	for (int i = 0; i < NInt; i++) {
		result_arr[i] = 0;
	}

	FUNC(arr, NumRanDat, LGrInt, NInt, result_arr);

	std::cout << "������ ��������� \t �������� ����� ������� \t ����� ����� � ���������\n";
	file << "������ ��������� \t �������� ����� ������� \t ����� ����� � ���������\n";

	for (int i = 0; i < NInt; i++) {
		std::cout << "\t" << i + 1 << "\t\t\t" << LGrInt[i] << "\t\t\t\t" << result_arr[i] << '\n';
		file << "\t" << i + 1 << "\t\t\t" << LGrInt[i] << "\t\t\t\t" << result_arr[i] << '\n';

	}
	std::cout << '\n';
	for (int i = 0; i < NumRanDat; i++) {
		std::cout << arr[i] << ' ';
	}
	delete[] LGrInt;
	delete[] arr;
	delete[] result_arr;

}

