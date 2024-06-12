#include <bits/stdc++.h>
using namespace std;

int FirstOccurrence(const vector<int>& nums, int target) {
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

int LastOccurrence(const vector<int>& nums, int target) {
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
int countOccurrences(const vector<int>& nums, int target) {
    int firstIndex = FirstOccurrence(nums, target);
    if (firstIndex == -1) {
        return 0; // Target is not present in the array
    }
    
    int lastIndex = LastOccurrence(nums, target);
    return lastIndex - firstIndex + 1;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int count = countOccurrences(nums, target);

    if (count == 0) {
        cout << "The target is not present in the array." << endl;
    } else {
        cout << "The target occurs " << count << " times in the array." << endl;
    }

    return 0;
}
