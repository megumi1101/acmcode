#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    struct Node {
        int x;
        Node* nex;
        Node(int x = 0) : x(x), nex(nullptr) {}
    };

    struct CNode {
        Node* head;
        int n = 0;
        CNode(int n) {
            this->n = n;
            build(n);
        }
        
        void build(int n) {
            head = new Node(1);
            Node *tail = head;
            for (int i = 2; i <= n; ++i) { tail->nex = new Node(i); tail = tail->nex; }
            tail->nex = head;
        }

        vector<int> js(int s, int k) {
            vector<int> out;
            if (n == 0) return out;

            Node *pre = head;
            while (pre->nex != head) pre = pre->nex;
            Node *cur = head;
            for (int i = 1; i < s; i++) {pre = cur; cur = cur->nex;}
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j < k; j++) {
                    pre = cur; cur = cur->nex;
                }
                out.emplace_back(cur->x);
                pre->nex = cur->nex;          
                Node* del = cur;
                cur = pre->nex;                
                delete del;
            }
            return out;
        }  
    };

    void sol() {
        int n, k, s;
        cin >> n >> k >> s;
        CNode lis(n);
        vector<int> ans = lis.js(s, k);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}