#include<bits/stdc++.h>
using namespace std;

int search(const vector <int>& nums, int target) {
  int low = 0;
  int high = nums.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
   
    if (nums[mid] == target) {
      return mid;
    }
     else if (mid > 0 && nums[mid - 1] == target) {
      return mid - 1;
    }
     else if (mid < high && nums[mid + 1] == target) {
      return mid + 1;
    }

    // Adjust search based on nearly sorted nature
    if (nums[mid] < target) {
      // Target might be in the right half
      low = mid + 1;
    } else {
      // Target might be in the left half
      high = mid - 1;
    }
  }

  return -1; 
}

int main() {
  vector<int> nums = {5, 10, 30, 20, 40};
  int target;
  cin >> target;

  int index = search(nums, target);

  if (index != -1) {
    cout << "Element found at index " << index << endl;
  } else {
    cout << "Element not found" << endl;
  }

  return 0;
}