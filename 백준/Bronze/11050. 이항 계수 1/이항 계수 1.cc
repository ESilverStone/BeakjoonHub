#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int a = 1;
	int b = 1;

	for (int i = 1; i <= k; i++) {
		b *= i;
	}

	for (int i = n - k + 1; i <= n; i++) {
		a *= i;
	}
	cout << a / b;

}