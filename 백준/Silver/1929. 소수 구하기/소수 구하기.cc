#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <climits> // INT_MAX
#include <string>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int M, N;
    cin >> M >> N;

    vector<int> arr(N + 1, 1);

    // 소수 판별 범위
    for (int i = 2; i * i <= N; i++) {

        // 이미 누군가의 배수이면 아웃
        if (arr[i] == -1) continue;

        // i의 배수 컷
        for (int j = i*i; j <= N; j+=i) {
            arr[j] = -1;
        }

    }
    int count = 0;

    arr[0] = arr[1] = -1;
    arr[2] = 1;

    for (int i = 0; i <= N; i++) {
        if (arr[i] == 1 && i >= M) cout << i << "\n";
    }

}