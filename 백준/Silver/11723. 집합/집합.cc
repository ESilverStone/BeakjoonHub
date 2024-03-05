#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

class BitSet {
private:
    unsigned int bits;
public:
    BitSet() : bits(0) {}

    // S집합에 x를 추가한다.
    void add(int x) {
        bits = bits | (1 << x);
    }

    // S집합에서 x를 제거한다.
    void remove(int x) {
        bits = (bits & ~(1 << x));
    }

    // S집합에 x가 있는지 확인
    void check(int x) {
        if (bits & (1 << x)) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    // S집합에 x가 있으면 제거 없으면 추가
    void toggle(int x) {
        bits = bits ^ (1 << x);
    }

    // S집합을 {1,2...20}으로 변경
    void all() {
        bits = (1 << 21) - 1;
    }

    // S집합을 공집합으로 변경
    void empty() {
        bits = 0;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    BitSet bit;

    int n;
    cin >> n;

    while (n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x;
            cin >> x;

            bit.add(x);
        } else if (cmd == "remove") {
            int x;
            cin >> x;

            bit.remove(x);
        } else if (cmd == "check") {
            int x;
            cin >> x;

            bit.check(x);
        } else if (cmd == "toggle") {
            int x;
            cin >> x;

            bit.toggle(x);
        } else if (cmd == "all") {
            
            bit.all();
        } else if (cmd == "empty") {
            
            bit.empty();
        }
    }
    return 0;
}