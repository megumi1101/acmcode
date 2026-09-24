#include<cstdio>
#include<algorithm>
using namespace std;
long long lowbit(long long v){
    return v&(-v);
}
int main(){
    int T;
    long long l,r,t;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&l,&r);
        t=(l^r);
        while(t!=lowbit(t)) t-=lowbit(t);
        printf("%lld\n",((t<<1)-1)&l);
    }
    return 0;
}
