#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {

		int  h, w, n;
		cin >> h >> w >> n;

		int x = n % h;

		int y = n / h;
		if (x == 0) {
			x = h;
		}
		else {
			y++;
		}

		cout << x * 100 + y << endl;



	}
	
	
	return 0;
}