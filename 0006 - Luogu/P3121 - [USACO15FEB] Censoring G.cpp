#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    const int N = 1e6 + 10;
    int n;
    int count;
    int ch[N][26], cnt[N], ne[N], a[N];
    vector<int> st;
    
    void add(string s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = s[i] - 'a';
            if (!ch[u][v]) ch[u][v] = ++count;
            u = ch[u][v];
            if (i == s.size() - 1) cnt[u] = s.size();
        }
    }
    
    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (ch[0][i]) q.push(ch[0][i]);
        }
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int i = 0; i < 26; i++) {
                int v = ch[u][i];
                if (v) ne[v] = ch[ne[u]][i], q.push(v);
                else ch[u][i] = ch[ne[u]][i];
            }
        }
    }
    
    void cx(string s) {
        int ans = 0, u = 0;
		st.push_back(0);
        for (int i = 1; i < s.size(); i++) {
			u = a[st.back()];
            u = ch[u][s[i] - 'a'];
			st.push_back(i);
			a[i] = u;
            if (cnt[u]) {
				for (int j = 1; j <= cnt[u]; j++) {
					st.pop_back();
				}
			}
        }
        // return ans;
    }
    
    void sol() {
		string t;
		cin >> t;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            add(s);
        }
        build();
		t = " " + t;
		cx(t);
		for (int i = 1; i < st.size(); i++) {
			cout << t[st[i]];
		}
		cout << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin>>T;
        // init();
        while (T--) {
            sol();
        }
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}