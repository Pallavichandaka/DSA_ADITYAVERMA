#include<bits/stdc++.h>
using namespace std;

int findFloor(const vector<long long>& a, long long n, long long x) {
    int l = 0;
    int h = n - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;

        if (a[mid] == x) {
            return mid; 
        } else if (a[mid] < x) {
            l = mid + 1; // Search right half for a larger element
        } else {
            h = mid - 1; // Search left half for a smaller element (potential floor)
        }
    }
    // If element not found, return h (index of the last element checked),which might be the floor if x is larger than all elements
    return h;
}

int main() {
  vector<long long> arr = {1, 2, 4, 6, 8, 10};
  long long n = arr.size();
  long long x = 5;

  int index = findFloor(arr, n, x);

  if (index != -1) {
    cout << "Floor of " << x << " is found at index " << index << " (value: " << arr[index] << ")" << endl;
  } else {
    cout << "No floor found for " << x << endl;
  }

  return 0;
}