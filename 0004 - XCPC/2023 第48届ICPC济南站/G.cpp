// QOJ user: xbbbz
// Contest: 2023 Á¨?8Â±äICPCÊµéÂçóÁ´?// Problem: #7900. Gifts from Knowledge (7900)
// Submission: https://qoj.ac/submission/1454976
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000010
int T,n,m,r,fa[N],b1[N];
const ll mo=1000000007;
string s;
int get(int x)
{
    if(fa[x]==x) return x;
    fa[x]=get(fa[x]);
    return fa[x];
}
void solve()
{
    cin>>n>>m;
    for (int i=1;i<=2*n;i++) fa[i]=i;
    vector<int>cnt[m+5];
    ll ans=1;
    int r=0;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        s=" "+s;
        int bz=0;
        for (int j=1;j<s.size();j++)
            if(s[j]=='1')
                bz=1;
        if(bz==0) {ans=ans*2%mo;continue;}
        r++;
        for (int j=1;j<s.size();j++)
            if(s[j]=='1')
                cnt[j].push_back(r);
    }
    int bz=0;
    for (int i=1;i<=m;i++)
        if(cnt[i].size()+cnt[m-i+1].size()>2)
            bz=1;
    if(bz==1||r>m) {cout<<0<<endl;return;}
    vector<vector<int>> b(2*r+5,vector<int>(2*r+5,0));
    for (int i=1;i<=m;i++)
        for (int j=0;j<cnt[i].size();j++)
            for (int k=0;k<cnt[i].size();k++)
                b[cnt[i][j]][cnt[i][k]+r]=b[cnt[i][j]+r][cnt[i][k]]=1;
    for (int i=1;i<=m;i++)
        for (int j=0;j<cnt[i].size();j++)
            for (int k=0;k<cnt[m-i+1].size();k++)
                b[cnt[i][j]][cnt[m-i+1][k]]=b[cnt[i][j]+r][cnt[m-i+1][k]+r]=1;
    for (int i=1;i<2*r;i++)
        for (int j=i+1;j<=2*r;j++)
            if(b[i][j]&&i+r!=j)
                fa[get(i)]=get(j);
    for (int i=1;i<=r;i++)
        if(get(i)==get(i+r))
            {cout<<0<<endl;return;}
    int num=0;
    for (int i=1;i<=2*r;i++)
        if(!b1[get(i)])
            b1[get(i)]=1,num++;
    for (int i=1;i<=num/2;i++) ans=ans*2%mo;
    for (int i=1;i<=2*r;i++) b1[i]=0;
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) solve();
    return 0;
}
/*
3
3 5
01100
10001
00010
2 1
1
1
2 3
001
001
*/
</code>