#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int n;
vector<vector<int>> arr;
vector<vector<int>> dp;

int sum = 0;
int min_sum = INT_MAX;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    arr.resize(n, vector<int>(3));
    dp.resize(n, vector<int>(3));

    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    // 초기값 설정
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    // dp를 사용해서 최소 비용 구하기
    // - 접근 -
    // 현재 집을 R / G / B로 칠했을 경우 최소비용을 따로 구한다.
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);
        dp[i][1] = min(dp[i - 1][0] + arr[i][1], dp[i - 1][2] + arr[i][1]);
        dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
    }

    // 출력
    int u = min(dp[n - 1][0], dp[n - 1][1]);
    int v = min(u, dp[n - 1][2]);
    
    cout << v;
    

    return 0;
}