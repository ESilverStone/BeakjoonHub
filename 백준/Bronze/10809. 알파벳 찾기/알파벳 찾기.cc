#include <iostream>
#include <string>
#include <algorithm>  // for std::fill

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;

	cin >> str;

	int alpha[26];

	fill(alpha, alpha + 26, -1);

	for (int i = 0; i < str.length(); i++) {
		int order = str[i] - 'a';

		if (alpha[order] != -1) continue;

		alpha[order] = i;
	}

	for (int i = 0; i < size(alpha); i++) {
		cout << alpha[i] << " ";
	}
	
	return 0;
}