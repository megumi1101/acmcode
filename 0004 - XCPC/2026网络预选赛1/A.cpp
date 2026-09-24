#include<bits/stdc++.h>
using namespace std;
#define N 2000010
char ch;
int x,T,n;
struct node{
    int type,x;
}a[N];
void sol()
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>ch>>x;
        if(ch=='+') a[i].type=1;
        if(ch=='T') a[i].type=2;
        if(ch=='F') a[i].type=3;
        a[i].x=x;
    }
    map<pair<int,int>,int>pos;
    vector<array<int,4>>ne(n+5,array<int,4>{n+1,n+1,n+1,n+1});
    for (int i=n;i>0;i--)
    {
        for (int j=1;j<=3;j++)
        {
            if(pos.find({a[i].x,j})==pos.end()) ne[i][j]=n+1;
            else ne[i][j]=pos[{a[i].x,j}];
        }
        pos[{a[i].x,a[i].type}]=i;
    }
    vector<int>mi(n+5,0);
    for (int i=1;i<=n;i++)
    {
        if(a[i].type!=1) continue;
        int posx=ne[i][1],posF=ne[i][3];
        int posT=ne[i][2];
        if(posT==n+1) mi[i]=i;
        else
        {
            if(posF<posT||posx<posT) mi[i]=i;
            else
            {
                while (ne[posT][2]<min(posx,posF)) posT=ne[posT][2];
                mi[i]=posT;
            }
        }
    }
    vector<int>fa(n+5,0);
    for (int i=1;i<=n;i++) fa[i]=i;
    vector<int>popp(n+5,0);
    auto get = [&](auto && self,int x) -> int
    {
        if(fa[x]==x) return x;
        fa[x]=self(self,fa[x]);
        return fa[x];
    };
    for (int i=n;i>0;i--)
    {
        if(a[i].type!=1) continue;
        mi[i]=get(get,mi[i]);
        for (int j=i;j<=mi[i];)
        {
            int x=get(get,j);
            fa[x]=mi[i];
            j=x+1;
        }
        popp[mi[i]]++;
    }
    for (int i=1;i<=n;i++)
    {
        if(a[i].type==1) cout<<"+";
        else cout<<"?";
        for (int j=1;j<=popp[i];j++) cout<<"-";
    }
    cout<<"\n";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--) sol();
    return 0;
}
/*
1
7
+ 1
T 1
T 1
+ 2
T 2
F 2
+ 1
*/