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

    unordered_map<string, int> nameList;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        nameList.insert({ name, i });
    }

    int count = 0;
    vector<string> arr;

    for (int j = 0; j < m; j++) {
        string temp;
        cin >> temp;

        auto it = nameList.find(temp);
        if (it != nameList.end()) {
            count++;
            arr.push_back(temp);
        }
    }

    cout << count << "\n";

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}