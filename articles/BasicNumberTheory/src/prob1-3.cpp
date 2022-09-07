#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

namespace BasicNumberTheory_Prob1_3 {
    void solve() {
        int a, b;
        cin >> a >> b;
        int sqrt_b = sqrt(b);

        // Sàng nguyên tố giống bài 2 đến sqrt(b)
        bool *is_prime = new bool[sqrt_b + 1];

        for (int i = 2; i <= sqrt_b; i++)
            is_prime[i] = true;

        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= sqrt_b; i++)
            if (is_prime[i])
                for (int j = 2; j * i <= sqrt_b; j++)
                    is_prime[j * i] = false;

        // Tạo 1 sàng nguyên tố từ a đến b
        bool *is_prime_a2b = (new bool[b - a + 1]) - a;

        // Mặc định các số trong khoảng [a, b] đều là số
        // nguyên tố
        for (int i = a; i <= b; i++)
            is_prime_a2b[i] = true;

        // Duyệt qua các phần tử của sàng nguyên tố ban đầu
        // nếu i là 1 số nguyên tố thì đánh dấu các bội của
        // i trong khoảng [a, b] là hợp số
        for (int i = 2; i <= sqrt_b; i++)
            if (is_prime[i]) {
                int lwr_bound = max((a + i - 1) / i, 2);
                int upr_bound = b / i;

                for (int j = lwr_bound; j <= upr_bound; j++)
                    is_prime_a2b[j * i] = false;
            }

        for (int i = a; i <= b; i++)
            if (is_prime_a2b[i])
                cout << i << " ";
    }
}
