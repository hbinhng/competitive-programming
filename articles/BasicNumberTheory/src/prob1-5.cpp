#include <iostream>

using namespace std;

namespace BasicNumberTheory_Prob1_5 {
    void solve() {
        // Tạo 1 sàng nguyên tố cỡ 10^6 phần tử
        const int upr_bound = 1e6 - 1;
        bool *is_prime = new bool[upr_bound + 1];

        for (int i = 2; i <= upr_bound; i++)
            is_prime[i] = true;

        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= upr_bound; i++)
            if (is_prime[i])
                for (int j = 2; j * i <= upr_bound; j++)
                    is_prime[j * i] = false;

        // Tạo mảng lưu tổng số lượng số nguyên tố
        // với primes_count[i] là tổng số lượng số
        // nguyên tố từ 0 đến i
        int *primes_count = new int[upr_bound + 1];
        primes_count[0] = primes_count[1] = 0;

        for (int i = 2; i <= upr_bound; i++) {
            primes_count[i] = primes_count[i - 1];

            if (is_prime[i]) {
                bool all_digit_prime = true;
                int num = i;

                // Kiểm tra các chữ số của num có là hợp số
                while (num != 0) {
                    int digit = num % 10;

                    if (!is_prime[digit]) {
                        all_digit_prime = false;
                        break;
                    }

                    num /= 10;
                }

                if (all_digit_prime) ++primes_count[i];
            }
        }

        int test_cases;
        cin >> test_cases;

        for (int i = 1; i <= test_cases; i++) {
            int a, b;
            cin >> a >> b;

            cout << primes_count[b] - primes_count[a - 1] << endl;
        }
    }
}
