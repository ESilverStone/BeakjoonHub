#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
vector<vector<int>> arr;
queue<pair<int, int>> que;

int dicX[4] = { 1,0,-1,0 };
int dicY[4] = { 0,-1,0,1 };

void bfs() {

    while (!que.empty()) {
        auto current = que.front();
        
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.first + dicX[i];
            int ny = current.second + dicY[i];
        
            // 배열 범위를 넘어갈 경우
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            // 방문하거나 -1인 경우
            if (arr[nx][ny] != 0) continue;

            // 날짜를 기록한다.
            arr[nx][ny] = arr[current.first][current.second] + 1;
            
            que.push({ nx, ny });
        }


    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 가로 / 세로
    cin >> m >> n;

    arr.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) que.push({ i,j });
        }
    }

    bfs();

    // 0이 있는지 검산
    int max_date = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                max_date = 0;
                goto end;
            }
            if (arr[i][j] > max_date) max_date = arr[i][j];

        }
    }end:


    cout << max_date - 1;


    return 0;
}