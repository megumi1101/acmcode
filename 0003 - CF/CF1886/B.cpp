#include <bits/stdc++.h>
using namespace std;
 
namespace xbbbz {
    #define db long double
    const db eps = 1e-12;
    db px,py,ax,ay,bx,by;
    bool pd(db x) {
        bool ao = (ax*ax+ay*ay <= x*x);
        bool bo = (bx*bx+by*by <= x*x);
        bool ab = ((ax-bx)*(ax-bx)+(ay-by)*(ay-by) <= 4.0*x*x);
        bool pa = ((ax-px)*(ax-px)+(ay-py)*(ay-py) <= x*x);
        bool pb = ((px-bx)*(px-bx)+(py-by)*(py-by) <= x*x);
        return (pa&&ao)||(pb&&bo)||(pa&&ab&&bo)||(pb&&ab&&ao);
    }
    db sol() {
        cin>>px>>py>>ax>>ay>>bx>>by;
        db l=0.0,r=10000.0,ans=0.0;
        while(l+eps<=r) {
            db mid=(l+r)/2;
            if(pd(mid))ans=mid,r=mid-eps;
            else l=mid+eps;
        }
        return ans; 
    }
    void main() {
        ios::sync_with_stdio(false),cin.tie(nullptr);
        int T;
        cin>>T;
        cout<<fixed<<setprecision(10);
        while(T--) cout<<sol()<<"\n";
    }
    #undef int
}
int main() {
    return xbbbz::main(), 0;
}
