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
    else insertBST(root->right, x);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        insertBST(root, x);
    }
    preorder(root);
    cout << '\n';
    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        insertBST(root, x);
        preorder(root);
        cout << '\n';
    }

    return 0;
}
