#include <bits/stdc++.h>

using namespace std;

string s = "DRUL";
const int Mx = 1e4;
mt19937_64 rng(123);
int main() {
    for (int t = 0; t < 5; t++) {
        for (int op = 0; op < 4; op++) {
            for (int i = 0; i < 20; i++) {
                cout << s[op];
            } 
        }
        
        for (int i = 0; i < Mx - 80; i++) {
            cout << s[(rng() ^ rng()) & 3];
        }
    }
    
}