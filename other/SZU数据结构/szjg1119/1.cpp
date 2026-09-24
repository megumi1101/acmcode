#include <iostream>
using namespace std;

void display(int arr[], int len) {
    cout << len << " ";
    for (int i = 1; i <= len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int find(int arr[], int len, int target) {
    for (int i = len; i >= 0; i--) {
        if (arr[i] == target) {
            return i;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int arr[1010];
        int len;
        cin >> len;
        for (int i = 1; i <= len; i++) {
            cin >> arr[i];
        }
        display(arr, len);

        int pos, val;
        cin >> pos >> val;
        if (pos > len + 1 || pos <= 0) {
            cout << "ERROR" << endl;
        } else {
            for (int i = len + 1; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = val;
            len++;
            display(arr, len);
        }

        cin >> pos;
        if (pos > len || pos <= 0) {
            cout << "ERROR" << endl;
        } else {
            for (int i = pos; i < len; i++) {
                arr[i] = arr[i + 1];
            }
            len--;
            display(arr, len);
        }

        int delVal;
        cin >> delVal;
        arr[0] = delVal;
        int idx = find(arr, len, delVal);
        if (idx) {
            for (int j = idx; j < len; j++) {
                arr[j] = arr[j + 1];
            }
            len--;
            display(arr, len);
        } else {
            cout << "ERROR" << endl;
        }

        int target;
        cin >> target;
        arr[0] = target;
        idx = find(arr, len, target);
        int cnt = len - idx + 1;
        if (idx) {
            cout << 1 << " " << idx << " " << cnt << endl;
        } else {
            cout << 0 << " " << 0 << " " << cnt << endl;
        }
    }

    return 0;
}
