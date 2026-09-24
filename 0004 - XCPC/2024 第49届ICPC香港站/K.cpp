// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCé¦™æ¸¯ç«?// Problem: #9925. LR String (9925)
// Submission: https://qoj.ac/submission/1574846
// Language: C++23

#include<bits/stdc++.h>
using namespace std;
#define N 1000010
string s,t;
int T,n,m,q,ne[N][2];
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
        int l=-1,r=-1;
        for (int i=n;i>=0;i--)
        {
            ne[i][0]=l,ne[i][1]=r;
            if(s[i]=='L') l=i;
            else r=i;
        }
        cin>>q;
        while (q--)
        {
            cin>>t;
            m=t.size();
            t=" "+t;
            if((s[1]=='L'&&t[1]=='R')||(s[n]=='R'&&t[m]=='L')) {cout<<"NO\n";continue;}
            int now=0,bz=0;
            for (int i=1;i<=m;i++)
            {
                if(t[i]=='L') now=ne[now][0];
                else now=ne[now][1];
                if(now==-1) {bz=1;break;}
            }
            if(bz==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
/*
2
RRLLRRLL
4
LLLLL
LLR
LRLR
R
RLLLLLL
3
LLLLL
RL
RRL
*/
</code>