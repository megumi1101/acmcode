#include<bits/stdc++.h>

using namespace std;

#define int long long

using S = array<int, 6>;

// highcard 0 高牌
// pair 1 一对
// two pair 2 两对
// three 3 三条
// straight 4 顺子
// flush 5 同花
// full house 6 葫芦
// four 7 四条
// str && flush 8 同花顺

int getid(string s) {
    string rks = "23456789TJQKA";
    string cuits = "CDHS";

    int rk = rks.find(s[0]);
    int cuit = cuits.find(s[1]);
    return cuit * 13 + rk;
}

pair<int, int> getpair(int id) {
    return {id % 13 + 2, id / 13};
    // 2 到 14
}

S getbig(const array<int, 5> &a) {
    array<int, 15> rkcnt{}; // 2 to 14
    array<int, 4> cuitcnt{};
    for (int x : a) {
        auto[rk, cuit] = getpair(x);
        rkcnt[rk]++;
        cuitcnt[cuit]++;
    }

    int flush = 0;
    for (int i = 0; i < 4; i++) {
        if (cuitcnt[i] == 5) {
            flush = 1;
            break;
        }
    }
    
    int straight = 0;
    vector<int> dis;
    for (int i = 2; i <= 14; i++) {
        if (rkcnt[i]) {
            dis.push_back(i);
        }
    }

    if (dis.size() == 5 && dis[4] - dis[0] == 4 ) {
        straight = dis[4];
    }
    if (dis == vector<int>{2, 3, 4, 5, 14}) {
        straight = 5;
    }

    // 8
    S s;
    if (flush && straight) {
        return {8, straight, 0, 0, 0, 0};
    }

    int four = 0;
    int three = 0;
    vector<int> twos;
    vector<int> ones;
    for (int i = 14; i >= 2; i--) {
        if (rkcnt[i] == 4) {
            four = i;
        } else if (rkcnt[i] == 3) {
            three = i;
        } else if (rkcnt[i] == 2) {
            twos.push_back(i);
        } else if (rkcnt[i] == 1) {
            ones.push_back(i);
        }
    }

    if (four) {
        return {7, four, ones[0], 0, 0, 0};
    }

    if (three && twos.size() == 1) {
        return {6, three, twos[0], 0, 0, 0};
    }

    if (flush) {
        return {5, ones[0], ones[1], ones[2], ones[3], ones[4]};
    }

    if (straight) {
        return {4, straight, 0, 0, 0, 0};
    }

    if (three) {
        return {3, three, ones[0], ones[1], 0, 0};
    }

    if (twos.size() == 2) {
        return {2, twos[0], twos[1], ones[0], 0, 0};
    }

    if (twos.size() == 1) {
        return {1, twos[0], ones[0], ones[1], ones[2], 0};
    }

    return {0, ones[0], ones[1], ones[2], ones[3], ones[4]};
}

void sol() {
    array<int, 5> mine;
    array<int, 5> pier;

    vector<int> used(52);
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        int id = getid(s);
        used[id] = 1;
        mine[i] = id;
    }

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        int id = getid(s);
        used[id] = 1;
        pier[i] = id;
    }


    array<S, 52> mineS;
    array<S, 52> pierS;
    for (int x = 0; x < 52; x++) {
        if (used[x]) continue;
        array<int, 5> a;
        for (int i = 0; i < 4; i++) a[i] = mine[i];
        a[4] = x;
        mineS[x] = getbig(a);

        for (int i = 0; i < 4; i++) a[i] = pier[i];
        a[4] = x;
        pierS[x] = getbig(a);
    }

    int pierwin = 0;
    int iwin = 1;

    for (int pi = 0; pi < 52; pi++) {
        if (used[pi]) continue;

        S mx;
        mx.fill(-1);
        for (int x = 0; x < 52; x++) {
            if (used[x] || x == pi) continue;
            mx = max(mx, mineS[x]);
        }

        if (pierS[pi] > mx) {
            pierwin = 1;
            iwin = 0;
        } else if (pierS[pi] == mx) {
            iwin = 0;
        }
    }


    if (pierwin == 1) {
        cout << "GeiWoCaPiXie\n";
    } else if (iwin == 1) {
        cout << "WoYaoYanPai\n";
    } else {
        cout << "PaiMeiYouWenTi\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}

/*
3
AS KH KD AC AH KS KC AD
2D 3C 3D 2C AH QH JH 2H
4C 6H KH 9H 5H 6C 7H 9S
*/