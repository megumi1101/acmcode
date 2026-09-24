#include<bits/stdc++.h>
using namespace std;
const int N=55,M=405,K=820005;
int a[N][M],top[N],n,m,ans[K][2],tot;
bool fg[N];
int inline rid()
{
	int ans=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
inline void yd(int x,int y) 
{
	ans[++tot][0]=x,ans[tot][1]=y;
	a[y][++top[y]]=a[x][top[x]--];
}
void wk(int l,int r)
{
	if(l==r) return;
	int mid=l+r>>1;
	memset(fg,0,sizeof(fg));
	for(int i=l;i<=mid;i++)
		for(int j=mid+1;j<=r;j++)
		{
			if(fg[i] || fg[j]) continue;
			int s=0;for(int k=1;k<=m;k++) s+=(a[i][k]<=mid);
			for(int k=1;k<=m;k++) s+=(a[j][k]<=mid);
			if(s>=m) 
			{
				s=0;for(int k=1;k<=m;k++) s+=(a[i][k]<=mid);
				for(int k=1;k<=s;k++) yd(j,n+1); 
				while(top[i]) a[i][top[i]]<=mid?yd(i,j):yd(i,n+1); 
				for(int k=1;k<=s;k++) yd(j,i);
				for(int k=1;k<=m-s;k++) yd(n+1,i);
				for(int k=1;k<=m-s;k++) yd(j,n+1); 
				for(int k=1;k<=m-s;k++) yd(i,j); 
				while(top[n+1]) 
				{
					if(top[i]==m || a[n+1][top[n+1]]>mid) yd(n+1,j);
					else yd(n+1,i); 
				}
				fg[i]=1;
			}
			else 
			{
				s=0;for(int k=1;k<=m;k++) s+=(a[j][k]>mid);
				for(int k=1;k<=s;k++) yd(i,n+1); 
				while(top[j]) a[j][top[j]]>mid?yd(j,i):yd(j,n+1); 
				for(int k=1;k<=s;k++) yd(i,j);
				for(int k=1;k<=m-s;k++) yd(n+1,j);
				for(int k=1;k<=m-s;k++) yd(i,n+1); 
				for(int k=1;k<=m-s;k++) yd(j,i); 
				while(top[n+1]) 
				{
					if(top[j]==m || a[n+1][top[n+1]]<=mid) yd(n+1,i);
					else yd(n+1,j); 
				}
				fg[j]=1;
			}
		}
	wk(l,mid);wk(mid+1,r);
}
int main()
{
	n=rid();m=rid();
	for(int i=1;i<=n;i++) 
		for(int j=1,x;j<=m;j++)
			a[i][++top[i]]=rid();
	wk(1,n);printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}