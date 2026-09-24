#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int inline rd()
{
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
	return ans*f;
}
int T,n,a[N];
deque<pair<int,int> >q1,q2;
void wk()
{
	while(!q1.empty())q1.pop_back();
	while(!q2.empty())q2.pop_back();
	for(int i=1;i<=n;i++)
            q1.push_back({a[i],i});
        int ans;
    while(1)
	{
    	if(q1.size()+ q2.size()==2){ans=1;break;}
        int x,id,y;
        y=q1.front().first,q1.pop_front();
        if(q2.empty()||!q1.empty()&&q1.back()>q2.back())
            x=q1.back().first,id=q1.back().second,q1.pop_back();
        else x=q2.back().first,id=q2.back().second,q2.pop_back();
        pair<int,int> now=make_pair(x - y,id);
        if(q1.empty()||q1.front()>now)
		{
            ans=q1.size()+q2.size()+2;
            int cnt=0;
            while(1)
			{
                cnt++;
                if(q1.size()+q2.size()+1==2){
                    if(cnt % 2==0)ans--;
                        break;
                    }
                int x,id;
                if(q2.empty()||!q1.empty()&&q1.back()>q2.back())
                    x=q1.back().first,id=q1.back().second,q1.pop_back();
                else x=q2.back().first,id=q2.back().second,q2.pop_back();
                now={x-now.first,id};
                if((q1.empty()||now<q1.front())&&(q2.empty()||now<q2.front())){;}
				else{if(cnt%2==0)ans--;break;}
            }
                break;
        }
		else{q2.push_front(now);}
    }
    printf("%d\n",ans);
}
int main()
{
	T=rd();n=rd();
	for(int i=1;i<=n;i++)a[i]=rd();T--;wk();
	while(T--)
	{
		int k=rd();
		for(int i=1;i<=k;i++)a[rd()]=rd();wk();
	}
}