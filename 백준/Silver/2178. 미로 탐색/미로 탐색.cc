#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<bool>> visited;

struct Pos {
    int x;
    int y;
};

int dicX[] = { 0,1,0,-1 };
int dicY[] = { 1,0,-1,0 };


void bfs() {

    queue<Pos> q;
    q.push(Pos{ 0,0 });
    visited[0][0] = true;

    while (!q.empty()) {

        Pos pos = q.front();
        q.pop();

        if (pos.x == n - 1 && pos.y == m - 1) break;



        for (int i = 0; i < 4; i++) {
            int CurX = pos.x + dicX[i];
            int CurY = pos.y + dicY[i];


            // 나가리
            if (CurX < 0 || CurY < 0 || CurX >= n || CurY >= m) continue;

            if (visited[CurX][CurY] || arr[CurX][CurY] == 0) continue;

            visited[CurX][CurY] = true;
            arr[CurX][CurY] = arr[pos.x][pos.y] + 1;
            q.push(Pos{ CurX, CurY });


        }


    }
  
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    // 입력
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
   
    bfs();


    cout << arr[n - 1][m - 1]; // 목적지까지의 최단 거리 출력


    return 0;
}