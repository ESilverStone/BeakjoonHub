#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		
		arr[i] = input;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}