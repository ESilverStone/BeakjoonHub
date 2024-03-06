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

    int n, m;
    cin >> n >> m;

    // 인접 리스트
    vector<vector<int>> list(n + 1);

    for (int i = 0; i < m; i++) {
        int num1, num2;
        cin >> num1 >> num2;

        list[num1].push_back(num2);
        list[num2].push_back(num1);
    }

    // DFS
    vector<bool> visited(n + 1, false);
    stack<int> s;
    s.push(1);
    int count = 0;

    while(!s.empty()) {
        int current = s.top();
        s.pop();


        if (!visited[current]) {

            visited[current] = true;

            for (int next : list[current]) {
                if (!visited[next]) {
                    s.push(next);
                }
            }
        }

    }

    for (int i = 2; i <= n; i++) {
        if (visited[i]) count++;
    }

    cout << count;


    


    return 0;
}