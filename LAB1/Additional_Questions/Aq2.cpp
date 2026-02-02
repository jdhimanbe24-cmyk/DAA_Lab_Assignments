// Program: Longest Good Subsequence (Absolute Difference ≤ 10)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {1, 5, 6, 7, 15, 20};
    int n = A.size();

    sort(A.begin(), A.end());

    int ans = 1, l = 0;
    for (int r = 0; r < n; r++) {
        while (A[r] - A[l] > 10)
            l++;
        ans = max(ans, r - l + 1);
    }

    cout << ans;
    return 0;
}
