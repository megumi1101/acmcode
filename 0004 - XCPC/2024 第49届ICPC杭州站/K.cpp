// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCæ­å·ç«?// Problem: #9736. Kind of Bingo (9736)
// Submission: https://qoj.ac/submission/1482721
// Language: C++23

#include<iostream>
#include<algorithm>
using namespace std;
int mark[100001];
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int T,n,m,k,ans;
    cin>>T;
    while(T--){
        cin>>n>>m>>k,ans=1e9+7;
        for(int i=1,x;i<=n*m;++i) cin>>x,mark[x]=i;
        if(k>=m) ans=m;
        else{
            for(int i=0;i<n;++i){
                // cout<<"i="<<i<<" i*m+1="<<i*m+1<<" (i+1)*m="<<(i+1)*m<<'\n';
                sort(mark+1+i*m,mark+1+(i+1)*m);
                ans=min(ans,mark[(i+1)*m-k]);
            }
        }
        ans=max(ans,m);
        cout<<ans<<'\n';
    }
    return 0;
}
/*
3
3 5 2
1 4 13 6 8 11 14 2 7 10 3 15 9 5 12
2 3 0
1 6 4 3 5 2
2 3 1000000000
1 2 3 4 5 6
*/
</code>