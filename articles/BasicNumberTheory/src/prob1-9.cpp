#include <iostream>

using namespace std;

namespace BasicNumberTheory_Prob1_9 {
    void solve() {
        int a, b;
        cin >> a >> b;

        for (int i = a; i <= b; i++)
            for (int j = i + 1; j <= b; j++) {
                bool is_co_prime = true;

                if (j % i == 0) continue;

                for (int divider = 2; divider * divider <= i; divider++) {
                    if (i % divider != 0) continue;

                    int other_divider = i / divider;

                    if (j % divider == 0 || j % other_divider == 0) {
                        is_co_prime = false;
                        break;
                    }
                }

                if (is_co_prime)
                    cout << '(' << i << ',' << j << ')' << endl;
            }
    }
}
