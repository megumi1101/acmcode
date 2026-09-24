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
        
        int siz() {
            int cnt = 0;
            Node *p = head->nex;
            while (p) {
                ++cnt;
                p = p->nex;
            }
            return cnt;
        }

        void print() {
            Node *p = head->nex;
            if (!p) {cout << '\n'; return;}
            while (p) {
                cout << p->x;
                if (p->nex) cout << " ";
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
        
        void era() {
            set<int> s;
            Node *lst = head;
            Node *p = head->nex;
            while (p) {
                if (s.count(p->x)) {
                    lst->nex = p->nex;
                    Node *del = p;
                    p = p->nex;
                    delete del;
                }
                else {
                    s.insert(p->x);
                    lst = p;
                    p = p->nex;
                }
            }
        }
        
    };

    void sol() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        ListNode lis;
        lis.build(a);
        lis.era();
        cout << lis.siz() << ": ";
        lis.print();
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