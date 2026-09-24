#include <bits/stdc++.h>
using namespace std;

struct Node {
    char v;
    Node *l, *r;
    Node(char c) : v(c), l(nullptr), r(nullptr) {}
};

Node* buildArray(const string& s, int i) {
    if (i < 1 || i > (int)s.size()) return nullptr;
    if (s[i - 1] == '#') return nullptr;
    Node* u = new Node(s[i - 1]);
    u->l = buildArray(s, i << 1);
    u->r = buildArray(s, i << 1 | 1);
    return u;
}

Node* buildPre(const string& p, int& idx) {
    if (idx >= (int)p.size()) return nullptr;
    char c = p[idx++];
    if (c == '#') return nullptr;
    Node* u = new Node(c);
    u->l = buildPre(p, idx);
    u->r = buildPre(p, idx);
    return u;
}

bool same(Node* a, Node* b) {
    if (a == nullptr || b == nullptr) return a == b;
    return a->v == b->v && same(a->l, b->l) && same(a->r, b->r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        string arr, pre;
        cin >> arr >> pre;

        Node* A = buildArray(arr, 1);
        int idx = 0;
        Node* B = buildPre(pre, idx);

        cout << (same(A, B) ? "YES" : "NO") << '\n';
    }
    return 0;
}
