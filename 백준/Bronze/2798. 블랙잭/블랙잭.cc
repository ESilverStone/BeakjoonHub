#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// n 카드 수, m 합산 값
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end()); // 배열 정렬

	int maxValue = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = arr[i] + arr[j] + arr[k];

				if (sum > m) continue;

				if (sum > maxValue) {
					maxValue = sum;
				}
			}
		}
	}

	cout << maxValue;

	return 0;
}