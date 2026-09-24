#include<bits/stdc++.h>
using namespace std;

namespace xbbbz {
    #define int long long
    const int N=1e5+10;
    int n,m,a[N], id[N],cnt[N], lst[N], to[N], L[N], R[N];
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        cin>>n>>m;
        int bl = sqrt(n);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            id[i] = (i-1)/bl+1;
            L[i]=(id[i]-1)*bl+1;
            R[i]=min(L[i]+bl-1,n);
        }
        for(int i=n;i>=1;i--) {
            if(i+a[i]>R[i]) {
                cnt[i]=1;
                lst[i]=i;
                to[i]=i+a[i];
            }
            else  {
                cnt[i]=cnt[i+a[i]]+1;
                lst[i]=lst[i+a[i]];
                to[i]=to[i+a[i]];
            }
        }
        for(int i=1;i<=m;i++) {
            int op,x,y;
            cin>>op;
            if(op==0) {
                cin>>x>>y;
                a[x]=y;
                for(int j=R[x];j>=L[x];j--) {
                    if(j+a[j]>R[j]) {
                        cnt[j]=1;
                        lst[j]=j;
                        to[j]=j+a[j];
                    }
                    else  {
                        cnt[j]=cnt[j+a[j]]+1;
                        lst[j]=lst[j+a[j]];
                        to[j]=to[j+a[j]];
                    }
                }
            }
            else {
                cin>>x;
                int ans=0;
                while(1) {
                    ans+=cnt[x];
                    if(to[x]>n) {
                        x=lst[x];
                        break;
                    }
                    else x=to[x];
                }
                cout<<x<<" "<<ans<<"\n";
            }
        }
    }
    #undef int
}

int main() {
    return xbbbz::main(), 0;
}
