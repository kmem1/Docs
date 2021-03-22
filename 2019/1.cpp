#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	int n1, n2;
	bool isValidNumbers = false;
	cout << "Введите два номера колонок - ";
	while (!(cin >> n1 >> n2)) {
		cout << "Введите два номера колонок - ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	n1++;
	while (n1 % 3 != 1)
		n1++;


	while (n2 % 3 != 1)
		n2--;

	int k = 0;

	for (int i = n1; i < n2; i += 3)
		k++;

	cout << "Количество страниц: " << k;
}
