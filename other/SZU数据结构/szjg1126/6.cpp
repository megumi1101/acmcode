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

Node* deleteBST(Node* root, int x) {
    if (!root) return nullptr;
    if (x < root->val) {
        root->left = deleteBST(root->left, x);
    } else if (x > root->val) {
        root->right = deleteBST(root->right, x);
    } else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        }
        if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        }
        Node* p = root->right;
        while (p->left) p = p->left;
        root->val = p->val;                       
        root->right = deleteBST(root->right, p->val); 
    }
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;
        Node* root = nullptr;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            insertBST(root, x);
        }

        inorder(root);
        cout << '\n';
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            root = deleteBST(root, x); 
            inorder(root);
            cout << '\n';
        }
    }

    return 0;
}
