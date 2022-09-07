#include <iostream>

using namespace std;

namespace BasicNumberTheory_Prob1_1 { void solve(); }

namespace BasicNumberTheory_Prob1_4 {
    void solve() {
        int test_cases;
        cin >> test_cases;

        for (int i = 1; i <= test_cases; i++)
            BasicNumberTheory_Prob1_1::solve();
    }
}
