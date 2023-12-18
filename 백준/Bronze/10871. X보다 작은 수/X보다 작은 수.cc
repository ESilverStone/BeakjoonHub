#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int x;

	cin >> n >> x;
	
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num < x) {
			cout << num << " ";
		}
	}

	return 0;
}