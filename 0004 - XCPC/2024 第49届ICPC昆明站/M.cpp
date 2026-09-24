#include<iostream>
#include<algorithm>
using namespace std;
int a[1001][1001];
int main(){
    int T,n,m;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>m;
        if(!(n&1)){ // n even
            for(int j=0;j<m;++j) for(int i=0;i<n;++i)  a[i][j]=j*n+i+1;
        }
        else{
            if(!(m&1)){ // m even
                for(int i=0;i<n;++i) for(int j=0;j<m;++j) a[i][j]=i*m+j+1;
            }
            else{
                for(int i=0;i<n;++i){
                    if(i&1){
                        for(int j=0;j<m-1;++j) a[i][j]=i*m+j+2;
                        a[i][m-1]=i*m+1;
                    }
                    else for(int j=0;j<m;++j) a[i][j]=i*m+j+1;
                }
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j) cout<<a[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}
