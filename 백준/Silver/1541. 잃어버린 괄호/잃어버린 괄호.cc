#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);

    int result = 0;
    int num = 0;
    bool numSwitch = false;
    bool calSwitch = false;

    for (char c : line) {
        
        if (c == '+') {
            result += (calSwitch) ? (num * -1) : (num);
            
            numSwitch = false;
            
            num = 0;
        }
        else if (c == '-') {
            result += (calSwitch) ? (num * -1) : (num);

            calSwitch = true;   // 앞으로 모두 숫자는 -
            numSwitch = false;

            num = 0;
        }
        else {
            if (!numSwitch) numSwitch = true;

            num *= 10;      // 이전 숫자를 10배 후
            num += c - 48;  // 이번 숫자를 더한다
        }
    }

    result += (calSwitch) ? (num * -1) : (num);
    

    cout << result;

    return 0;
}