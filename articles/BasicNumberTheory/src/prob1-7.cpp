#include <iostream>

using namespace std;

namespace BasicNumberTheory_Prob1_7 {
    void solve() {
        // Tạo 1 sàng nguyên tố cỡ 10^4 phần tử
        const int upr_bound = 1e4 - 1;
        bool *is_prime = new bool[upr_bound + 1];

        for (int i = 2; i <= upr_bound; i++)
            is_prime[i] = true;

        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= upr_bound; i++)
            if (is_prime[i])
                for (int j = 2; j * i <= upr_bound; j++)
                    is_prime[j * i] = false;

        int test_cases;
        cin >> test_cases;

        for (int i = 1; i <= test_cases; i++) {
            int n;
            cin >> n;

            for (int j = 2; j < n; j++)
                if (is_prime[j] && is_prime[n - j])
                    cout << j << " " << n - j << endl;
        }
    }
}
