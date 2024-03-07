#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional> // greater 헤더 포함


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>> maxQue;
    priority_queue<int, vector<int>, greater<int>> minQue;

    int n;
    cin >> n;

    while (n--) {
        int input;
        cin >> input;

        if (input == 0) {
            if (minQue.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << minQue.top() << "\n";

                minQue.pop();
            }
        }
        else {
            minQue.push(input);
        }
    }


    return 0;
}