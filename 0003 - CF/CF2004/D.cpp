#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    bool pd(int n,int x,int k) {
        return ((x*(2*k+x-1))-n*(2*k+n-1)/2)>0;
    }
    void sol() {
        int n,q;
        cin>>n>>q;
        vector<int>a(n+10),al(n+10),ar(n+10,n+1);
        for(int i=1;i<=n;i++) {
            string s;
            cin>>s;
            if(s=="BG")a[i]=1;
            else if(s=="BR")a[i]=2;
            else if(s=="BY")a[i]=3;
            else if(s=="GR")a[i]=4;
            else if(s=="GY")a[i]=5;
            else if(s=="RY")a[i]=6;
        }
        int tmp=0;
        for(int i=1;i<=n;i++) {
            if(a[i]!=1&&a[i]!=6)tmp=i;
            else al[i]=tmp;
        }
        tmp=n+1;
        for(int i=n;i>=1;i--) {
            if(a[i]!=1&&a[i]!=6)tmp=i;
            else ar[i]=tmp;
        }
 
        tmp=0;
        for(int i=1;i<=n;i++) {
            if(a[i]!=2&&a[i]!=5)tmp=i;
            else al[i]=tmp;
        }
        tmp=n+1;
        for(int i=n;i>=1;i--) {
            if(a[i]!=2&&a[i]!=5)tmp=i;
            else ar[i]=tmp;
        }
 
        tmp=0;
        for(int i=1;i<=n;i++) {
            if(a[i]!=3&&a[i]!=4)tmp=i;
            else al[i]=tmp;
        }
        tmp=n+1;
        for(int i=n;i>=1;i--) {
            if(a[i]!=3&&a[i]!=4)tmp=i;
            else ar[i]=tmp;
        }
 
        while(q--) {
            int x, y;
            cin>>x>>y;
            if(x==y) {
                cout<<"0\n";continue;
            }
            if(x>y)swap(x,y);
            if(ar[x]<y||a[x]==a[y]){cout<<y-x<<"\n";continue;}
            int ans=99999999;
            if(al[x]!=0)ans=min(ans,y-x+2*(x-al[x]));
            if(ar[x]!=n+1)ans=min(ans,y-x+2*(ar[x]-y));
            if(ans==99999999)ans=-1;
            cout<<ans<<"\n";
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
