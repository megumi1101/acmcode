#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
   void sol() {
        string s;
        cin >> s;           
        stack<char> st;
        bool ok = 1;
        
        auto pp = [&] (char l, char r) -> bool {
            return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
        };
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            else if (c == ')' || c == ']' || c == '}') {
                if (st.empty() || !pp(st.top(), c)) {
                    ok = 0; break;
                }
                st.pop();
            }
        }
        if (!st.empty()) ok = 0;

        cout << (ok ? "ok\n" : "error\n");
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}