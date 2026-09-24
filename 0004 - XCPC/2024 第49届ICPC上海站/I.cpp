// QOJ user: xbbbz
// Contest: 2024 ç¬?9å±ŠICPCä¸Šæµ·ç«?// Problem: #9045. In Search of the Ultimate Artifact (9045)
// Submission: https://qoj.ac/submission/1540107
// Language: C++23

#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=998244353;
long long a[200001];
int main(){
    int T,n,k;
    long long ans,lastans;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n,greater<long long>()),ans=a[0]%mod,lastans=a[0]%mod;
        for(int i=1;i<n;++i){
            ans=ans*a[i]%mod;
            if(i%(k-1)==0){
                // cout<<"i="<<i<<" i%(k-1)==0\n";
                if(!a[i]){
                    break;
                }
                lastans=ans;
            }
            // cout<<"i="<<i<<" ans="<<ans<<" lastans="<<lastans<<'\n';
        }
        cout<<lastans<<'\n';
    }
    return 0;
}
/*
1
4 3
998244354 998244353 998244352 0
*/
</code>