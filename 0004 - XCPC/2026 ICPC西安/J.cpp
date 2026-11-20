#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int f[400001],sz[400001];
int getf(int v) { return f[v] == v ? v : f[v] = getf(f[v]); }
bool query(int x,int y){ return getf(x)==getf(y); }
void merge(int x,int y){
    if(query(x,y)) return;
    if(sz[f[x]]<sz[f[y]]) swap(x,y);
    sz[f[x]]+=sz[f[y]],f[f[y]]=f[x];
}
int lst[200001],a[400001];
void solution() {
    int n;
    string res;
    cin >> n;
    fill(lst+1,lst+1+n,0);
    for(int i=1;i<=(n<<1);++i) f[i]=i,sz[i]=1;
    for(int i=1;i<=(n<<1);++i){
        cin>>a[i];
        if(!lst[a[i]]) lst[a[i]]=i;
        else merge(i,lst[a[i]]);
    }
    for(int i=1;i<=n;++i) res+="()",merge((i<<1)-1,i<<1);
    for(int i=2;i+1<=(n<<1);i+=2){
        // cout<<"i = "<<i<<" f[i] = "<<getf(i)<<" f[i+1] = "<<getf(i+1)<<'\n';
        if(!query(i,i+1)) merge(i,i+1),swap(res[i-1],res[i]);
    }
    cout<<res<<'\n';
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) solution();
    return 0;
}
/*
5
2
1 2 1 2
2
2 2 1 1
3
1 2 3 1 2 3
4
1 2 3 4 3 2 1 4
7
3 6 7 1 5 6 2 2 4 3 4 7 1 5
*/


/*
1
6 7 3 2 5
1 1 4 5 1 4
1 9 1 9 8 1 0
3 8 19 26 23 34 
47 19 18 21 34 33 
34 39 25 26 21 32 
45 50 49 33 42 31 
48 53 52 55 47 46 
49 48 59 60 55 53 
58 51 56 63 60 63 
51
*/