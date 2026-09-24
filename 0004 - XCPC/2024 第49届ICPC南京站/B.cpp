// QOJ user: xbbbz
// Contest: 2024 Á¨?9Â±äICPCÂçó‰∫¨Á´?// Problem: #9565. Birthday Gift (9565)
// Submission: https://qoj.ac/submission/1539051
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define  N 500010
int T,n,cnt[N];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>s;
        n=s.size();
        s=" "+s;
        for (int i=0;i<3;i++) cnt[i]=0;
        for (int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                if(s[i]=='0') s[i]='1';
                else if(s[i]=='1') s[i]='0';
            }
            cnt[s[i]-'0']++;
        }
        // cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
        if(cnt[0]>cnt[1]) swap(cnt[0],cnt[1]);
        if(cnt[2]<=cnt[1]-cnt[0]) cout<<cnt[1]-cnt[0]-cnt[2]<<endl;
        else cout<<(cnt[2]+cnt[1]-cnt[0])%2<<endl;
    }
    return 0;
}
</code>