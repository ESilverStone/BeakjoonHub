#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int limit = lcm(m, n); // 최대 공배수까지 범위를 설정
        int ans = -1;

        for (int i = x; i <= limit; i += m) {
            if ((i - 1) % n + 1 == y) {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}