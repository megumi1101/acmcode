#include <bits/stdc++.h>

using namespace std;

void sol() {
    string s;
    cin >> s;
    int siz = s.size();
    int l = 0, r = siz - 1;
    
    string ans;
    while (l <= r) {
        if (r - l == 0) {
            ans.push_back(s[l]);
            break;
        }
        if (r - l == 1) {
            if (s[l] < s[r]) {
                ans.push_back(s[l]);
                ans.push_back(s[r]);
            } else {
                ans.push_back(s[r]);
                ans.push_back(s[l]);
            }
            break;
        }
        if (s[l] < s[r]) {
            ans.push_back(s[l]);
            l++;
        } else if (s[r] < s[l]) {
            ans.push_back(s[r]);
            r--;
        } else {
            int A = 0;
            int B = 0;
            while (l + A  <= r && s[l + A] == s[l]) A++;
            while (r - B  >= l && s[r - B] == s[r]) B++;

            char x = s[l + A];
            char y = s[r - B];
            char c = s[l];
            if (l + A - 1 == r) {
                for (int i = 0; i <= A / 2; i++) {
                    ans.push_back(c);
                }
                r = -1;
            } else {
                if (x < c && y < c) {
                    for (int i = 0; i < min(A, B); i++) {
                        ans.push_back(c);
                        l++; r--;
                    }
                } else if (x < c && y > c) {
                    for (int i = 0; i < A; i++) {
                        ans.push_back(c);
                        l++;
                    }
                } else if (x > c && y < c) {
                    for (int i = 0; i < B; i++) {
                        ans.push_back(c);
                        r--;
                    }
                } else {
                    for (int i = 0; i < A; i++) {
                        ans.push_back(c);
                        l++;
                    }
                    for (int i = 0; i < B; i++) {
                        ans.push_back(c);
                        r--;
                    }
                }
            }
        }
    }


    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}