#include <iostream>

using namespace std;

namespace BasicNumberTheory_Prob1_10 {
    /**
      * Các số có đúng ba ước số chỉ có thể có các ước:
      * - 1
      * - chính nó
      * - căn bậc 2 của nó
      * vì nếu 1 số n chia hết cho 1 số i không phải căn
      * bậc 2 của n thì n cũng sẽ chia hết cho n / i
      *
      * Suy ra các số thoả mãn yêu cầu của bài chính là
      * bình phương của 1 số nguyên tố
      */

    void solve() {
        int upr_bound = 1e6;
        bool *is_prime = new bool[1001];

        for (int i = 2; i <= 1000; i++)
            is_prime[i] = true;

        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i <= 1000; i++)
            if (is_prime[i])
                for (int j = 2; j * i <= 1000; j++)
                    is_prime[i * j] = false;

        int test_cases;
        cin >> test_cases;

        for (int i = 1; i <= test_cases; i++) {
            int n;
            cin >> n;

            for (int j = 2; j * j <= n; j++)
                if (is_prime[j])
                    cout << j * j << " ";
            cout << endl;
        }
    }
}
