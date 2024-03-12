#include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <queue>


    using namespace std;

    int n, m;

    vector<vector<int>*> nodes;
    vector<bool> visited;

    // visited 벡터를 true로 만드는 역할
    void dfs(int num) {

        visited[num] = true;

        // 노드 n과 인접한 모든 노드 검사
        for (int i = 1; i <= n; i++) {

            if ((*nodes[num])[i] == 0 || visited[i]) continue;

            dfs(i);
        }

    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> n >> m;

        nodes.resize(n + 1);
        visited.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            nodes[i] = new vector<int>(n + 1);
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            (*nodes[u])[v] = (*nodes[v])[u] = 1;            
        }

        int cnt = 0;

        // 검사
        for (int i = 1; i <= n; i++) {

            if (!visited[i]) {
                dfs(i);
                cnt++;
            }
        }

        cout << cnt;
        
        
        for (int i = 1; i <= n; i++) {
            delete nodes[i];
        }

        return 0;
    }