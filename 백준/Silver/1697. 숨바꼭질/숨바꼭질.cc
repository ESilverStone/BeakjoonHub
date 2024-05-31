#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
vector<bool> arr;
vector<int> dist;


void bfs(int n) {

    queue<int> q;
    q.push(n);
    arr[n] = true;

    while (!q.empty())
    {
        int curPos = q.front();
        q.pop();
        

        if (curPos == k) break;


        // -1
        if (curPos - 1 >= 0 && !arr[curPos - 1]) {
            arr[curPos - 1] = true;
            dist[curPos - 1] = dist[curPos] + 1;
            q.push(curPos - 1);
        }

        // +1
        if (curPos + 1 <= 100000 && !arr[curPos + 1]) {
            arr[curPos + 1] = true;
            dist[curPos + 1] = dist[curPos] + 1;
            q.push(curPos + 1);
        }

        // *2
        if (curPos * 2 <= 100000 && !arr[curPos * 2]) {
            arr[curPos * 2] = true;
            dist[curPos * 2] = dist[curPos] + 1;
            q.push(curPos * 2);
        }

    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    arr.resize(100001, false);
    dist.resize(100001, 0);

    bfs(n);

    cout << dist[k];


    return 0;
}