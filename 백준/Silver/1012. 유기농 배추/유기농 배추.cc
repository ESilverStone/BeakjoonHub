#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

int n, m, k;

vector<vector<int>> arr;
vector<vector<int>> visited;

// 방향 벡터
int dirX[] = { 0, 1, 0, -1 };
int dirY[] = { -1, 0, 1, 0 };

// dfs의 역할 : 검사하면서 visited 배열 1로 만들기
void dfs(const int& i, const int& j) {

    // 0. 0 || visited
    if (visited[i][j] == 1) return;

    visited[i][j] = 1;

    // 1. 상 우 하 좌 순으로 1있는지 검사
    for (int d = 0; d < 4; d++) {
        int X = i + dirX[d];
        int Y = j + dirY[d];

        // 배열 침범
        if (X < 0 || X >= n || Y < 0 || Y >= m) continue;

        // 0이면 컷
        if (arr[X][Y] == 0) continue;

        dfs(X, Y);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        //int n, m, k;
        cin >> n >> m >> k;

        arr.assign(n, vector<int>(m, 0));
        visited.assign(n, vector<int>(m, 0));

        while (k--) {
            int i, j;
            cin >> i >> j;
            arr[i][j] = 1;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                // 검사 조건
                if (arr[i][j] == 0 || visited[i][j] == 1) continue;

                // dfs로 이웃한 노드 visited 1로 만들어주기
                dfs(i, j);

                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}