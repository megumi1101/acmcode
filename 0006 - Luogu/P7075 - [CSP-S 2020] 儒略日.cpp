#include<bits/stdc++.h>
using namespace std;
#define int long long
int inline rd(){int ans=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){ans=ans*10+ch-'0';ch=getchar();}
    return ans*f;
}
int T,x,f[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int g[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool pd(int x){if(x%4==0&&x%100!=0)return 0;
    if(x%400==0)return 0;return 1;
}
void wk2(int x,int op){int d=1,m=1;
    if(op==1){while(x>=f[m])x-=f[m],m++;d+=x;}
    else{while(x>=g[m])x-=g[m],m++;d+=x;}
    printf("%lld %lld ",d,m);
}
void wk(){x=rd();int y=4713;
    if(x<1721424){int tmp=x/1461*4;y-=tmp;x%=1461;
        if(y%4==1)tmp=366;
        else tmp=365;
        while(x>=tmp){y--;x-=tmp;
            if(y%4==1)tmp=366;
            else tmp=365;
        }
        if(y%4==1)wk2(x,0);
        else wk2(x,1);
        printf("%lld BC\n",y);return;
    }
    x-=1721424;y=1;
    if(x>577736)x+=10;
    if(x<584400){int tmp=x/1461*4;y+=tmp;x%=1461;
        if(y%4)tmp=365;
        while(x>=tmp){y++;x-=tmp;
            if(y%4)tmp=365;
            else tmp=366;
        }
        if(y%4)wk2(x,1);
        else wk2(x,0);
        printf("%lld\n",y);return;
    }
    x-=584400,y+=1600;
    int tmp=x/146097*400;x%=146097,y+=tmp;
    if(x==146096)x-=36524*3,y+=300;
    else tmp=x/36524*100,y+=tmp,x%=36524;
    tmp=x/1461*4;x%=1461;y+=tmp;
    if(y%4)tmp=365;
    while(x>=tmp){y++;x-=tmp;
        if(y%4)tmp=365;
        else tmp=366;
    }
    wk2(x,pd(y));printf("%lld\n",y);
}
signed main(){T=rd();
    while(T--)wk();
}