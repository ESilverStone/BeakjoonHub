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

    unordered_map<string, int> dic;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        dic.emplace(arr[i], i+1);
    }

    vector<string> ans(m);

    for (int i = 0; i < m; i++) {
        string temp;
        
        cin >> temp;

        // 입력이 포켓몬 이름일 경우 > 앞문자 대문자 영어
        if (temp[0] >= 65 && temp[0] <= 90) {
            cout << dic.at(temp) << "\n";
        }
        // 도감 번호 입력 받은 경우
        else {
            cout << arr[stoi(temp)-1] << "\n";
        }
    }

    return 0;
}