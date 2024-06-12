#include<bits/stdc++.h>
using namespace std;

int search(int A[], int n, int l, int h, int key) {
  
  while (l <= h) {
    int mid = l + (h - l) / 2;

    if (A[mid] == key) {
      return mid;
    }

    if (A[l] <= A[mid]) { // Check if left half is sorted
      if (key >= A[l] && key <= A[mid]) {
        h = mid - 1;
      } else {
        l = mid + 1;
      }
    } else { // Right half must be sorted
      if (key >= A[mid] && key <= A[h]) {
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
  }
  return -1;
}

int main() {
  int arr[] = {4, 5, 6, 7, 0, 1, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 0;

  int index = search(arr, n, 0, n - 1, key);

  if (index != -1) {
    std::cout << "Element found at index " << index << std::endl;
  } else {
    std::cout << "Element not found" << std::endl;
  }

  return 0;
}