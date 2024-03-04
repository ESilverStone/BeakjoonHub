#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> arr;
    arr.resize(n);
    
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxLen = max(maxLen, arr[i]);
    }

    long long left = 1; 
    long long right = maxLen;
    long long ans = 0;

    while (left <= right) { 
        // 중간값
        long long mid = (left + right) / 2; 
        
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i] / mid;
        }

        if (sum >= m) {
            left = mid + 1;

            ans = max(ans, mid);
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}