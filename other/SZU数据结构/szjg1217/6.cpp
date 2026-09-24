#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> gold(N), medal(N), pop(N);
    for (int i = 0; i < N; i++) {
        cin >> gold[i] >> medal[i] >> pop[i];
    }

    vector<int> query(M);
    for (int i = 0; i < M; i++) cin >> query[i];

    for (int id = 0; id < M; id++) {
        int x = query[id];
        int bestRank = N + 1;
        int bestType = 5;

        for (int type = 1; type <= 4; type++) {
            int rank = 1;
            for (int i = 0; i < N; i++) {
                bool better = false;
                if (type == 1) better = gold[i] > gold[x];
                if (type == 2) better = medal[i] > medal[x];
                if (type == 3) better = (double)gold[i] / pop[i] > (double)gold[x] / pop[x];
                if (type == 4) better = (double)medal[i] / pop[i] > (double)medal[x] / pop[x];
                if (better) rank++;
            }
            if (rank < bestRank || (rank == bestRank && type < bestType)) {
                bestRank = rank;
                bestType = type;
            }
        }

        if (id) cout << " ";
        cout << bestRank << ":" << bestType;
    }
    cout << "\n";
    return 0;
}
