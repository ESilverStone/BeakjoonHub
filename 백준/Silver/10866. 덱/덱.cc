#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
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

    deque<int> que;

    while (N--) {
        string cmd ="";
        cin >> cmd;

        if (cmd == "push_front") {
            int num;
            cin >> num;

            que.push_front(num);
        } 
        else if (cmd == "push_back") {
            int num;
            cin >> num;

            que.push_back(num);
        }
        else if (cmd == "pop_front") {
            if (que.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << que.front() << "\n";
                que.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (que.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << que.back() << "\n";
                que.pop_back();
            }
        }
        else if (cmd == "size") {
            cout << que.size() << "\n";
        }
        else if (cmd == "empty") {
            if (que.empty())cout << "1\n";
            else            cout << "0\n";
        }
        else if (cmd == "front") {
            if (que.empty())cout << "-1\n";
            else            cout << que.front() << "\n";
        }
        else {
            if (que.empty())cout << "-1\n";
            else            cout << que.back() << "\n";
        }
        
    }
}