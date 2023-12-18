#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;


	if (n % 4 == 0) {

		if (n % 100 != 0 || n % 400 ==0) {
			cout << 1;
		}
		else {

			cout << 0;
		}
	}
	else {
		cout << 0;
	}


	return 0;
}