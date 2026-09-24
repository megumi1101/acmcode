
        vector<string> s2(t);
        for (int i = 0; i < t; i++) {
            int x = c1[i];
            s2[i] = s[v[x].back()];
            v[x].pop_back();
        }
        s = move(s2);
    }