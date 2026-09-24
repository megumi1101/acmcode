#include<bits/stdc++.h>
using namespace std;
#define pa pair<int,int>
#define N 8010
string s;
int n,a[N][N],num[N],T;
void sol()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        num[i]=0;
        cin>>s;
        for (int j=1;j<=n;j++)
        {
            a[i][j]=s[j-1]-'0';
            if(a[i][j]==1) num[i]++;
        }
    }
    for (int i=1;i<=n;i++)
        if(a[i][i]==0)
        {
            cout<<"no\n";
            return;
        }
    vector<pa>ans;
    for (int i=1;i<=n;i++)
    {
        vector<int>vis(n+5,0);
        vis[i]=1;
        while (1)
        {
            int ma=0;
            for (int j=1;j<=n;j++)
                if(a[i][j]==1&&!vis[j])
                    ma=max(ma,num[j]);
            if(ma==0) break;
            for (int j=1;j<=n;j++)
                if(a[i][j]==1&&num[j]==ma&&!vis[j])
                {
                    ans.push_back({i,j});
                    
                    // 【修改处 1：添加防御机制】一旦边数大于等于 n，说明绝对不是合法的树，直接判否，防止退化成 O(N^3)
                    if (ans.size() >= n) {
                        cout << "no\n";
                        return;
                    }
 
                    for (int k=1;k<=n;k++)
                        if(a[j][k]==1)
                        {
                            if(a[i][k]==0||vis[k])
                            {
                                cout<<"no\n";
                                return;
                            }
                            vis[k]=1;
                        }
                }
        }
    }
    if(ans.size()!=n-1)
    {
        cout<<"no\n";
        return;
    }
    vector<int>fa(n+5,0);
    for (int i=1;i<=n;i++) fa[i]=i;
    auto get=[&](auto && self,int x) -> int
    {
        if(fa[x]==x) return x;
        fa[x]=self(self,fa[x]);
        return fa[x];
    };
    for (auto [x,y]:ans) fa[get(get,x)]=get(get,y);
    for (int i=2;i<=n;i++)
        if(get(get,i)!=get(get,1))
        {
            cout<<"no\n";
            return;
        }
    cout<<"yes\n";
    for (auto [x,y]:ans) cout<<x<<" "<<y<<"\n";
    return;
}
int main()
{
    // 【修改处 2：解除 C++ 输入输出流的同步，极大幅度提升读取百万级字符的速度】
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin>>T;
    while (T--) sol();
    return 0;
}
