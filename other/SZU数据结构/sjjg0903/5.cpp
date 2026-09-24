#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    struct Rec {
        int y, m, d;
        int s1, s2; 
    };

    static inline tuple<int,int,int> parseDate(const string& s) {
        int a = 0,b = 0,c = 0; char ch;
        stringstream ss(s);
        ss >> a >> ch >> b >> ch >> c;
        return {a, b, c};
    }

    static inline int dkey(int y, int m, int d) {
        return y * 10000 + m * 100 + d;
    }

    void sol() {
        int N, M;
        if(!(cin >> N >> M)) return;

        vector<pair<Rec,string>> all;
        all.reserve(N);

        for(int i=0;i<N;i++){
            string date, typ;
            int s1, s2;
            cin >> date >> typ >> s1 >> s2;
            auto [yy,mm,dd] = parseDate(date);
            all.push_back({Rec{yy,mm,dd,s1,s2}, typ});
        }

        vector<Rec> openV, closeV;
        openV.reserve(N);
        closeV.reserve(N);
        for (auto &p : all){
            if (p.second == "open") openV.push_back(p.first);
            else closeV.push_back(p.first);
        }

        auto solveOne = [&](vector<Rec>& v, const string& typ){
            sort(v.begin(), v.end(), [](const Rec& a, const Rec& b){
                return dkey(a.y,a.m,a.d) < dkey(b.y,b.m,b.d);
            });
            int n = (int)v.size();
            if (n < M) return;

            vector<int> ps1(n+1,0), ps2(n+1,0);
            for (int i=0;i<n;i++){
                ps1[i+1] = ps1[i] + v[i].s1;
                ps2[i+1] = ps2[i] + v[i].s2;
            }

            for (int i=M-1;i<n;i++){
                int sum1 = ps1[i+1] - ps1[i+1-M];
                int sum2 = ps2[i+1] - ps2[i+1-M];
                int avg1 = sum1 / M; 
                int avg2 = sum2 / M;
                cout << v[i].y << "/" << v[i].m << "/" << v[i].d
                     << " " << typ << " " << avg1 << " " << avg2 << "\n";
            }
        };

        solveOne(openV, "open");
        solveOne(closeV, "close");
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
