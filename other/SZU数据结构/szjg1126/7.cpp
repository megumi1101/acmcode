#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int cnt;                     
    TrieNode* next[26];
    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 26; ++i) next[i] = nullptr;
    }
};

void insert(TrieNode* root, const string& s) {
    TrieNode* p = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!p->next[idx]) p->next[idx] = new TrieNode();
        p = p->next[idx];
        p->cnt++;
    }
}

int countPrefix(TrieNode* root, const string& pre) {
    TrieNode* p = root;
    for (char c : pre) {
        int idx = c - 'a';
        if (!p->next[idx]) return 0;
        p = p->next[idx];
    }
    return p->cnt;
}

string levelOrder(TrieNode* root) {
    string res;
    queue<pair<TrieNode*, char>> q;
    for (int i = 0; i < 26; ++i)
        if (root->next[i]) q.push({root->next[i], char('a' + i)});
    while (!q.empty()) {
        auto [node, ch] = q.front(); q.pop();
        res += ch;
        for (int i = 0; i < 26; ++i)
            if (node->next[i])
                q.push({node->next[i], char('a' + i)});
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);

        TrieNode* root = new TrieNode();
        for (auto& w : words) insert(root, w);

        int t;
        if (!(cin >> t)) break;
        cout << levelOrder(root) << "\n";
        while (t--) {
            string pre;
            cin >> pre;
            cout << countPrefix(root, pre) << "\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    return 0;
}
