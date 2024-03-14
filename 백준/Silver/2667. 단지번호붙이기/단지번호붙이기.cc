#include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <queue>


    using namespace std;


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            int cnt = 0;

            for (char c : s) {
                if (c == '0') {
                    arr[i][cnt] = 0;
                }
                else {
                    arr[i][cnt] = 1;
                }
                cnt++;
            }
        }

        int dirU[] = { 0,-1,0,1 };
        int dirV[] = { -1,0,1,0 };

        int cntK = 0;

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
            {
                // 0이거나 방문했으면 다음꺼
                if (arr[i][j] == 0 || visited[i][j]) continue;

                // bfs
                queue<pair<int, int>> que;
                pair<int, int> start = { i,j };
                int cnt = 0;

                que.push(start);
                visited[i][j] = true;

                while (!que.empty()) {
                    int u = que.front().first;
                    int v = que.front().second;

                    que.pop();

                    // 4방향 검사
                    for (int d = 0; d < 4; d++) {
                        int nu = u + dirU[d];
                        int nv = v + dirV[d];

                        // 아웃레인지
                        if (nu < 0 || nv < 0 || nu >= n || nv >= n) continue;

                        // 0이든 1이든 검사하였다고 표시
                        // if (arr[nu][nv] == 0) visited[nu][nv] = true;

                        // 1이고 방문하지 않았다면
                        if (arr[nu][nv] == 1 && !visited[nu][nv]) {
                            cnt++;
                            visited[nu][nv] = true;
                            que.push(pair<int, int>{nu, nv});
                        }
                    }
                }

                cntK++;

                ans.push_back(cnt + 1);
                

            }
        }


        cout << cntK << "\n";

        std::sort(ans.begin(), ans.end());

        for (int i : ans) {
            cout << i << "\n";
        }
        
        return 0;
    }