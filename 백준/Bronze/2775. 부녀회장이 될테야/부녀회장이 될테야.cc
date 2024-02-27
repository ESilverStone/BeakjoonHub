#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sumPerson(int k, int n) {

	// k와 n 중 1(0)이 되는 시점에 사람 명수를 확정할 수 있다.
	if (k == 0) return n;
	if (n == 1) return 1;

	// k층 n호의 사람은 (k-1,n)와 (k, n-1)의 합이다. 
	return sumPerson(k - 1, n) + sumPerson(k, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 테스트 수
	int test;
	cin >> test;

	for (int t = 0; t < test; t++)
	{
		// k : 층, n : 호
		int k, n;
		cin >> k >> n;

		// 값 출력
		cout << sumPerson(k, n) << "\n";
	}
}