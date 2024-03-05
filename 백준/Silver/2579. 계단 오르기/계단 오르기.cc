#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> dp;
vector<int> score;

int logic(const int& n) {

    if (n <= 0) return 0;

    if (dp[n] != -1) return dp[n];

    dp[n] = max(score[n] + logic(n - 2), score[n] + score[n - 1] + logic(n - 3));
    
    return dp[n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    dp.resize(n + 1, -1);
    score.resize(n + 1);

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> score[i + 1];
    }

    cout << logic(n);

    return 0;
}