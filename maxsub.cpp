#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0, left_sum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int low, int high) {
    if (low == high) return arr[low];

    int mid = (low + high) / 2;

    int left_sum = maxSubArraySum(arr, low, mid);
    int right_sum = maxSubArraySum(arr, mid + 1, high);
    int cross_sum = maxCrossingSum(arr, low, mid, high);

    return max(max(left_sum, right_sum), cross_sum);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum Subarray Sum = " << max_sum << endl;

    return 0;
}
