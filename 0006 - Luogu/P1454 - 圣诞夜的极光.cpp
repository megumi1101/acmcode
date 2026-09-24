#include<cstdio>
int m,n,p;
char a[1010][1010];
int xx[13]={0,0,0,1,-1,0,0,2,-2,1,1,-1,-1};
int yy[13]={0,1,-1,0,0,2,-2,0,0,1,-1,1,-1};
void dfs(int x,int y)
{
	if(x<1||x>n||y<1||y>m||a[x][y]!='#')
	{
		return;
	}
	else if(a[x][y]=='#')
	{
		a[x][y]='-';	
	}for(int i=1;i<=12;i++)
	{		
		dfs(x+xx[i],y+yy[i]);
	}	
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		
			scanf("%s",a[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
  			if(a[i][j]=='#')
  			{
			  p++;
			  dfs(i,j);	
  			}
		}
	}printf("%d",p);
	return 0;
} 