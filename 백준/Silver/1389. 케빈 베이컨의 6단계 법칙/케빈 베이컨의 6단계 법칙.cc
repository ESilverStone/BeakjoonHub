#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<vector<int>> arr;

int bfs(int start) {
	vector<int> range(n + 1, -1);
	queue<int> q;

	q.push(start);
	range[start] = 0;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int next : arr[current]) {
			if (range[next] != -1) continue;

			range[next] = range[current] + 1;
			q.push(next);
		}		
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += range[i];
	}

	return sum;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;

	arr.resize(n + 1, vector<int>());

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int min = INT_MAX;
	int person = -1;

	for (int i = 1; i <= n; i++) {
		int bNum = bfs(i);

		if (bNum < min) {
			min = bNum;
			person = i;
		}
	}
	cout << person;
}