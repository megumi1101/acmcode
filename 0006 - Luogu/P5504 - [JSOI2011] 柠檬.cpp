#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
const int maxn=1e5+10;
int xx,n,w[maxn];
db num[maxn],f[maxn];
vector<int> ed[maxn],st[maxn];
db X(int i){return (db)num[i];}
db Y(int j){return f[j-1]+(db)xx*num[j]*num[j];}
db xl(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		w[i]=read();
		num[i]=ed[w[i]].size();
		ed[w[i]].push_back(i);   
	}
	for(int i=1;i<=n;i++)
	{
		xx=w[i];
		while(st[xx].size()>=2&&xl(st[xx][st[xx].size()-2],st[xx][st[xx].size()-1])<xl(st[xx][st[xx].size()-1],i))st[xx].pop_back();
		st[xx].push_back(i);
		while(st[xx].size()>=2&&xl(st[xx][st[xx].size()-2],st[xx][st[xx].size()-1])<2*(db)xx*(db)(num[i]+1))st[xx].pop_back();
		int kk=st[xx][st[xx].size()-1];
		f[i]=f[kk-1]+xx*(num[i]-num[kk]+1)*(num[i]-num[kk]+1);
	}
	printf("%lld\n",(int)f[n]);
	return 0;
}