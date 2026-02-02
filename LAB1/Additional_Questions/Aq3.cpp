// Program: Median Removal Problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {1, 2, 3, 4};

    while (A.size() > 2) {
        vector<int> medians;

        for (int i = 0; i < A.size(); i++) {
            for (int j = i + 2; j < A.size(); j += 2) {
                vector<int> temp(A.begin() + i, A.begin() + j + 1);
                sort(temp.begin(), temp.end());
                medians.push_back(temp[temp.size() / 2]);
            }
        }

        int minMedian = *min_element(medians.begin(), medians.end());
        auto it = find(A.begin(), A.end(), minMedian);
        A.erase(it);
    }

    int sum = 0;
    for (int x : A) sum += x;
    cout << sum;

    return 0;
}
