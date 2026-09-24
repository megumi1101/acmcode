#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
struct node{
    int next_[26],cnt;
    node(): cnt(0) {
        for(int i=0;i<26;++i) next_[i]=0;
    }
};
vector<node> tree(2);
vector<int> f;
int res;
void insert(const string& s){
    int cur=1;
    for(int i=0;i<s.length();++i){
        // cout<<"i = "<<i<<" cur = "<<cur<<'\n';
        if(!tree[cur].next_[s[i]-'a']){
            tree[cur].next_[s[i]-'a']=tree.size();
            tree.push_back(node());
        }
        // cout<<"mark\n";
        cur=tree[cur].next_[s[i]-'a'],++tree[cur].cnt;
        // cout<<"i = "<<i<<" cur = "<<cur<<" tree[cur].cnt = "<<tree[cur].cnt<<'\n';
        if(f[tree[cur].cnt]<i+1){
            res-=(f[tree[cur].cnt]^tree[cur].cnt);
            f[tree[cur].cnt]=i+1;
            res+=(f[tree[cur].cnt]^tree[cur].cnt);
        }
    }
}
string s;
signed main(){
    int n;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n,f.resize(n+1),fill(f.begin(),f.end(),0);
    for(int i=0;i<n;++i) res+=i+1,cin>>s,insert(s),cout<<res<<'\n';
    return 0;
}