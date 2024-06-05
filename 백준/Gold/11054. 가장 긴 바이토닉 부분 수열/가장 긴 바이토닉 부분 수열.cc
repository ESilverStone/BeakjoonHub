#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> arr(n);
    vector<int> dp_inc(n, 1);
    vector<int> dp_des(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 정방향 역방향을 dp로 구한 다음에
    // 해당 인덱스에 해당되는 값들을 더해서 최대값을 구한다.

    // 정방향 : 증가하는 가장 긴 부분 수열
    for (int i = 1; i < n; i++) {

        // 0 ~ i 까지 dp값들과 비교
        for (int j = 0; j < i; j++) {

            // 증가 수열의 조건을 만족한다면
            if (arr[j] < arr[i]) {
                dp_inc[i] = max(dp_inc[j] + 1, dp_inc[i]);
            }
        }
    }

    // 역방향 : (반대방향으로) 증가하는 가장 긴 부분 수열
    for (int i = n - 2; i >= 0; i--) {

        // 0 ~ i 까지 dp값들과 비교
        for (int j = n - 1; j >= i; j--) {

            // 감소 수열의 조건을 만족한다면
            if (arr[j] < arr[i]) {
                dp_des[i] = max(dp_des[j] + 1, dp_des[i]);
            }
        }
    }
    

    // 검사 및 출력
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = dp_des[i] + dp_inc[i];

        if (ans < sum) ans = sum;
    }

    cout << ans - 1;
    

    return 0;
}