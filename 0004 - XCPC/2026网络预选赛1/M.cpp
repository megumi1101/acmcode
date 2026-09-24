#include<bits/stdc++.h>
using namespace std;
#define N 1000010
long long x,ans=0,pre=0,sum;
int n,m,a[N];
// int tot,tree[N][55];
// string s;
// void insert()
// {
//     int len=s.size();
//     int now=0;
//     for (int i=0;i<len;i++)
//     {
//         if(s[i]>='a'&&s[i]<='z') a[i]=s[i]-'a';
//         else a[i]=s[i]-'A'+26;
//     }
//     for (int i=0;i<len;i++)
//     {
//         if(!tree[now][a[i]]) tree[now][a[i]]=++tot;
//         now=tree[now][a[i]];
//     }

// }
map<string,int>b;
string s;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        b[s]=1;
    }
    for (int i=1;i<=m;i++)
    {
        cin>>s;
        if(b[s]==1) cout<<"OK\n",b[s]=2;
        else if(b[s]==2) cout<<"REPEAT\n";
        else cout<<"WRONG\n";
    }
    return 0;
}
