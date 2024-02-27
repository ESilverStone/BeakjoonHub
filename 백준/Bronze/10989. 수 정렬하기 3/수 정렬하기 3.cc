#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> countingArr(10001);

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		
		countingArr[input]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (countingArr[i] != 0) {
			for (int j = 0; j < countingArr[i]; j++) {			
				cout << i << "\n";
			}
		}
	}
}