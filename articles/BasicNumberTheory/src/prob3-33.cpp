#include <iostream>
#include <cmath>

using namespace std;

namespace BasicNumberTheory_Prob3_33 {
    /*
     * Mảng này sẽ lưu ước nguyên tố lớn nhất của
     * số thứ i
     */
    int *enhanced_prime_sieve = new int[101];

    void initialize() {
        for (int i = 0; i <= 100; i++)
            enhanced_prime_sieve[i] = i;

        for (int i = 2; i <= 100; i++)
            if (enhanced_prime_sieve[i] == i)
                for (int j = 2; j * i <= 100; j++)
                    enhanced_prime_sieve[i * j] = i;
    }

    /*
     * Để giải bài toán này, ta cần phân tích n! ra
     * các thừa số nguyên tố: a^b . c^d . e^f ... y^z
     * và đáp án của bài toán là số cách chọn các ước
     * nguyên tố kia gộp lại với nhau:
     * (b+1).(d+1).(f+1)...(z+1)
     */
    int64_t count_divisor(int n) {
        int *prime_divisor_counts = new int[101];

        for (int i = 0; i <= 100; i++)
            prime_divisor_counts[i] = 0;

        for (int i = 2; i <= n; i++) {
            int tmp = i;

            do {
                prime_divisor_counts[enhanced_prime_sieve[tmp]]++;

                tmp /= enhanced_prime_sieve[tmp];
            } while (tmp != 1);
        }

        int64_t result = 1;

        for (int i = 2; i <= 100; i++)
            if (prime_divisor_counts[i] != 0)
                result *= (prime_divisor_counts[i] + 1);

        return result;
    }

    void solve() {
        initialize();

        int test_cases;

        cin >> test_cases;

        while (test_cases--) {
            int n;

            cin >> n;

            cout << count_divisor(n) << endl;
        }
    }
}
