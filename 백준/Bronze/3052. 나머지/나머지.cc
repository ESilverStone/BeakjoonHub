#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int arr[42] = {0};

	for (int i = 0; i < 10; i++) {
		int num = 0;
		cin >> num;

		arr[num % 42]++;
	}

	int count = 0;
	for (int i = 0; i < 42; i++)
	{
		if (arr[i] != 0) count++;
	}

	cout << count;
	
	return 0;
}