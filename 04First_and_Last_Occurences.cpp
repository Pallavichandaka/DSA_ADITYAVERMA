#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(const vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int firstOccurrence = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            firstOccurrence = mid;
            high = mid - 1; // Keep searching in the left half
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return firstOccurrence;
}

int findLastOccurrence(const vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int lastOccurrence = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            lastOccurrence = mid;
            low = mid + 1; // Keep searching in the right half
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return lastOccurrence;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int firstIndex = findFirstOccurrence(nums, target);
    int lastIndex = findLastOccurrence(nums, target);

    if (firstIndex == -1) {
        cout << "The target is not present in the array." << endl;
    } else {
        cout << "The first occurrence of the target is at index: " << firstIndex << endl;
        cout << "The last occurrence of the target is at index: " << lastIndex << endl;
    }

    return 0;
}
