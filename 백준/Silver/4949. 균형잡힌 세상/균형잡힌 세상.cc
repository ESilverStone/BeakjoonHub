#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits> // INT_MAX
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string line;

    while (getline(cin, line)) {
        
        // 종료 조건
        if (line == ".") break;

        stack<char> st;
        char top = 1;

        bool result = true;

        // 한 줄의 모든 글자를 검사
        for (char w : line)
        {
            if (w == '(' || w == '[') {
                st.push(w);
            }
            else if (w == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    result = false;
                    break;
                }
            }
            else if (w == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    result = false;
                    break;
                }
            }

        }

        if (!st.empty()) result = false;

        if (result) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }

    }
}