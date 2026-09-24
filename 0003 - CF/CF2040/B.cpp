#include<bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int N=1e5+10;
    int a[N];
    void sol() {
        int n;
        cin>>n;
        cout<<a[n]<<"\n";
    }
    void init() {
        int pos=1;a[1]=1;
        for(int i=2;i<=30;i++) {
            pos=pos*2+2;
            pos=min(pos,N-1);
            for(int j=pos;;j--) {
                if(a[j]!=0)break;
                a[j]=i;
            }
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
