#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int a;
		int b;

		cin >> a >> b;
		cout << a + b << "\n";

	}

	return 0;
}