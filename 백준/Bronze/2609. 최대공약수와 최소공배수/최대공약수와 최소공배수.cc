#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 두 숫자 입력
	int n, m;
	cin >> n >> m;

	int min, max;

	if (n < m) {
		min = n;
		max = m;
	}
	else {
		min = m;
		max = n;
	}

	// 최대 공약수
	int result1 = 1;
	for (int i = 1; i <= min; i++) {
		if (max % i == 0 && min % i == 0) result1 = i;
	}

	// 최소 공배수
	int result2 = 0;
	for (int i = 1; i <= min; i++) {
		if (max * i % min == 0) {
			result2 = max * i;
			break;
		}
	}

	cout << result1 << "\n";
	cout << result2;

}