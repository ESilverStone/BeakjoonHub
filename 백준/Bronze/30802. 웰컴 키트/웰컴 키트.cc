#include <iostream>
#include <vector>


using namespace std;

int n; // 참가자 수
int t, p;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	vector<int> size(6);

	for (int i = 0; i < 6; i++) {
		cin >> size[i];
	}
	
	cin >> t >> p;

	// 옷
	int c = 0;
	int ans = 0;
	for (int i : size) {
		if (i % t == 0) {
			ans += (i / t);
		}
		else {
			ans += (i / t) + 1;
		}
	}

	cout << ans << "\n";

	// 펜 주문
	int m = n / p;
	int k = n - m * p;

	cout << m << " " << k;
	
	return 0;
	
}