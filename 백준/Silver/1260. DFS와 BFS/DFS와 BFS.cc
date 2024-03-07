#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int n) {
    // 이미 방문한 노드 일 경우
    if (visited[n]) return;

    visited[n] = true;
    cout << n << " ";

    for (int m : graph[n]) {

        if (visited[m]) continue;

        dfs(m);
    }
}


void bfs(int v) {

    queue<int> que; 
    que.push(v);
    visited[v] = true;

    while (!que.empty()) {
        int f = que.front();
        que.pop();

        cout << f << " ";

        for (int m : graph[f]) {
            
            if (visited[m]) continue;

            visited[m] = true;
            que.push(m);
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // n : 정점, m : 간선, v : 시작 번호
    int n, m, v;
    cin >> n >> m >> v;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int num1, num2;
        cin >> num1 >> num2;

        // 간선 입력
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << "\n";

    fill(visited.begin(), visited.end(), false);

    bfs(v);


    return 0;
}