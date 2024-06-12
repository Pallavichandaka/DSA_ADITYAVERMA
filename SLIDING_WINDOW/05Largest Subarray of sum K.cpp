#include <bits/stdc++.h>
using namespace std;

int largestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> sum_map;
    int sum = 0, max_len = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == k) {
            max_len = i + 1;
        }

        if (sum_map.find(sum) == sum_map.end()) {
            sum_map[sum] = i;
        }

        if (sum_map.find(sum - k) != sum_map.end()) {
            max_len = max(max_len, i - sum_map[sum - k]);
        }
    }

    return max_len;
}

int main() {
    vector<int> arr = {10, 5, -2, 7, -1, 9};
    int k = 15;
    cout << "Largest subarray length: " << largestSubarray(arr, k) << endl;
    return 0;
}