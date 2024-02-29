#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits> // INT_MAX
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    stack<int> st;

    while (N--) {
        string cmd ="";
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;

            st.push(num);
        }
        else if (cmd == "pop") {
            if (st.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (cmd == "size") {
            cout << st.size() << "\n";
        }
        else if (cmd == "empty") {
            if (st.empty()) cout << "1\n";
            else            cout << "0\n";
        }
        else {
            if (st.empty()) cout << "-1\n";
            else            cout << st.top() << "\n";
        }
        
    }
}