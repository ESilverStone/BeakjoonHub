#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <climits>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    vector<int> tree(N, 0);


    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    int left = 0;
    int right = INT_MAX;

    int middle = 0;
    int result = 0;

    while (left < right) {
        middle = (left + right) / 2;

        long sum = 0;

        for (int i = 0; i < N; i++) {
            if (tree[i] > middle)
                sum += (tree[i] - middle);

        }

        // M 목표치 보다 크다면 성공
        if (M <= sum) {
            result = middle;

            // 많이 남을 수 있으므로 left 값을 올린다.
            left = middle + 1;
        }
        else {
            // 덜 남았으므로 right값을 낮춘다.
            right = middle;
        }
    }
    cout << result;

    return 0;
}