#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> zeroMemo;
vector<int> oneMemo;

pair<int,int> fibo(int n) {

    if (n == 0) {
        return { 1,0 };
    }
    else if (n == 1) {
        return { 0,1 };
    }

    // 이미 기억하고 있으면 바로 ㄱ
    if (zeroMemo[n] != -1 && oneMemo[n] != -1) {
        return { zeroMemo[n], oneMemo[n] };
    }

    zeroMemo[n] = fibo(n - 1).first + fibo(n - 2).first;
    oneMemo[n] = fibo(n - 1).second + fibo(n - 2).second;


    return { zeroMemo[n], oneMemo[n]};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    zeroMemo.resize(41, -1);
    oneMemo.resize(41, -1);

    while (t--) {
        int num;
        cin >> num;

        
        pair<int, int> p;


        p = fibo(num);

        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}