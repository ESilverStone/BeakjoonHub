#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x;
	int y;

	cin >> x >> y;

	if (x < y) {
		cout << "<";
	}
	else if (x > y) {

		cout << ">";
	}
	else {

		cout << "==";
	}

	return 0;
}