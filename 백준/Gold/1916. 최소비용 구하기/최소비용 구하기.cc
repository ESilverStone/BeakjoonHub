#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<pair<int, int>>> cities;  // 최소 비용 기록
vector<int> dist;                       // 각 도시까지의 비용 >> 정답지
priority_queue<pair<int, int>> pq;      // 기록지 >> 현재 진행형

void dijkstra(int start) {
    // 초기화
    dist.resize(n + 1, INF);
    
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        // 가장 낮은 비용의 도시를 뽑아야한다.
        auto current_city = pq.top().second;    // 현재 도시
        auto current_cost = pq.top().first;     // 현재 도시까지의 비용
        pq.pop();

        // 현 도시까지 비용이 이미 기록된 비용보다 크면 pass
        // 기록 중인 비용이 정답지보다 높다면 더 이상 기록할 필요가 없다.
        if (dist[current_city] < current_cost) continue;


        for (auto city : cities[current_city]) {
            int nCity = city.second;
            int nCost = city.first;

            if (dist[nCity] > nCost + dist[current_city]) {
                dist[nCity] = nCost + dist[current_city];

                pq.push({ dist[nCity] , nCity });
            }
        }

    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    // 초기화
    cities.resize(n + 1);

    for (int i = 0; i < m; i++) {
        // 시작점, 도착점, 비용
        int s, e, c;    
        cin >> s >> e >> c;

        // 인접리스트
        // 단방향
        cities[s].push_back({ c,e });
    }

    
    int sq, eq;
    cin >> sq >> eq;

    dijkstra(sq);

    cout << dist[eq];

    return 0;
}