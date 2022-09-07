#include <iostream>

using namespace std;

namespace OneDimensionArray_Prob22 {
    int min(int a, int b) {
        return (a < b) ? a : b;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int cnt[1000001] = {0};

    void solve() {
        int n, m;
        cin >> n >> m;

        int min_value = 1e9, max_value = -1e9;

        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            min_value = min(min_value, a[i]);
            max_value = max(max_value, a[i]);
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
            cnt[b[i]]++;
            min_value = min(min_value, b[i]);
            max_value = max(max_value, b[i]);
        }

        for (int i = min_value; i <= max_value; i++)
            if (cnt[i])
                cout << i << " ";

        cout << endl;

        for (int i = min_value; i <= max_value; i++)
            if (cnt[i] == 2)
                cout << i << " ";

        cout << endl;
    }
}
