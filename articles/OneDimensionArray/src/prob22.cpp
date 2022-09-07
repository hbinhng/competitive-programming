#include <iostream>

using namespace std;

namespace OneDimensionArray_Prob22 {
    const int MAX_BOUND = 1e6;
    int cnt[MAX_BOUND + 1] = {0};

    void solve() {
        int n, m, j;
        cin >> n >> m;

        for (int i = 0; i < n + m; i++) {
            cin >> j;
            cnt[j]++;
        }

        for (int i = 0; i <= MAX_BOUND; i++)
            if (cnt[i])
                cout << i << " ";

        cout << endl;

        for (int i = 0; i <= MAX_BOUND; i++)
            if (cnt[i] == 2)
                cout << i << " ";

        cout << endl;
    }
}
