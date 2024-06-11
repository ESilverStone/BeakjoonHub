#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;

	cout << a + b - c << "\n";

	int sb = b;

	while (sb >= 10) {
		sb /= 10;
		a *= 10;
	}

	cout << a * 10 + b - c;

	return 0;
}