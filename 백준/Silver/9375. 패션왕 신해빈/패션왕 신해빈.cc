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
    

    while (t--) {
        int n;
        cin >> n;

        unordered_map<string, int> clothes;

        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;

            // 같은 타입의 옷이 없다면
            if (clothes.find(type) == clothes.end()) {
                clothes[type] = 1;
            }
            // 같은 타입의 옷이 이미 있다면
            else {
                clothes[type]++;
            }
        }

        int result = 1;
        for (auto& v : clothes) {
            result *= (v.second + 1);
        }

        cout << result - 1 << "\n";
    }
    


    return 0;
}