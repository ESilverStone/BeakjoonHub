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
	int num = 0;
	// 내가 원하는 번째의 숫자를 찾으면 끝
	while (count != N) {

		num++;

		int temp = num;

		while (temp != 0 ) {
			if (temp % 1000 == 666) {
				count++;
				break;
			}
			temp /= 10;
		}
	}

	cout << num;
}