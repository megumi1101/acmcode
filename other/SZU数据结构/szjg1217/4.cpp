#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> heap(1);
    unordered_map<int, int> pos;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        heap.push_back(x);
        int idx = heap.size() - 1;
        while (idx > 1 && heap[idx] < heap[idx / 2]) {
            swap(heap[idx], heap[idx / 2]);
            idx /= 2;
        }
    }

    for (int i = 1; i < heap.size(); i++) pos[heap[i]] = i;

    cin.ignore();
    while (M--) {
        string line;
        getline(cin, line);

        if (line.find("is the root") != string::npos) {
            int x = stoi(line);
            cout << (pos[x] == 1 ? "T\n" : "F\n");
        } 
        else if (line.find("are siblings") != string::npos) {
            int x, y;
            sscanf(line.c_str(), "%d and %d are siblings", &x, &y);
            cout << ((pos[x] / 2 == pos[y] / 2 && pos[x] != pos[y]) ? "T\n" : "F\n");
        } 
        else if (line.find("is the parent of") != string::npos) {
            int x, y;
            sscanf(line.c_str(), "%d is the parent of %d", &x, &y);
            cout << (pos[y] / 2 == pos[x] ? "T\n" : "F\n");
        } 
        else if (line.find("is a child of") != string::npos) {
            int x, y;
            sscanf(line.c_str(), "%d is a child of %d", &x, &y);
            cout << (pos[x] / 2 == pos[y] ? "T\n" : "F\n");
        }
    }
    return 0;
}
