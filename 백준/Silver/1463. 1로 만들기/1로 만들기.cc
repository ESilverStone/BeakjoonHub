#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> memo;

int logic(const int& n) {

    if (n == 1) {
        return 0;
    }

    if (memo[n] != -1) return memo[n];


    if (n % 6 == 0) {
        memo[n] = min(1+logic(n/3), 1+ logic(n/2));
    }
    else if (n % 3 == 0) {
        memo[n] = min(1 + logic(n / 3), 1 + logic(n - 1));
    }
    else if (n % 2 == 0) {
        memo[n] = min(1 + logic(n / 2), 1 + logic(n - 1));
    }
    else {
        memo[n] = 1 + logic(n - 1);
    }

    return memo[n];


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    memo.resize(n + 1, -1);
    
    memo[1] = 0;
    memo[2] = memo[3] = 1;
    
    int ans = logic(n);
    cout << ans;

    return 0;
}