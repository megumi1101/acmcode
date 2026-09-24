#include<bits/stdc++.h>
using namespace std;
const int N=1200010;
int id[N],a[N],t[N][2],m;
map<pair<int,int>,int>mp[4];
int main()
{
      scanf("%d",&m);
      if(m==1){printf("2");return 0;}
      m=1<<m;
      long long ans=(long long)(1+m)*m/2;
      for(int i=1;i<=m;i++) 
      {
          scanf("%d",&a[i]);
          id[a[i]]=i;
      }
      for(int i=0;i<m/2;i++) 
      {
          t[id[i]][0]=(rand()|rand()<<15);
          t[id[i]][1]=(rand()|rand()<<15);
          t[id[(m-1)^i]][0]=t[id[i]][0];
          t[id[(m-1)^i]][1]=t[id[i]][1];
      }
      for(int i=1;i<=m;i++) 
      {
          t[i][0]^=t[i-1][0];
          t[i][1]^=t[i-1][1];
      }
      for(int i=0;i<=m;i++) 
      {
          pair<int,int> qwq=make_pair(t[i][0],t[i][1]);
          ans-=mp[i%4][qwq];
          mp[i%4][qwq]++; 
      }
      cout<<ans;
      return 0;
}