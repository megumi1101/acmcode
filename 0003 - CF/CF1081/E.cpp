#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N = 2e5+10;
    int n;
    int a[N],b[N];
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        cin>>n;
        for(int i=2;i<=n;i+=2)cin>>a[i];
        int pos = 1e5;
        for(int i=n;i>=2;i-=2) {
            while(pos>0) {
                int x=sqrt(pos*pos+a[i]);
                if(x*x==pos*pos+a[i]) {
                    a[i-1]=pos*pos;
                    if(a[i-2]<pos*pos)pos=sqrt(pos*pos-a[i-2]);
                    else pos=0;
                    break;
                }
                pos--;
            }
            if(pos<=0) {
                cout<<"No\n";
                return;
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++) {
            if(i%2==1)a[i]-=sum;
            sum+=a[i];
        }
        cout<<"Yes\n";
        for(int i=1;i<=n;i++) {
            cout<<a[i]<<" ";
        }
    }
 
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
