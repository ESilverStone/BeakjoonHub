#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> unit(n);

    for (int i = 0; i < n; i++) {
        cin >> unit[i];
    }

    int count = 0;

    for (int i = n - 1; i >= 0; i--) {

        if (unit[i] > m) continue;

        int k = m / unit[i];
        m -= k * unit[i];
        count += k;

        if (m == 0) break;
    }

    cout << count;


    return 0;
}