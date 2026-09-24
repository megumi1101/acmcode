#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    #define int long long
    void solve(){
        #define lowb lower_bound 
        int n,q;cin>>n>>q;
        set<int> s1;
        multiset<int> s2;
        vector<int> a(n+q+10);
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a.begin()+1,a.begin()+n+1);
        for(int i=1;i<=n;i++)s1.insert(a[i]);
        for(int i=1;i<n;i++)s2.insert(a[i+1]-a[i]);
        if(s1.size()>1)cout<<*prev(s1.end())-*s1.begin()-*prev(s2.end())<<"\n";
        else cout<<"0"<<"\n";
        for(int i=1;i<=q;i++){
            int op,x;
            cin>>op>>x;
            if(op){
                auto it=s1.lower_bound(x);
                if(it!=s1.begin()&&it!=s1.end()){
                    int s=*prev(it),t=*it;
                    s2.erase(s2.find(t-s));s2.insert(x-s);s2.insert(t-x);
                    
                }
                else if(it==s1.begin()&&it!=s1.end()){
                    int t=*it;s2.insert(t-x);
                }
                else if(it!=s1.begin()&&it==s1.end()){
                    int s=*prev(it);s2.insert(x-s);
                }
                s1.insert(x);
            }
            else{
                auto it=s1.lower_bound(x);
                if(it!=s1.begin()&&it!=prev(s1.end())){
                    int s=*prev(it),t=*next(it);    
                    s2.erase(s2.find(x-s));
                    s2.erase(s2.find(t-x));
                    s2.insert(t-s);
                }
                else if(it==s1.begin()&&it!=prev(s1.end())){
                    int t=*next(it);
                    s2.erase(s2.find(t-x));
                }
                else if(it!=s1.begin()&&it==prev(s1.end())){
                    int s=*prev(it);
                    s2.erase(s2.find(x-s));
                }
                s1.erase(x);
            }
            if(s1.size()>1)cout<<*prev(s1.end())-*s1.begin()-*prev(s2.end())<<"\n";
            else cout<<"0"<<"\n";
            // if(i==3){
            //     cout<<"dfs"<<*prev(s1.end())<<" "<<*s1.begin()<<" "<<*prev(s2.end())<<"dffd";
            // }
        }
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        // int T;cin>>T;
        // while(T--)
            solve();
    }
}
/*
1 5
1 0 0 1 1
1 8
1 0 1 1 0 1 1 1
*/
