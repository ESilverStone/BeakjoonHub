#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

int n, m;
int max_sum = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;

int dicX[4] = { 0, 1 ,0, -1 };
int dicY[4] = { 1, 0 ,-1, 0 };

void repeat(int x, int y, int count, int sum) {
    // 최종 도달
    if (count == 4) {
        if (max_sum < sum) max_sum = sum;

        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dicX[i];
        int ny = y + dicY[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        if (visited[nx][ny]) continue;

        // 설정
        visited[nx][ny] = true;

        // 재귀
        repeat(nx, ny, count + 1, sum + arr[nx][ny]);

        // 설정 초기화
        visited[nx][ny] = false;

    }
}


// ㅗ 경우 >> 한 지점에서 상하좌우를 검사 후 3가지 값을 가져온다.
int except_case(int x, int y) {
    int cnt = 0;
    int sum = arr[x][y];
    int min_val = INT_MAX;

    for (int i = 0; i < 4; i++) {
        int nx = x + dicX[i];
        int ny = y + dicY[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        
        cnt++;
        sum += arr[nx][ny];
        min_val = min(min_val, arr[nx][ny]);    // 검사한 것중 제일 낮은거
    }

    if (cnt < 3) return 0;              // 모서리에 있어 3개를 충족하지 못한 경우.
    else if (cnt == 3) return sum;      // 벽에 붙어서 정확히 3개를 충족한 경우.
    else return sum - min_val;          // 4개 다 검사된 경우 >> 제일 낮은 숫자를 뺀다. 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    
    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int max_ans = 0;

    // 모든 포지션에서 테트로미노 검사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // 재귀로 이어진 4칸 검사
            visited[i][j] = true;
            repeat(i, j, 1, arr[i][j]);
            visited[i][j] = false;

            max_ans = max(max_sum, max_ans);

            // 예외 경우 검사
            max_ans = max(except_case(i, j), max_ans);
        }
    }

    
    cout << max_ans;
    

    return 0;
}