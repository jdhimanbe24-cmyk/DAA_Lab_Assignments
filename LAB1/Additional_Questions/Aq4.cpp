// Program: Specialty of a Sequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {3, 1, 4, 2};
    int k = 1;
    int n = A.size();
    int specialty = 0;

    for (int i = 0; i < n; i++) {
        vector<int> B(n);
        for (int j = 0; j < n; j++)
            B[j] = (A[j] > A[i]);

        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        bool isSpecial = false;

        for (int x : B) {
            sum += x;
            if (mp.count(sum - k)) {
                isSpecial = true;
                break;
            }
            mp[sum]++;
        }

        if (isSpecial)
            specialty += A[i];
    }

    cout << specialty;
    return 0;
}
