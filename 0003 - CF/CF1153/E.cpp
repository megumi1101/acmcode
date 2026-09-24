#include <bits/stdc++.h>
using namespace std;
namespace xbbbz {
    int n;
    int c1,c2,r1,r2;
    bool pd(int l,int r,int op,int x) {
        if(op) {
            printf("? %d %d %d %d",x,l,x,r);cout<<endl;
            int tmp;cin>>tmp;
            return tmp&1;
        }
        else {
            printf("? %d %d %d %d",l,x,r,x);cout<<endl;
            int tmp;cin>>tmp;
            return tmp&1;
        }
    }
    int getans(int l,int r,int op,int x) {
        int ans;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(pd(l,mid,op,x)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    void main() {
        // ios::sync_with_stdio(false),cin.tie(nullptr);
        cin>>n;
        for(int i=1;i<=n;i++) {
            printf("? %d %d %d %d",1,1,i,n);cout<<endl;
            int x;cin>>x;
            if(!r1&&x&1)r1=i;
            if(r1&&!r2&&!(x&1))r2=i;
        }
        if(r1&&!r2) {
            int ans1 = getans(1,n,1,r1);
            printf("! %d %d %d %d",r1,ans1,r1,ans1);cout<<endl;
            return;
        }
        if(r1&&r2) {
            int ans1 = getans(1,n,1,r1);
            int ans2 = getans(1,n,1,r2);
            printf("! %d %d %d %d",r1,ans1,r2,ans2);cout<<endl;
            return;
        }
        for(int i=1;i<n;i++) {
            printf("? %d %d %d %d",1,1,n,i);cout<<endl;
            int x;cin>>x;
            if(!c1&&x&1)c1=i;
            if(c1&&!c2&&!(x&1))c2=i;
        }
        if(!c2)c2=n;
        int ans1 = getans(1,n,0,c1);
        int ans2 = getans(1,n,0,c2);
        printf("! %d %d %d %d",ans1,c1,ans2,c2);cout<<endl;
        return;
    }
}
int main() {
    return xbbbz::main(), 0;
}
