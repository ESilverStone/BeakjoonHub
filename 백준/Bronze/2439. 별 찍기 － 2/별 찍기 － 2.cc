#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i + j + 2 > n) {
				cout << "*";
			}
			else {
				cout << " ";
			}

		}
			cout << "\n";
	}
	
	return 0;
}