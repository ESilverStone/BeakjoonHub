#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}

	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// N개의 단어를 입력
	int N;
	cin >> N;

	// 단어들이 들어갈 배열
	vector<string> arr(N);

	for (int i = 0; i < N; i++) {
		string m;
		cin >> m;

		arr[i] = m;
	}

	sort(arr.begin(), arr.end(), compare);

	string memo = "0";
	// 출력
	for (int i = 0; i < N; i++) {
		
		if (memo != arr[i]) {
			cout << arr[i] << "\n";
		} 
		
		memo = arr[i];
	}
}