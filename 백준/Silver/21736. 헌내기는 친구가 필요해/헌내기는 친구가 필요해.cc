#include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <queue>


    using namespace std;


    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;

        vector<string> arr(n);
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        pair<int, int> start;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];

            for (int j = 0; j < m; j++) {
                
                if (arr[i][j] == 'I') {
                    start = { i,j };
                }
            }

        }



        // bfs
        queue<pair<int, int>> que;
        que.push(start);
        visited[start.first][start.second] = true;

        int dirX[] = {0, 1, 0, -1};
        int dirY[] = {-1, 0, 1, 0};

        int cnt = 0;

        while (!que.empty()) {
            int X = que.front().first;
            int Y = que.front().second;

            que.pop();


            for (int i = 0; i < 4; i++) {
                int newX = X + dirX[i];
                int newY = Y + dirY[i];

                if (newX < 0 || newY < 0 || newX >= n || newY >= m) {
                    continue;
                }

                if (visited[newX][newY]) continue;

                if (arr[newX][newY] == 'P') cnt++;

                visited[newX][newY] = true;

                if (arr[newX][newY] == 'X') continue;

                que.push(pair<int, int>(newX, newY));

            }
            

        }

        if (cnt == 0) {
            cout << "TT";
        }
        else {
            cout << cnt;
        }

        
        return 0;
    }