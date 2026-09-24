// LUOGU_RID: 93820848
#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=309,mod=1e9+7;
inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}
void pls(int &x,int y) {x+=y; x=(x>=mod?x-mod:x);}
int n,a[N],s[N];
namespace sw{ 
	int s[N],f[2][N][N];
	void solve() {
		int d=0;
		rep(i,1,n) {
			if(a[i]==a[i-1]) s[i]=s[i-1]+1;
			else s[i]=0;
		}
		f[0][0][0]=1;
		rep(i,1,n) {
			if(a[i]!=a[i-1]) {
				rep(j,0,i) rep(k,1,s[i-1])
					pls(f[d^1][j][0],f[d^1][j][k]), f[d^1][j][k]=0;
			}
			rep(j,0,i) {
				int upk=min(s[i],j);
				rep(k,0,upk) {
					if(j&&k) pls(f[d][j][k],f[d^1][j-1][k-1]*(2*s[i]-k+1)%mod);
					pls(f[d][j][k],f[d^1][j][k]*(i-2*s[i]+2*k-j)%mod);
					pls(f[d][j][k],f[d^1][j+1][k]*(j-k+1)%mod);
				}
			}
			memset(f[d^1],0,sizeof(f[d^1]));
			if(i!=n) d^=1;
		}
		printf("%lld\n",f[d][0][0]);
	}
}
 
signed main() {
	n=read();
	rep(i,1,n) {
		a[i]=read();
		for(int j=2;j*j<=a[i];j++)
			while(a[i]%(j*j)==0) a[i]/=j*j;
	}
	sort(a+1,a+n+1);
	sw::solve();
	return 0;
}
