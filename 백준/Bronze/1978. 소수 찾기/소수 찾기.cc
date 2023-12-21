#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test;

	cin >> test;

	int count = 0;

	for (int t = 0; t < test; t++) {
		int num;

		cin >> num;

		bool sosu = true;

		for (int i = 2; i < num; i++) {
			if (num % i == 0)
			{
				sosu = false;
				break;
			}
		}

		if (num == 1) sosu = false;

		if (sosu) count++;

	}

	cout << count;
	
	return 0;
}