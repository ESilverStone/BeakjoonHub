#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n + 1);

    arr[1] = 1;
    arr[2] = 2;

    if (n >= 3) {

        for (int i = 3; i <= n; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;

        }
    }

    cout << arr[n];


    return 0;
}