#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> visited;
vector<int> arr;

void back_track(int s, int c) {

    if (c == m) {
        // 출력
        for (int k : arr) {
            cout << k << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = s; i <= n; i++) {

        if (visited[i]) continue;

        visited[i] = true;
        arr[c] = i;
        back_track(i + 1, c + 1);
        visited[i] = false;

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    visited.resize(n + 1);
    arr.resize(m);
    
    back_track(1, 0);

    return 0;
}