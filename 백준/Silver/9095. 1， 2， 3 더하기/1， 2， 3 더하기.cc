#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> memo(12, 0);

int logic(const int& n) {
    
    if (n < 0) return 0;
    if (n == 0) return 1;

    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = logic(n - 1) + logic(n - 2) + logic(n - 3);
    
    return memo[n];
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        cout << logic(num) << "\n";

    }



    return 0;
}