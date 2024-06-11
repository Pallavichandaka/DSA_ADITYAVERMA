#include<bits/stdc++.h>
using namespace std;

int findCeiling(const vector<long long>& a, long long n, long long x) {
    int l = 0;
    int h = n - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;

        if (a[mid] == x) {
            return mid; 
        } else if (a[mid] < x) {
            l = mid + 1; // Search right half for a larger element (potential ceiling)
        } else {
            h = mid - 1; // Search left half for a smaller element
        }
    }

    // If element not found, return l (index of the first element checked after the search)
    // which might be the ceiling if x is smaller than all elements
    return l;
}

int main() {
  vector<long long> arr = {1, 2, 4, 6, 8, 10};
  long long n = arr.size();
  long long x = 5;

  int index = findCeiling(arr, n, x);

  if (index != n) {
    cout << "Ceiling of " << x << " is found at index " << index << " (value: " << arr[index] << ")" << endl;
  } else {
    cout << "No ceiling found for " << x << " (larger than all elements)" << endl;
  }

  return 0;
}