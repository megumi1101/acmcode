#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int T,n,a[N<<1],ct,ps1[N],ps2[N],as[2][N],tmp[N];
bool fg1,fg2;
struct node{
	int p,v;
}p1,p2,t1,t2;
void wk()
{
	scanf("%d",&n);
	fg1=0,fg2=0;
	memset(ps1,0,sizeof(ps1));
	memset(ps2,0,sizeof(ps2));
	memset(as,0,sizeof(as));
	memset(a,0,sizeof(a));
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&a[i]);
		if(ps1[a[i]])ps2[a[i]]=i;
		else ps1[a[i]]=i;
	}
	if(n==1){printf("LL\n");return;}
	ct=1;p1.p=2,p1.v=a[2];
	p2.p=n*2,p2.v=a[n*2];
	int pp=ps2[a[1]];
	t1.p=pp-1,t1.v=a[pp-1];
	t2.p=pp+1,t2.v=a[pp+1];
	as[0][1]=1,as[1][1]=2;
	while(ct<n)
	{
		ct++;
		int cnt=0;
		if(p1.v==t1.v&&p1.p<t1.p)cnt++;
		if(p1.v==t2.v)cnt++;
		if(p2.v==t1.v)cnt++;
		if(p2.v==t2.v&&p2.p>t2.p)cnt++;
		if(cnt>=2)
		{				
			if(p1.v==t1.v)
			{
				t1.p--;
				t1.v=a[t1.p];
			}
			else
			{
				t2.p++;
				t2.v=a[t2.p];
			}
			p1.p++;
			p1.v=a[p1.p];
			as[0][ct]=1;		
		}
		else if(cnt==1)
		{
			if(p1.v==t1.v&&p1.p<t1.p)
			{
				p1.p++;t1.p--;as[0][ct]=1;
			}
			else if(p1.v==t2.v)
			{
				p1.p++;t2.p++;as[0][ct]=1;
			}
			else if(p2.v==t1.v)
			{
				p2.p--;t1.p--;as[0][ct]=2;
			}
			else if(p2.v==t2.v)
			{
				p2.p--;t2.p++;as[0][ct]=2;
			}
			p1.v=a[p1.p];p2.v=a[p2.p];
			t1.v=a[t1.p];t2.v=a[t2.p];
		}
		else
		{
			fg1=1;break;
		}
	}
	ct=1;p2.p=n*2-1,p2.v=a[n*2-1];
	p1.p=1,p1.v=a[1];
	pp=ps1[a[n*2]];
	t1.p=pp-1,t1.v=a[pp-1];
	t2.p=pp+1,t2.v=a[pp+1];
	while(ct<n)
	{
		ct++;
		int cnt=0;
		if(p1.v==t1.v&&p1.p<t1.p)cnt++;
		if(p1.v==t2.v)cnt++;
		if(p2.v==t1.v)cnt++;
		if(p2.v==t2.v&&p2.p>t2.p)cnt++;
		if(cnt>=2)
		{			
			if(p1.v==t1.v)
			{
				t1.p--;
				t1.v=a[t1.p];
			}
			else
			{
				t2.p++;
				t2.v=a[t2.p];
			}
			p1.p++;
			p1.v=a[p1.p];
			as[1][ct]=1;	
		}
		else if(cnt==1)
		{
			if(p1.v==t1.v&&p1.p<t1.p)
			{
				p1.p++;t1.p--;as[1][ct]=1;
			}
			else if(p1.v==t2.v)
			{
				p1.p++;t2.p++;as[1][ct]=1;
			}
			else if(p2.v==t1.v)
			{
				p2.p--;t1.p--;as[1][ct]=2;
			}
			else if(p2.v==t2.v)
			{
				p2.p--;t2.p++;as[1][ct]=2;
			}
			p1.v=a[p1.p];p2.v=a[p2.p];
			t1.v=a[t1.p];t2.v=a[t2.p];
		}
		else
		{
			fg2=1;break;
		}
	}
	int kk;
	if(fg1&&fg2){
		printf("-1\n");return;
	}
	else if(fg1)kk=1;
	else if(fg2)kk=0;
	else{
		for(int i=1;i<=n;i++)
		{
			if(as[0][i]>as[1][i]){kk=1;break;}
			if(as[0][i]<as[1][i]){kk=0;break;}
		}
	}
	int l=0,r=n*2+1;
	for(int i=1;i<=n;i++)
	{
		if(as[kk][i]==1)
		{
			l++;tmp[i]=a[l];printf("L");
		}
		else
		{
			r--;tmp[i]=a[r];printf("R");
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(a[l+1]==tmp[i]){
			l++;printf("L");
		}
		else
		{
			r--;printf("R");
		}
	}
	printf("\n");
}
int main()
{
	scanf("%d",&T);
	while(T--)wk();
}
/*
1
20
3 5 13 2 19 9 20 6 11 4 10 8 7 17 15 1 18 14 16 18 15 17 7 12 8 10 4 11 6 20 9 19 2 13 3 5 1 14 16 12*/