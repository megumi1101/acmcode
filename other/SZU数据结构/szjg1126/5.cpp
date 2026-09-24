#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void insertBST(Node* &root, int x) {
    if (!root) {
        root = new Node(x);
        return;
    }
    if (x < root->val) insertBST(root->left, x);
    else               insertBST(root->right, x); 
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

int searchBST(Node* root, int x) {
    int cnt = 0;
    Node* cur = root;
    while (cur) {
        ++cnt;
        if (x == cur->val) return cnt;
        else if (x < cur->val) cur = cur->left;
        else                   cur = cur->right;
    }
    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        Node* root = nullptr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            insertBST(root, x);
        }
        inorder(root);
        cout << '\n';

        int m;
        if (!(cin >> m)) break;

        while (m--) {
            int x;
            cin >> x;
            int res = searchBST(root, x);
            if (res == -1) cout << -1 << '\n';
            else           cout << res << '\n';
        }
    }

    return 0;
}
