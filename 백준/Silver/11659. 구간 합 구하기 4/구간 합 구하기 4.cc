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

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);

    // 누적합을 저장하자
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int ipt;
        cin >> ipt;

        sum += ipt;

        arr[i + 1] = sum;
    }
    
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        int result = arr[e] - arr[s - 1];

        cout << result << "\n";
    }

    return 0;
}