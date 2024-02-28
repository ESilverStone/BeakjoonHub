#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    int m = 0;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    // 전체 판 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char BorW;
            cin >> BorW;
            
            // B : 0, W : 1
            if (BorW == 'B') arr[i][j] = 0;
            else             arr[i][j] = 1;
        }
    }

    int minCount = 64;

    // 8구간씩 검사하기
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {

            int count = 0;

            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    // 체스판의 시작이 'B'인 경우
                    if ((k + l) % 2 == 0) {
                        if (arr[k][l] != 0) count++;
                    }
                    // 체스판의 시작이 'W'인 경우
                    else {
                        if (arr[k][l] != 1) count++;
                    }
                }
            }

            // 현재 탐색한 8x8 체스판에서 칠해야하는 최소 칸 수 업데이트
            minCount = min(minCount, min(count, 64 - count));

        }
    }

    cout << minCount;


}