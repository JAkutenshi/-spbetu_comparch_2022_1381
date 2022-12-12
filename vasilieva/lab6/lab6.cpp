#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <locale>

using namespace std;

extern "C" void func(int* intervals, int N_int, int N, int* numbers, int* final_answer);

int main() {
	system("chcp 1251 > nul");
	setlocale(LC_CTYPE, "rus");

	int N, X_min, X_max, N_int;

	cout << "������� ���������� �����:";
	cin >> N;
	cout << "������� ��������:";
	cin >> X_min >> X_max;
	cout << "������� ���������� ����������:";
	cin >> N_int;

	if (N_int <= 0 || N_int > 24) {
		cout << "���������� ���������� �� ������������\n";
		system("Pause");
		return 0;
	}

	if (N_int < abs(X_max - X_min)) {
		cout << "���������� ���������� ����� ���� ������ ��� ����� �������� ����. � ���. ����� ���������\n";
		system("Pause");
		return 0;
	}

	cout << "������� ����� ���������:";
	auto intervals = new int[N_int + 1];
	for (int i = 0; i < N_int; i++)
		cin >> intervals[i];

	if (intervals[0] <= X_min) {
		cout << "������ ����� ������� ������ ���� ������ ���. ������� ���������\n";
		system("Pause");
		return 0;
	}

	cout << "������� ������ �������\n";
	cin >> intervals[N_int];

	if (intervals[N_int] < intervals[N_int - 1]){
		cout << "������ ������� ���������� ��������� ������ ���� ������ ����� ������� ���������� ���������\n";
		system("Pause");
		return 0;
	}

	if (intervals[N_int] <= X_max) {
		cout << "������ ������� ���������� ��������� ����� ���� ������ ����. ������� ���������\n";
		system("Pause");
		return 0;
	}

	auto numbers = new int[N];
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> dist(X_min, X_max);
	for (int i = 0; i < N; i++) {
		numbers[i] = dist(generator);
		cout << numbers[i] << " ";
	}

	cout << endl;

	auto final_answer = new int[N_int];

	for (int i = 0; i < N_int; i++)
		final_answer[i] = 0;

	func(intervals, N_int, N, numbers, final_answer);

	ofstream file("output.txt");
	auto str = "������ ���������\t�������� ����� �������\t���������� ����� � ���������";
	file << str << endl;
	cout << str << endl;

	for (int i = 0; i < N_int; i++) {
		auto str_result = to_string(i + 1) + "\t\t\t" + to_string(intervals[i]) + "\t\t\t\t" + to_string(final_answer[i]) + "\n";
		file << str_result;
		cout << str_result;
	}

	system("Pause");

	return 0;
}
