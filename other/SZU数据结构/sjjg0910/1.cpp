#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    struct Node {
        int x;
        Node* nex;
        Node(int x = 0) : x(x), nex(nullptr) {}
    };

    struct ListNode {
        Node* head;

        ListNode() {
            head = new Node();
        }
        
        void print() {
            Node *p = head->nex;
            if (!p) {cout << '\n'; return;}
            while (p) {
                cout << p->x << " ";
                p = p->nex; 
            }
            cout << "\n";
        }

        void build (vector<int> &a) {
            Node *p = head;
            for (auto x : a) {
                p->nex = new Node(x);
                p = p->nex;
            } 
        }

        bool ins (int pos, int x) {
            if (pos <= 0) return 0;
            Node *p = head;
            for (int i = 1; i < pos && p; i++) {
                p = p->nex;
            }
            if (!p) return 0;
            Node *q = new Node(x);
            q->nex = p->nex;
            p->nex = q;
            return 1;
        }

        bool erase (int pos) {
            if (pos <= 0) return 0;
            Node *p = head;
            for (int i = 1; i < pos && p; i++) {
                p = p->nex;
            }
            if (!p || !p -> nex) return 0;
            Node *q = p->nex;
            p->nex = q->nex;
            delete q;
            return 1; 
        }

        bool find(int pos, int &res) {
            if (pos <= 0) return 0;
            Node *p = head;
            for (int i = 1; i <= pos && p; i++) {
                p = p->nex;
            }
            if (!p) return 0;
            res = p->x;
            return 1;
        }
    };

    

    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ListNode lis;
        lis.build(a);
        lis.print();
        
        int pos, x;
        cin >> pos >> x;
        if (!lis.ins(pos, x)) cout << "error\n";
        else lis.print();
        cin >> pos >> x;
        if (!lis.ins(pos, x)) cout << "error\n";
        else lis.print();

        cin >> pos;
        if (!lis.erase(pos)) cout << "error\n";
        else lis.print();
        cin >> pos;
        if (!lis.erase(pos)) cout << "error\n";
        else lis.print();

        
        int res;
        cin >> pos;
        if (!lis.find(pos, res)) cout << "error\n";
        else cout << res << "\n";
        cin >> pos;
        if (!lis.find(pos, res)) cout << "error\n";
        else cout << res << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}