﻿#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <random>

extern "C" void first_dist(int* numbers, int n, int* result1, int x_min, float* mid);
extern "C" void second_dist(int* result1, int* intervals, int* result2, int x_max, int x_min, int n_int);
extern "C" void task_dist(int* numbers, int n, int* intervals, int* result3, int n_int);

using namespace std;

int main()
{
	float mid = 0;
	int n, x_min, x_max, n_int;
	cout << "enter the length of the array" << endl;
	cin >> n;
	if (n <= 0 || n > 16000) {
		cout << "0 < n <= 16000!!" << endl;
		system("Pause");
		return 0;
	}
	cout << "enter xMin" << endl;
	cin >> x_min;
	cout << "enter xMax" << endl;
	cin >> x_max;

	if (x_max <= x_min) {
		cout << "xMax > xMin!" << endl;
		system("Pause");
		return 0;
	}
	cout << "enter the number of the intervals" << endl;
	cin >> n_int;
	if (n_int <= 0 || n_int > 24) {
		cout << "0 < n_int <= 24!!" << endl;
		system("Pause");
		return 0;
	}

	int* intervals = new int[n_int + 1];
	for (int i = 0; i < n_int; i++) {
		cout << "enter the Lg of " << i << " interval" << endl;
		cin >> intervals[i];
	}

	intervals[n_int] = x_max + 1;

	for (int i = 0; i < n_int + 1; i++) {
		for (int j = i; j < n_int + 1; j++) {
			if (intervals[i] > intervals[j]) {
				swap(intervals[i], intervals[j]);
			}
		}
	}

	if (intervals[n_int] > x_max + 1) {
		cout << "Rg <= x_max!!" << endl;
		system("Pause");
		return 0;
	}

	int* numbers = new int[n];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(x_min, x_max);
	for (int i = 0; i < n; i++) {
		numbers[i] = dis(gen);

		cout << numbers[i] << " ";
	}
	cout << endl;

	int* result1 = new int[abs(x_max - x_min) + 1];
	int* result2 = new int[n_int];
	int* result3 = new int[n_int];
	for (int i = 0; i < abs(x_max - x_min) + 1; i++) {
		result1[i] = 0;
	}
	for (int i = 0; i < n_int; i++) {
		result2[i] = 0;
		result3[i] = 0;
	}

	first_dist(numbers, n, result1, x_min, &mid);
	for (int i = 0; i < abs(x_max - x_min); i++) {
		cout << i + x_min << ": " << result1[i] << " | ";
	}
	cout << to_string(abs(x_max - x_min) + x_min) << ": " << result1[abs(x_max - x_min)] << endl;
	second_dist(result1, intervals, result2, x_max + 1, x_min, n_int);
	task_dist(numbers, n, intervals, result3, n_int);

	ofstream file("table.txt");
	auto head = "n_int\tLg\tvalue\tx%2==0";
	file << head << endl;
	cout << head << endl;
	for (int i = 0; i < n_int; i++) {
		auto line = to_string(i) + "\t" + to_string(intervals[i]) + "\t" + to_string(result2[i]) +"\t" + to_string(result3[i]) + "\n";
		file << line;
		cout << line;
	}
	//	cout << mid << endl;
	system("Pause");
	return 0;
}