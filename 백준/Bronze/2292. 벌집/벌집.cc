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

	int sum = 1;
	int num = 0;

	while (n!=1) {
		sum += num * 6;

		if (n <= sum) {
			break;
		}

		num++;
	}

	cout << num + 1;
	
	
	return 0;
}