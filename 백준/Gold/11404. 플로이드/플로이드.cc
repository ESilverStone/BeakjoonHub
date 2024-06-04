#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> cost;   // 최소 비용 기록

void floyd() {

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] > cost[i][k] + cost[k][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    // 초기화
    cost.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cost[i][j] = 0;
        }
    }


    for (int i = 0; i < m; i++) {
        // 시작점, 도착점, 비용
        int s, e, c;    
        cin >> s >> e >> c;

        // 전체 배열에 기록
        // 단방향
        cost[s][e] = min(cost[s][e], c);
    }

    floyd();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost[i][j] == INF) {
                cout << 0 << " ";
            }
            else {
                cout << cost[i][j] << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}