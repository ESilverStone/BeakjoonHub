#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int count = 0;

	// 2의 개수가 5의 개수보다 많으므로 5의 개수만 카운트해주면된다.
	for (int i = 1; i <= N; i++) {

		int temp = i;
		while (temp != 0) {

			if (temp % 5 == 0) {
				count++;
			}
			else {
				break;
			}
			
			temp /= 5;
		}
	}

	cout << count;
}