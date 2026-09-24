#include <bits/stdc++.h>
using namespace std;
int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
string s,x;
int main(){
    int cnt,maxn=-1;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>s,x=s;
    for(int i=0;i<26;++i){
        cnt=0;
        for(int j=0;j<s.length();++j){
           x[j]=(s[j]-'A'+i)%26+'A';
           cnt+=holes_cnt[x[j]-'A'];
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
