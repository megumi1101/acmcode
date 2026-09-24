## kmp
pi[i]为以i为结尾的最长公共前后缀(从0开始)
求pi数组
```cpp
vector<int> get_pi(string s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
void kmpSearch(string txt, string pat) {
    vector<int> next = buildNext(pat);
    for (int i = 0, j = 0; i < txt.size(); ++i) {
        while (j > 0 && txt[i] != pat[j]) j = next[j - 1];
        if (txt[i] == pat[j]) ++j;
        if (j == pat.size()) {
            cout << "Pattern found at index " << i - j + 1 << endl;
            j = next[j - 1];
        }
    }
}
```