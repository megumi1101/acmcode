+ 1), ansr(rt + 1);
        ansl[0] = ansr[0] = 1;
        nl = 1, nr = 1;
        now = 1;
        int op = 0, tun = 0;
        while (nl <= lf || nr <= rt) {
            if (op == 0) {
                if (a[nl] == 0) {
                    ansl[nl] = ++now;
                    nl++;
                    tun = 0;
                } else {
                    if (tun == 1) {
                        ansl[nl] = ++now;
                        nl++;
                        op ^= 1;
                    }
                }
            } else {
                if (b[nr] == 0) {
                    ansr[nr] = ++now;
                    nr++;
                    tun = 0;
                } else {
                    if (tun == 1) {
                        ansr[nr] = ++now;
                        nr++;
                        op ^= 1;
                    }
                }
            }
        }
        for (int i = 0; i < lf; i++) {
            cout << ansl[i] << " " << ansl[i + 1] << "\n";
        }
        for (int i = 0; i < rt; i++) {
            cout << ansr[i] << " " << ansr[i + 1] << "\n";
        }