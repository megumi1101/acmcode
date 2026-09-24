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

    void LL_merge(ListNode *lisa, ListNode *lisb) {
        Node *pa = lisa->head->nex;
        Node *pb = lisb->head->nex;
        Node *tail = lisa->head;

        while (pa && pb) {
            if (pa->x <= pb->x) {
                tail->nex = pa;
                pa = pa->nex;
            }
            else {
                tail->nex = pb;
                pb = pb->nex;
            }
            tail = tail->nex;
        }
        if (pa) tail->nex = pa;
        else tail->nex = pb;
    }

    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        ListNode lisa, lisb;
        lisa.build(a); lisb.build(b);

        LL_merge(&lisa, &lisb);
        lisa.print();
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