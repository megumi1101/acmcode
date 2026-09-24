if (ans.size() + 1 == (1 << (n - 1))) {
            cout << "Yes\n";
            for (auto [x, y] : ans) {
                cout << x << " " << y << "\n";
            }
        } else {
            cout << "No\n";
        }