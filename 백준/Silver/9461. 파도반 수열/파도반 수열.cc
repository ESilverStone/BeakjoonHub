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

    int t;
    cin >> t;
    
    vector<long long> arr(101);
    arr[0] = 0;
    arr[1] = arr[2] = arr[3] = 1;
    arr[4] = 2;


    while (t--) {
        int num;
        cin >> num;

        if (num > 4) {
            for (int i = 5; i <= num; i++) {
                arr[i] = arr[i - 1] + arr[i - 5];
            }
        }
        cout << arr[num] << "\n";
    } 

    return 0;
}