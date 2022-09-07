#include <iostream>

using namespace std;

namespace BasicNumberTheory_Prob1_2 {
    void solve() {
        int n;
        cin >> n;

        // Tạo 1 mảng đánh dấu is_prime[i]
        // với is_prime[i] = true nếu i là số nguyên tố
        // ngược lại is_prime[i] = false nếu i là hợp số
        bool *is_prime = new bool[n + 1];

        // Ta mặc định coi tất cả các số đều là số nguyên tố
        for (int i = 2; i <= n; i++)
            is_prime[i] = true;

        // 0 và 1 chắc chắn không phải số nguyên tố
        is_prime[0] = is_prime[1] = false;

        // Duyệt từ 2 đến sqrt(n)
        // Nếu số thứ i là số nguyên tố, đánh dấu tất cả
        // các bội của i là hợp số
        for (int i = 2; i * i <= n; i++)
            if (is_prime[i])
                for (int j = 2; j * i <= n; j++)
                    is_prime[j * i] = false;

        for (int i = 2; i <= n; i++)
            if (is_prime[i])
                cout << i << " ";
    }
}