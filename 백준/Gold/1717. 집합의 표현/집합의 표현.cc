#include <iostream>
#include <vector>


using namespace std;

int n, m;
vector<int> uf;

int find_parent(int x);

// 집합 합치는 함수
void union_find(int x, int y) {
    int rx = find_parent(x);
    int ry = find_parent(y);

    if (rx != ry) {
        uf[rx] = ry;
    }
}

// root 찾는 함수
int find_parent(int x) {
    // 자기 자신이 root일 경우
    if (uf[x] == x) return x;

    return uf[x] = find_parent(uf[x]);  // 경로 압축
}

// 같은 집합인지 확인하는 함수
bool check_union(int x, int y) {
    return find_parent(x) == find_parent(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    // 유니온 파인드 검사 배열 초기화
    uf.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        uf[i] = i;
    }

    // 입력
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> c >> a >> b;

        // 합집합 연산
        if (c == 0) {
            union_find(a, b);
        }
        // 같은 집합에 있는 지 확인
        else {
            if (check_union(a, b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}