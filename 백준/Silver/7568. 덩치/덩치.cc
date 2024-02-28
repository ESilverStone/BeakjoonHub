#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    // 몸무게와 키를 저장할 2차원 벡터 생성
    vector<vector<int>> arr(N, vector<int>(3));
    vector<int> rank(N);

    // 몸무게와 키 조사
    for (int i = 0; i < N; i++) {
        int w, h;
        cin >> w >> h;

        // 벡터에 몸무게와 키 저장
        arr[i][0] = w;
        arr[i][1] = h;
        arr[i][2] = 0;

    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            if (i == j) continue;

            // 나보다 무거운지
            if (arr[i][0] < arr[j][0]) {

                // 나보다 키 큰지
                if (arr[i][1] < arr[j][1]) {
                    // 둘다 크면 ㅇㅈ
                    arr[i][2]++;
                }
            }
        }

    }

    for (int i = 0; i < N; i++) {
        cout << arr[i][2] + 1 << "\n";
    }


    return 0;
}