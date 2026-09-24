#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tokens;
    string x;

    while (cin >> x) tokens.push_back(x);
    if (tokens.empty()) {
        cout << "ERROR";
        return 0;
    }

    stack<double> st;
    for (int i = tokens.size() - 1; i >= 0; i--) {
        string t = tokens[i];
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            if (st.size() < 2) {
                cout << "ERROR";
                return 0;
            }

            double a = st.top(); st.pop();
            double b = st.top(); st.pop();

            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else {
                if (b == 0) {
                    cout << "ERROR";
                    return 0;
                }
                st.push(a / b);
            }

        } else {
            st.push(stoi(t));
        }
    }

    if (st.size() != 1) {
        cout << "ERROR";
        return 0;
    }

    double ans = st.top();
    cout << fixed << setprecision(1) << ans;

    return 0;
}
