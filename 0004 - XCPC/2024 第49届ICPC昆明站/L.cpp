#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
int T,n,m,a[N],b[N];
bool cmp(int x,int y){return x<y;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        int bz=0,cnt=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>1) a[i]--,cnt++;
            else if(!bz) a[i]--,cnt++,bz=1; 
        }
        for (int i=1;i<=m;i++) cin>>b[i];
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+m+1,cmp);
        // for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
        // for (int i=1;i<=m;i++) cout<<b[i]<<" ";cout<<endl;
        // cout<<cnt<<endl;
        int x=0,i=1,j=1,sum=0;
        while (1)
        {
            while (i<=n&&a[i]<=x) x++,i++;
            while (j<=m&&b[j]<=x) x++,j++;
            if(i<=n&&a[i]<=x) continue;
            if(j>m) break;
            sum+=b[j]-x,j++,x++;
        }
        if(sum>cnt) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
/*
1
3 2
1 1 4
2 7
*/
