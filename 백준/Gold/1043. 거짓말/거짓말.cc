#include <iostream>
#include <vector>


using namespace std;

// n : 사람 수, m : 파티 수
int n, m;
vector<int> uf;

int find_parent(int x) {
    if (uf[x] == x) return x;

    return uf[x] = find_parent(uf[x]);
}

void union_find(int x, int y) {
    int rx = find_parent(x);
    int ry = find_parent(y);

    if(rx != ry) uf[rx] = ry;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    int t; 
    cin >> t;
    vector<int> truth(t);   // 진실을 아는 그룹

    for (int i = 0; i < t; i++) {
        cin >> truth[i];
    }

    vector<vector<int>> parties(m);     // 파뤼타임
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        parties[i].resize(p);

        // 방명록 등록
        for (int j = 0; j < p; j++) {
            cin >> parties[i][j];
        }
    }

    // 초기화
    uf.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        uf[i] = i;
    }

    // 진실을 아는 그룹 단일화
    for (int i : truth) {
        union_find(truth[0], i);
    }

    // 나머지 그룹 단일화
    for (int i = 0; i < m; i++) {
        for (int j : parties[i]) {
            union_find(parties[i][0], j);
        }
    }


    // 최종 검사
    // 검사 대상. 만약 없으면 -1로 설정하여 비교 안되도록
    int true_man = truth.empty() ? -1 : find_parent(truth[0]);

    int count = 0;
    for (const auto& party : parties) {
        bool can_lie = true;

        for (int person : party) {
            if (find_parent(person) == true_man) {
                can_lie = false;
                break;
            }
        }
        if (can_lie) count++;
    }
    
    cout << count << " ";

    return 0;
}