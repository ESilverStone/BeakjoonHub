#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct MT {
	int s;
	int e;
};

// 먼저 끝나는 시간 기준으로 정렬하기
bool compare(MT a, MT b) {
	if (a.e == b.e) return a.s < b.s;
	
	return a.e < b.e;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	vector<MT> arr;

	// 입력
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		MT mt = { a,b };

		arr.push_back(mt);
	}

	// 빨리 끝나는 시간으로 정렬
	sort(arr.begin(), arr.end(), compare);

	int count = 0;
	int end_time = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i].s >= end_time) {
			end_time = arr[i].e;
			count++;
		}
	}

	cout << count << endl;

	return 0;
	
}