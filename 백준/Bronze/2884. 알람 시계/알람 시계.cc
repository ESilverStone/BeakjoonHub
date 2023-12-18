#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;

	cin >> a >> b;

	if (b < 45) {
		b = b + 60 - 45;
		
		if (a == 0) {
			a = 23;
		}
		else {
			a--;
		}
	}
	else {
		b -= 45;
	}

	cout << a << " " << b;
	
	
	return 0;
}