#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    bool pd(int n,int x,int k) {
        return ((x*(2*k+x-1))-n*(2*k+n-1)/2)>0;
    }
    void sol() {
        int n,m,q;
        cin>>n>>m>>q;
        vector<int>a(m+10);
        for(int i=1;i<=m;i++)cin>>a[i];
        sort(a.begin()+1,a.begin()+m+1);
        while(q--) {
            int x;
            cin>>x;
            if(x<a[1])cout<<a[1]-1<<"\n";
            else if(x>a[m])cout<<n-a[m]<<"\n";
            else {
                int i=upper_bound(a.begin()+1,a.begin()+m+1,x)-a.begin();
                cout<<(a[i]-a[i-1])/2<<"\n";
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
