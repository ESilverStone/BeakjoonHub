#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	
	getline(cin, str);

	int count = 0;

	bool countReadyReady = false;
	bool countReady = false;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (countReadyReady) {

				countReady = true;
			}
		}
		else {
			if (countReady) {
				count++;
				countReady = false;
			}
			countReadyReady = true;
		}
	}

	if (countReadyReady) {
		cout << count+1;
	}
	else {
		cout << 0;
	}

	
	
	return 0;
}