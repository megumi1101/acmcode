#include<bits/stdc++.h>
using namespace std;
void qm(int &a,int b){if(a>b)a=b;}
const int M=23,N=1<<M,INF=1e9;
int n,m,K,x=-1,y,z,w,L,R;
int lg[N],sz[N],f[N],g[M][M],h[M][N>>1];
int main(){
	scanf("%d%d%d",&n,&m,&K);L=1<<m;R=L>>1;lg[0]=-1;
	while(n--) scanf("%d",&y),~x?++g[x][--y]:--y,x=y;
	for(int i=1;i<L;i++) lg[i]=lg[i>>1]+1,sz[i]=sz[i>>1]+(i&1);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)if(i^j) h[i][0]+=g[j][i]*K-g[i][j];
		for(int j=1;j<R;j++) y=j&-j,z=lg[y],z+=z>=i,h[i][j]=h[i][j^y]+g[i][z]*(1+K)+g[z][i]*(1-K);
	}
	for(int i=1;i<L;i++)for(f[i]=INF,x=i;y=x&-x;x^=y)
		z=lg[y],w=i^y,qm(f[i],f[i^y]+h[z][w&y-1|w>>z+1<<z]*sz[i]);
	printf("%d",f[L-1]);
	return 0;
}