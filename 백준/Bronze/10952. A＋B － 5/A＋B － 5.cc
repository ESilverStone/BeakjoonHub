#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	
	int a, b;
	// 입력이 끝날 때까지 반복
	while (true) {
		cin >> a >> b;

		if (a == 0 && b == 0) {
			break;
		}

		cout << a+b <<"\n";
	}

	return 0;
}