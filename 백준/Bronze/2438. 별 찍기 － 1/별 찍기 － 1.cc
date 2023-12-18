#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x;

	cin >> x ;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}