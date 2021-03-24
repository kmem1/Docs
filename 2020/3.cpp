#include <iostream>
#include <conio.h>

using namespace std;

const int max_n = 100;

char bitset[5];

string W[100000];

char alphabet[] = { 'A', 'B', 'C' };

void inc() {
	int i = 4;
	if (bitset[i] != 'C')
		bitset[i] += 1;
	else {
		bitset[i] = 'A';
		while (bitset[--i] == 'C' && i >= 0)
			bitset[i] = 'A';
		if (i >= 0)
			bitset[i] += 1;
	}
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	int n = pow(3,5);

	for (int i = 0; i < 5; i++)
		bitset[i] = 'A';


	cout << bitset << endl;
	W[0] = "AAAAA";
	for (int i = 0; i < n; i++) {
		inc();
		W[i + 1] = bitset;
	}

	while (true) {
		int k;
		cout << "Введите номер: ";
		cin >> k;
		if (k < 1 || k > n)
			cout << "Таких слов нет" << endl;
		else
			cout << W[k - 1] << endl;
		cout << "Выход - Escape, Продолжение - любая" << endl;
		if (_getch() == 27)
			return 0;
	}
}
