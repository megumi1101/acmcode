#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N=2e5+10;
    int a[N],p2[100];
    void out(int x,int n,int k) {
        if(n<=0)return;
        int i=1;
        while(n-i-1>=0&&k>p2[min((int)60,n-i-1)]) {
            k-=p2[n-i-1];
            i++;
        }
        cout<<x+i-1<<" ";
        out(x+i,n-i,k);
        for(int j=i-1;j>=1;j--)cout<<j+x-1<<" ";
    }
    void sol() {
        int n,k;
        cin>>n>>k;
        if(n<=60&&p2[n-1]<k) {
            cout<<"-1\n";
            return;
        }
        out(1,n,k);
        cout<<"\n";
    }
    void init() {
        p2[0]=1;
        for(int i=1;i<=60;i++) {
            p2[i]=p2[i-1]*2;
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin>>T;
        init();
        while(T--) {
            sol();
        }
    } 
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
