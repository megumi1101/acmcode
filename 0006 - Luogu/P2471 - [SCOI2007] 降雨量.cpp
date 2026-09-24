#include<bits/stdc++.h>
using namespace std;
const int N=50010;
map<int,int> mp;
int n,m,a[N],r[N];
int main()
{
	scanf("%d",&n);	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",a+i,r+i);
		mp[a[i]]=i;
	}
	mp[1e9+7]=n+1;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int y,x;
		scanf("%d%d",&y,&x);
    if(mp.find(y)==mp.end()&&mp.find(x)==mp.end())
		{
			printf("maybe\n");
			continue;
		}
		if(mp.find(y)==mp.end())
		{
			int k=mp.upper_bound(y)->second;
			int j=mp.find(x)->second;
			bool flag=true;
			while(k<j&&flag)
				if(r[k++]>=r[j]) flag=false;
			if(flag) printf("maybe\n");
			else printf("false\n");
			continue;
		}
		if(mp.find(x)==mp.end())
		{
			int k=mp.upper_bound(x)->second-1;
			int j=mp.find(y)->second;
			bool flag=true;
			while(j<k&&flag)
				if(r[k--]>=r[j]) flag=false;
			if(flag) printf("maybe\n");
			else printf("false\n");
			continue;
		}
		bool flag=true;
		int j=mp.find(y)->second;
		int k=mp.find(x)->second;
		if(r[k]>r[j]) flag=false;
		for(int p=j+1;p<k&&flag;p++)
			if(r[p]>=r[k]) flag=false;
		if(flag) if(k-j==x-y) printf("true\n");
				 else printf("maybe\n");
		else printf("false\n");
	}
	return 0;
}