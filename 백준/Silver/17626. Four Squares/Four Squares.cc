#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

vector<int> memo;

int cal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    

    // 기억하고 있는 숫자면
    if (memo[n] != -1) {
        return memo[n];
    }

    // 다 1인 경우, n이 최대 값
    int result = n;

    // 1부터 n의 제곱근까지
    for (int i = 1; i * i <= n; i++) {
        result = min(result, cal(n - i * i) + 1);
    }

    return memo[n] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    memo.resize(n + 1, -1);

    cout << cal(n);


    return 0;
}