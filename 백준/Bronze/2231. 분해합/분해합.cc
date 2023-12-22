#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int digitCount = static_cast<int>(log10(n)) + 1;

	int startNum = n - digitCount * 10;

	bool resist = false;
	int resultNum = 0;

	// 테스트
	for (int i = startNum; i < n; i++) {

		int result = i;
		int copy = i;

		int sum = 0;

		while (copy != 0) {
			sum += copy % 10;
			copy /= 10;
		}

		if (result + sum == n) {
			resist = true;
			resultNum = result;
			break;
		}
	}

	if (resist) {

		cout << resultNum;
	}
	else {
		cout << 0;
	}
	
	
	return 0;
}