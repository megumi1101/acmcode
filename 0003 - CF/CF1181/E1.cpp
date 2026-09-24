#include<bits/stdc++.h>
using namespace std;
namespace xbbbz{
    void main();
}
int main(){
    return xbbbz::main(),0;
}
namespace xbbbz{
    struct rec{
        int x1_,y1_,x2_,y2_;
    };
    bool pd(vector<rec> v){
        int n=v.size();
        if(n<=1)return 1;
        for(int XY=1;XY<=2;XY++){
            int mxx=-1;
            sort(v.begin(),v.end(),[&](rec a,rec b){return a.x1_<b.x1_;});
            for(int i=0;i<n-1;i++){
                mxx=max(mxx,v[i].x2_);
                if(v[i+1].x1_>=mxx){
                    vector<rec>L,R;
                    for(int j=0;j<=i;j++)L.push_back(v[j]);
                    for(int j=i+1;j<n;j++)R.push_back(v[j]);
                    return pd(L)&&pd(R);
                }
            }
            for(auto &i : v){
                swap(i.x1_,i.y1_);swap(i.x2_,i.y2_);
            }
        }
        return 0;
    }
    void main(){
        ios::sync_with_stdio(false);cin.tie(nullptr);
        int n;vector<rec>ed;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x1_,x2_,y1_,y2_;
            cin>>x1_>>y1_>>x2_>>y2_;
            ed.push_back({x1_,y1_,x2_,y2_});
        }
        puts(pd(ed)?"YES":"NO");
    }
}
