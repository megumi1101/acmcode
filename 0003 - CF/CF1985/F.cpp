#include<bits/stdc++.h>
using namespace std;
namespace xbbbz {
    #define int __int128
    int rid() {
        int x=0,f=1;
        char ch=getchar();
        while(!isdigit(ch)) {
            if(ch=='-')f=-1;
            ch=getchar();
        }
        while(isdigit(ch)) {
            x=x*10+ch-'0';
            ch=getchar();
        }
        return x*f;
    }
    void out(int x) {
        if(x>9)out(x/10);
        putchar(x%10+'0');
    }
    const int mod=1e9+7;
    void sol() {
        int h,n;
        h=rid(),n=rid();
        int c[n+1],a[n+1];
        for(int i=1;i<=n;i++) a[i]=rid();
        for(int i=1;i<=n;i++) c[i]=rid();
        int l=1,r=1e11;
        int ans=0;
        while(l<=r) {
            int mid=(l+r)/2;
            int res=0;
            for(int i=1;i<=n;i++) {
                res+=((mid-1)/c[i]+1)*a[i];
            }
            if(res>=h)ans=mid,r=mid-1;
            else l=mid+1;
        }
        out(ans);
        puts("");
    }
    void main() {
        // ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        T=rid();
        while(T--)sol();
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
