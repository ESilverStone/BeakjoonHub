#include <iostream>
#include <vector>

using namespace std;

struct pipe {
    // 0 : ㅡ
    // 1 : \
    // 2 : ㅣ
    vector<int> session = {0,0,0};

    pipe() : session({ 0,0,0 }) {};

    pipe(int a, int b, int c) : session({ a, b, c }) {}
};

int n;
vector<vector<int>> arr;
vector<vector<pipe>> field;

bool canBuild(int x, int y) {
    if (arr[x - 1][y] == 1 || arr[x][y - 1] == 1) return false;
    else return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    arr.resize(n, vector<int>(n));
    field.resize(n, vector<pipe>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            field[i][j] = pipe{ 0,0,0 };
        }
    }

    // 검사
    field[0][1].session[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // 해당 지역이 막힌 경우
            if (arr[i][j] == 1 || (i==0 && j==1)) {
                continue;
            }

            // 가로
            // 왼쪽 지역의 0, 1의 합
            if (j != 0) 
            {
                int sum = field[i][j - 1].session[0] + field[i][j - 1].session[1];
                field[i][j].session[0] = sum;
            }

            // 세로 
            // 위쪽 지역의 1, 2의 합
            if (i != 0) 
            {
                int sum = field[i - 1][j].session[1] + field[i - 1][j].session[2];
                field[i][j].session[2] = sum;
            }

            // 대각선
            // 좌측 상단 지역의 0,1,2의 합
            // 설치 가능 지역인지 판단
            if (i != 0 && j != 0) 
            {
                if (canBuild(i, j)) 
                {
                    int sum = field[i - 1][j - 1].session[0] + field[i - 1][j - 1].session[1] + field[i - 1][j - 1].session[2];
                    field[i][j].session[1] = sum;
                }
            }
        }
    }

    // 출력
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans += field[n - 1][n - 1].session[i];
    }

    cout << ans;
    
    return 0;
}