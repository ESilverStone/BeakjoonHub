#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> arr(n, vector<int>(m));

    int maxH = 0;
    int minH = 256;

    // 땅 상태 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if (maxH < arr[i][j]) maxH = arr[i][j];
            if (minH > arr[i][j]) minH = arr[i][j];

        }
    }

    int minTime = INT_MAX;
    int ans = 0;

    // 땅을 0부터 최대치까지 다 검사
    for (int i = minH; i <= maxH; i++) {

        int addB = 0;
        int delB = 0;
        int time = 0;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                
                int block = arr[j][k];

                if (i < block) {
                    delB += (block - i);
                }
                else {
                    addB += (i - block);
                }

            }
        }

        // 조건1. 추가한 블록이 더 많을 경우
        if (delB + b < addB) break;

        time = delB * 2 + addB * 1;

        // 조건2. 시간이 오래걸림
        if (minTime < time) continue;
        else {
            minTime = time;
            ans = i;
        }
    }

    cout << minTime << " " << ans;


    return 0;
}