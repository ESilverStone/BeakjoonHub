#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int max = -1000000;
	int min = 1000000;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		
		if (num > max) {
			max = num;
		}

		if (num < min) {
			min = num;
		}
	}
	
	cout << min <<" "<< max;
	
	
	return 0;
}