#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {

		int arr[3];

		int count = 0;

		for (int i = 0; i < 3; i++) {
			cin >> arr[i];

			if (arr[i] == 0) {
				count++;
			}
		}

		if (count == 3) break;


		sort(begin(arr), end(arr));

		if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2)) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}
	
	return 0;
}