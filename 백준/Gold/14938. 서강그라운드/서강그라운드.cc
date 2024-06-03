#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, r;
vector<vector<pair<int, int>>> graph;
vector<int> items;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost) continue;

        for (auto u : graph[node]) {
            int next_node = u.first;
            int weight = u.second;

            if (dist[next_node] > dist[node] + weight) {
                dist[next_node] = dist[node] + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;

    items.resize(n + 1);
    dist.resize(n + 1, INT_MAX);
    graph.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int ans_max = 0;

    for (int i = 1; i <= n; i++) {
        fill(dist.begin(), dist.end(), INT_MAX);
        dijkstra(i);

        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[j] <= m) sum += items[j];
        }

        ans_max = max(ans_max, sum);
    }

    cout << ans_max;

    return 0;
}