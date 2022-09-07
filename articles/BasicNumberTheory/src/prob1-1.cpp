#include <iostream>

using namespace std;

namespace BasicNumberTheory_Prob1_1 {
    void solve() {
        int n;
        cin >> n;

        if (n < 2) {
            cout << "NO";
            return;
        }

        // Kiểm tra từ 2 đến sqrt(n), nếu tồn tại ước
        // của n thì in ra NO
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                cout << "NO";
                return;
            }

        // Sau khi kiểm tra tất cả các trường hợp
        // mà không phải hợp số thì in ra YES
        cout << "YES";
    }
}