#include <iostream>
#include <cmath>

using namespace std;

namespace BasicNumberTheory_Prob1_11 {
    void solve() {
        int bound = 1e6;
        bool *is_prime = new bool[bound + 1];

        for (int i = 1; i <= bound; i++)
            is_prime[i] = true;

        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i <= bound; i++)
            if (is_prime[i])
                for (int j = 2; j * i <= bound; j++)
                    is_prime[i * j] = false;

        /**
          * Mảng prime_counts lưu tổng số lượng số nguyên
          * tố với prime_counts[i] là tổng số lượng số
          * nguyên tố từ 1 đến i
          */
        int *prime_counts = new int[bound + 1];

        prime_counts[0] = prime_counts[1] = 0;

        for (int i = 2; i <= bound; i++) {
            prime_counts[i] = prime_counts[i - 1];

            if (is_prime[i]) prime_counts[i]++;
        }

        int test_cases;
        cin >> test_cases;

        for (int i = 1; i <= test_cases; i++) {
            int64_t n;
            cin >> n;

            /**
              * In ra số lượng số nguyên tố từ 1 đến căn
              * bậc 2 của n với lí thuyết từ bài 10
              */
            cout << prime_counts[(int) sqrt(n)] << endl;
        }
    }
}
