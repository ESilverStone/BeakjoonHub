#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int count = 5;
	vector<int> nums(count);

	int num = 0;
	int sum = 0;
	for (int i = 0; i < count; i++) {
		cin >> num;
		nums[i] = num;

		sum += pow(num, 2);
	}

	int result;
	result = sum % 10;

	cout << result;

	return 0;
}