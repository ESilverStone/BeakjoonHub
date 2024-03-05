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

    unordered_map<string, string> list;

    for (int i = 0; i < n; i++) {
        string site;
        string pw;

        cin >> site >> pw;

        list.emplace(site, pw);
    }

    for (int i = 0; i < m; i++) {
        string ans;
        cin >> ans;

        cout << list.at(ans) << "\n";

    }

    
    return 0;
}