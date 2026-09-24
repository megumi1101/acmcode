#include <bits/stdc++.h>

using namespace std;

#define int long long

bool alla (const string &s) {
    for (auto &c : s) {
        if (c != 'a') {
            return false;
        }
    }
    return true;
}
void sol() {
    int n;
    cin >> n;
    vector<string> ss(n);

    int L = 0;
    for (auto &s : ss) {
        cin >> s;
        L += s.size();
    }
    
    struct SS {
        vector<string> v;
        
        SS () {}
        SS (vector<string> v_) {
            v = v_;
        }

        SS ins(string s) {
            auto cp = v;
            for (int i = 0; i < cp.size(); i++) {
                if (s + cp[i] < cp[i] + s) {
                    cp.insert(cp.begin() + i, s);
                    return{cp};
                }
            }
            
            cp.push_back(s);
            return {cp};
        }

        string get() {
            string t;
            for (auto &s : v) {
                t += s;
            }
            return t;
        }
        
        void getmin(SS b) {
            if (get() > b.get()) {
                v = b.v;
            }
        }
    };

    vector<SS> f(L + 1);
    for (auto &s : ss) {
        vector<SS> nf(L + 1);
        for (int i = 0; i <= L; i++) nf[i] = f[i].ins(s);
        if (s == "abb") {
            cout << f[1].get() << "\n\n";
            cout << f[1].ins(s).get() << "\n\n";
        }
        int cnt = 0;
        for (auto &c : s) {
            if (c != 'a') {
                cnt++;

                c = 'a';
                for (int i = 0; i <= L; i++) {
                    if (i + cnt <= L) {
                        nf[i + cnt].getmin(f[i].ins(s));
                    }
                }
            }
        }
        for (int i = 0; i < L; i++) nf[i + 1].getmin(nf[i]);
        f = move(nf);
        // for (int i = 0; i <= L; i++) {
        //     cout << f[i].get() << "\n";
        // }

        // cout << "\n";
    }

    for (int i = 0; i <= L; i++) {
        cout << f[i].get() << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}

/*
3
5
bca a zz ab c
4
ba b aa aba
3
az za m
*/