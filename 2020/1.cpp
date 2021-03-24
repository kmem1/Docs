#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b % a, a);
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	int n, m;
	cin >> n >> m;

	if (n < m) {
		int g = gcd(n, m);
		cout << "Несократимая дробь: " << n / g << '/' << m / g;
	} else {
		cout << "Несократимая дробь: " << endl;
		cout << "Целая часть: " << n / m << ". ";
		n = n % m;
		if (n != 0) {
			int g = gcd(n, m);
			cout << "Дробная часть: " << n / g << '/' << m / g;
		}
	}
}
