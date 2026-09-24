#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	
	void sol() {
		string s;
		cin >> s;
		s = " " + s;
		int cnt[14];
		memset(cnt, 0 ,sizeof (cnt));
		for (int i = 1; i <= 10; i++) {
			cnt[s[i] - '0']++;
		}
		vector<int>xx;
		for (int i = 1; i <= 10; i++) {
			for (int j = 10 - i; j <= 9; j++) {
				if (cnt[j]) {
					cnt[j]--;
					xx.push_back(j);
					break;
				}
			}
		}
		for (int i : xx) cout << i;
		cout << "\n";
	}
	void main() {
		ios::sync_with_stdio(false), cin.tie(nullptr);
		int T = 1;
		cin >> T;
		while (T--) sol();
	}
 
	#undef int
}
 
int main() {
	return Xbbbz::main(), 0;
}
