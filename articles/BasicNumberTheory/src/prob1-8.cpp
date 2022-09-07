#include <iostream>

using namespace std;

namespace BasicNumberTheory_Prob1_8 {
    bool is_prime(int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;

        return true;
    }

    void naive() {
        int test_cases;
        cin >> test_cases;

        for (int i = 1; i <= test_cases; i++) {
            int a, b, count = 0;

            cin >> a >> b;

            for (int j = a; j <= b; j++) {
                if (!is_prime(j)) continue;

                int tmp = j, digit_sum = 0, digit;
                bool has_none_prime_digit = false;

                while (tmp) {
                    digit = tmp % 10;

                    if (digit != 2 && digit != 3 &&
                        digit != 5 && digit != 7) {
                        has_none_prime_digit = true;
                        break;
                    }

                    digit_sum += digit;
                    tmp /= 10;
                }

                if (has_none_prime_digit) continue;

                if (!is_prime(digit_sum)) continue;

                ++count;
            }

            cout << count << endl;
        }
    }

    void solve() {
        naive();
    }
}
