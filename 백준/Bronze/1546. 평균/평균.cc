#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 과목 수 입력
	int n;
	cin >> n;

	vector<int> score;		
	int max = 0;
	float sum = 0;
	for (int t=0; t < n; t++) {


		// 점수
		int m;
		cin >> m;

		if (max < m) max = m;

		score.push_back(m);
		sum += m;
	}
	sum = ((sum * 100) / max) / n;
	cout << sum;
}