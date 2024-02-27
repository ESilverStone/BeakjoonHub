#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		
		// 값을 입력 받는다.
		string input;
		cin >> input;

		// 0이면 탈출
		if (input == "0") break;

		// 입력된 값을 분할 후 벡터에 저장
		vector<char> digits;
		for (char digit : input) {
			digits.push_back(digit);
		}

		bool isFel = true;
		for (int i = 0; i < digits.size()/2; i++) {
			if (digits[i] != digits[digits.size() - 1 - i]) {
				isFel = false;
				break;
			}
		}

		if (isFel) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}