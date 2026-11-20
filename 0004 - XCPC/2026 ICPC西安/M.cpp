#include <algorithm>
#include <iostream>
using namespace std;
string a[4];
int res[4], combo[4];
bool mark[4];
void solution() {
    int n;
    cin >> n;
    for (int i = 0; i < 4; ++i) cin >> a[i];
    for (int i = 0; i < 4; ++i) {
        res[i] = 2000, mark[i] = true, combo[i] = 0;
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (a[i][j] == 'H') {
                ++combo[i];
                if (combo[i] == 100) {
                    for (int j = 0; j < 4; ++j) {
                        if (i == j) continue;
                        res[j] += 30;
                    }
                    combo[i] = 0;
                }
            } else {
                combo[i] = 0;
                if (a[i][j] == 'J') res[i] -= 50;
                if(a[i][j]=='A') res[i]-=100;
                if(a[i][j]=='M') res[i]-=200;
            }
        }
        for(int i=0;i<4;++i){
            if(res[i]<=0) mark[i]=false;
            res[i]=min(res[i],2000);
        }
    }
    for (int i = 0; i < 4; ++i) cout << mark[i]*res[i] << ' ';
    cout << '\n';
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) solution();
    return 0;
}
/*
3
5
CCCCC
JJJJJ
AAAAA
MMMMM
10
HCJAMHCJAM
CHCHCHCHCH
JAMJAMJAMJ
MAJHAMMACH
103
MMMMMMMMMMCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
CJCJCJCJHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHJJJCJCJCJCJCJCJCJCJCJCJCJCJCJCJCJCJCJC
HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
*/