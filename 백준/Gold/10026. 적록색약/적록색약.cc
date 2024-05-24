#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<vector<int>> arr;
vector<vector<bool>> visited;

int dicX[] = { 1, 0, -1, 0 };
int dicY[] = { 0, -1, 0, 1 };

struct Pos {
    int x;
    int y;
};

void RGB(int startX, int startY) {
    stack<Pos> st;
    st.push({ startX, startY });
    visited[startX][startY] = true;
    int c = arr[startX][startY];

    while (!st.empty()) {
        Pos curPos = st.top();
        st.pop();

        for (int i = 0; i < 4; i++) {
            int posX = curPos.x + dicX[i];
            int posY = curPos.y + dicY[i];

            // 범위 넘어갈 시
            if (posX < 0 || posY < 0 || posX >= n || posY >= n) continue;

            // 이미 방문시
            if (visited[posX][posY]) continue;

            // 다른 RGB일 시
            if (arr[posX][posY] != c) continue;

            visited[posX][posY] = true;
            st.push({ posX, posY });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    arr.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));  // 초기화

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            char c = str[j];
            if (c == 'R') {         // R = 1
                arr[i][j] = 1;
            }
            else if (c == 'G') {  // G = 2
                arr[i][j] = 2;
            }
            else {                // B = 3
                arr[i][j] = 3;
            }
        }
    }

    int countRGB = 0;
    int countRRB = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            RGB(i, j);
            countRGB++;
        }
    }

    // visited 배열을 다시 초기화
    visited.assign(n, vector<bool>(n, false));

    // 초록색을 빨강으로 변경
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 2) arr[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            RGB(i, j);
            countRRB++;
        }
    }

    cout << countRGB << " " << countRRB;

    return 0;
}