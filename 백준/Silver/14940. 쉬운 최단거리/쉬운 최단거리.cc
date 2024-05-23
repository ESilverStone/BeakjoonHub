#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> visited;

// 방향
int dicX[] = {1, 0, -1, 0};
int dicY[] = {0, -1, 0, 1};


// 좌표값
struct Pos {
    int x;
    int y;
};

// bfs에서 사용할 que 생성
// visited을 채워나간다. 
// 스타팅 지점부터 bfs로 접근 가능 지역에 값을 채워 넣는다.
void bfs(int startX, int startY) {
    
    // Que
    queue<Pos> que;
    Pos pos = { startX, startY };
    que.push(pos);

    // start 지점 설정
    visited[startX][startY] = 0;

    while (!que.empty()) {

        Pos currentPos = que.front();
        que.pop();

        // 방향 설정
        for (int i = 0; i < 4; i++) {
            int CurX = currentPos.x + dicX[i];
            int CurY = currentPos.y + dicY[i];

            // 인덱스를 초과하면 다음
            if (CurX < 0 || CurY < 0 || CurX >= n || CurY >= m) continue;

            if (visited[CurX][CurY] == -1 && arr[CurX][CurY] != 0)
            {
                // 조건을 다 통과 하였다면 큐에 넣어준다.
                Pos nextPos = { CurX, CurY };
                que.push(nextPos);

                // 출발지점과 떨어진 거리
                visited[CurX][CurY] = visited[currentPos.x][currentPos.y] + 1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<int>(m, -1));
    visited.resize(n, vector<int>(m, -1));

    int startingX = 0, startingY = 0;

    // 지도 값 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                startingX = i;
                startingY = j;
            }
        }
    }

    // BFS 연산
    bfs(startingX, startingY);

    visited[startingX][startingY] = 0;

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                cout << 0 << " ";
            }
            else {
                cout << visited[i][j] << " ";
            }
        }
        cout << "\n";
    } 
    return 0;
}