#include <bits/stdc++.h>

using namespace std;

struct Ch {
    vector<int> ord;
    vector<int> fp;
    Ch(vector<int>& a) {
        int n = a.size();
        ord = a;
        int pos = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 1) {
                pos = i;
                break;
            }
        }

        fp.resize(n);
        for (int i = 0; i < a.size(); i++) {
            fp[i] = a[(i + pos) % n];
        }
    }

    friend bool operator < (const Ch &A, const Ch &B) {
        return A.fp < B.fp;
    }

    void print() {
        cout << "ord : \n";
        for (int i = 0; i < ord.size(); i++) cout << ord[i] << " ";
        cout << "\n";
        cout << "fp : \n";
        for (int i = 0; i < fp.size(); i++) cout << fp[i] << " ";
        cout << "\n";

    }
};


int main() {
    int n;
    cin >> n;
    vector<int> vis(n + 1);

    vector<int> a;
    auto dfs = [&](this auto&&dfs, int pos) -> Ch {
        if (pos == n + 1) {
            return Ch(a);
        }

        vector<Ch> v;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            a.push_back(i);
            vis[i] = 1;
            v.push_back(dfs(pos + 1));
            a.pop_back();
            vis[i] = 0;
        }
        
        Ch c = v[0];
        if (pos & 1) {
            for (int i = 1; i < v.size(); i++) {
                if (v[i] < c) {
                    c = v[i];
                }
            }
        } else {
            for (int i = 1; i < v.size(); i++) {
                if (c < v[i]) {
                    c = v[i];
                }
            }
        }
        return c;
    };

    Ch ans = dfs(1);
    ans.print();
}