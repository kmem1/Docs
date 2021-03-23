#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string reformat(string s);

int main()
{
	setlocale(LC_CTYPE, "rus");
	char buff[100];
	vector<string> v1 = { };

	ifstream fin("file.txt");
	ofstream fout("output.txt");
	while (fin.getline(buff, 100)) {
		cout << buff << endl;
		fout << buff << endl;
		v1.push_back(reformat(buff));
	};

	cout << endl << "Упорядоченный список" << endl;
	fout << endl << "Упорядоченный список" << endl;

	std::sort(v1.begin(), v1.end());

	int n = v1.size();
	for (int i = 0; i < n; i++) {
		cout << v1[i] << endl;
		fout << v1[i] << endl;
	}
}

string reformat(string s) {
	int n = s.size();
	char s1[100];

	int j = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') {
			k++;
			if (k == 1)
				s1[j++] = s[i];
			s1[j++] = s[i + 1];
			s1[j++] = '.';
		}

		if (k == 0)
			s1[j++] = s[i];
	}

	s1[j] = '\0';

	return s1;
}
