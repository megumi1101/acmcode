#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int long long
    const int N = 5e5+10;
    int n;
    int a[N],b[N],f1[N],f2[N];
    stack<int>ss;
    void main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=n;i>=1;i--) {
            while(!ss.empty()&&a[i]<=a[ss.top()])ss.pop();
            b[i]=n+1;
            if(!ss.empty())b[i]=ss.top();
            ss.push(i);
        }
        for(int i=n;i>=1;i--) {
           f1[i]=f1[b[i]]+(b[i]-i)*a[i]; 
        }
        for(int i=1;i<=n/2;i++) {
            swap(a[i],a[n-i+1]);
        }
        while(!ss.empty())ss.pop();
        for(int i=n;i>=1;i--) {
            while(!ss.empty()&&a[i]<=a[ss.top()])ss.pop();
            b[i]=n+1;
            if(!ss.empty())b[i]=ss.top();
            ss.push(i);
        }
        for(int i=n;i>=1;i--) {
            f2[i]=f2[b[i]]+(b[i]-i)*a[i];
        }
        for(int i=1;i<=n/2;i++) {
            swap(f2[i],f2[n-i+1]);
            swap(a[i],a[n-i+1]);
        }
        int ans=0,topans;
        for(int i=1;i<=n;i++) {
            if(ans<f1[i]+f2[i]-a[i]) {
                ans=f1[i]+f2[i]-a[i];
                topans=i;
            }
        }
        for(int i=topans-1;i>=1;i--) {
            a[i]=min(a[i],a[i+1]);
        }
        for(int i=topans+1;i<=n;i++) {
            a[i]=min(a[i],a[i-1]);
        }
        for(int i=1;i<=n;i++) {
            cout<<a[i]<<" ";
        }
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
 
 
