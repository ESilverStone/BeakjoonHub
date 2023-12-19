#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;

	cin >> str;

	int alpha[26];

	fill(alpha, alpha + 26, 0);


	for (int i = 0; i < str.length(); i++) {

		if ('a' <= str[i] && str[i] <= 'z') {
			alpha[str[i] - 'a']++;
		}
		else {
			alpha[str[i] - 'A']++;
		}
	}

	int max = 0;
	bool same = false;
	int maxNum = 0;

	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			maxNum = i;
			same = false;
		}
		else if (alpha[i] == max) {
			same = true;
		}
	}

	char result = 'A' + maxNum;

	if (same) cout << "?";
	else cout << result;
	
	return 0;
}