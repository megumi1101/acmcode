// QOJ user: xbbbz
// Contest: 2024 Á¨?9Â±äICPCÂçó‰∫¨Á´?// Problem: #9574. Strips (9574)
// Submission: https://qoj.ac/submission/1538111
// Language: C++14

#include<bits/stdc++.h>
using namespace std;
#define N 200010
int n,m,k,w,T,tot;
int cnt,ans[N],pos[N];
struct node{int x,y;}a[N];
bool cmp(node a,node b){return a.x<b.x;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--)
    {
        tot=cnt=0;
        cin>>n>>m>>k>>w;
        for (int i=1;i<=n;i++) cin>>a[++tot].x,a[tot].y=0;
        for (int i=1;i<=m;i++) cin>>a[++tot].x,a[tot].y=1;
        a[++tot]={0,1},a[++tot]={w+1,1};
        sort(a+1,a+tot+1,cmp);
        // for (int i=1;i<=tot;i++) cout<<"?? "<<a[i].x<<" "<<a[i].y<<"\n";
        int la=1,bz=0;
        pos[0]=-k;
        for (int i=2,j=0;i<=tot;i++)
        {
            if(a[i].y==0)
            {
                if(a[i].x>=pos[j]+k) pos[++j]=a[i].x;
            }
            else
            {
                // cout<<a[i].x<<" "<<j<<endl;
                pos[j+1]=a[i].x;
                for (int p=j;p>0;p--)
                {
                    if(pos[p]+k>pos[p+1]) pos[p]=pos[p+1]-k;
                    else break;
                }
                if(pos[1]<la) {bz=1;break;}
                for (int p=1;p<=j;p++) ans[++cnt]=pos[p];
                la=a[i].x+1;
                j=0;
            }
        }
        if(bz==1) cout<<-1<<"\n";
        else
        {
            cout<<cnt<<"\n";
            for (int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
/*
4
5 2 3 16
7 11 2 9 14
13 5
3 2 4 11
6 10 2
1 11
2 1 2 6
1 5
3
2 1 2 6
1 5
2

*/
</code>