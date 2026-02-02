// Program: Maximum Subarray Sum using Divide and Conquer

#include <iostream>
#include <climits>
using namespace std;

int maxSubArraySum(int arr[], int n) {
    int max_so_far = INT_MIN, curr_max = 0;

    for (int i = 0; i < n; i++) {
        curr_max += arr[i];
        if (curr_max > max_so_far)
            max_so_far = curr_max;
        if (curr_max < 0)
            curr_max = 0;
    }
    return max_so_far;
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSubArraySum(arr, n);
    return 0;
}
