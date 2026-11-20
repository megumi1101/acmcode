#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int n,m,k,type[N],a[N],sum[N];
struct node{
    int l,r,id;
}itv[N];
bool cmp(node a,node b)
{
    return a.r<b.r;
}
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) cin>>type[i]>>a[i];
    for (int i=1;i<=k;i++) cin>>itv[i].l>>itv[i].r,itv[i].id=i;
    sort(itv+1,itv+k+1,cmp);

    vector<int>q;
    vector<int>p;
    for (int i=1,j=1;i<=m;i++)
    {
        if(type[i]==0)
        {
            while (q.size()&&a[i]>=a[*q.rbegin()]) q.pop_back();
            q.push_back(i);
        }
        else
        {
            while (p.size()&&a[i]<=a[*p.rbegin()]) p.pop_back();
            p.push_back(i);
        }

        while (itv[j].r==i)
        {
            auto [l,r,id]=itv[j];
            int ans=0;
            while (l<=r)
            {
                int mid=l+r>>1,len=0;
                auto point=lower_bound(q.begin(),q.end(),mid);
                int x=0;
                if(point!=q.end()) x=a[*point],len+=q.end()-point;

                point=lower_bound(p.begin(),p.end(),mid);
                int y=n+1;
                if(point!=p.end()) y=a[*point],len+=p.end()-point;

                if(x<y-1) ans=len,r=mid-1;
                else l=mid+1;
            }
            if(l>itv[j].l) ans++;
            sum[id]=ans;
            
            // cout<<itv[j].l<<" "<<itv[j].r<<" "<<ans<<"\n";

            j++;

            
        }
    }
    for (int i=1;i<=k;i++) cout<<sum[i]<<"\n";
    return 0;
}
/*
5 4 3
0 3
1 2
0 5
1 4
1 4
2 3
1 2

10 3 3
0 10
0 3
0 6
1 2
1 3
2 3
*/