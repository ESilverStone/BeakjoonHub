#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 9;


	int max = 0;
	int count = 0;
	for (int i = 0; i < 9; i++) {

		int num;
		cin >> num;

		if (max < num) {
			max = num;
			count = i + 1;
		}
	}

	cout << max << endl;
	cout << count;
	
	
	return 0;
}