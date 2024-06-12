#include<bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int n = letters.size();
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (letters[mid] > target) {
            // Potential candidate for next alphabetical element
            return letters[mid];
        } else if (letters[mid] == target) {
            // Search right half for the next element (might wrap around)
            low = mid + 1;
        } else {
            // Search left half
            high = mid - 1;
        }
    }

    // If element not found or larger than all elements (wraparound):
    // Return the first element (assuming wraparound)
    return letters[0];
}

int main() {
  vector<char> letters = {'a', 'b', 'c', 'd', 'z'};
  char target = 'z';

  char nextChar = nextGreatestLetter(letters, target);

  if (nextChar != target) {
    cout << "Next alphabetical element: " << nextChar << endl;
  } else {
    cout << "No next alphabetical element (wraparound to first element)" << endl;
  }

  return 0;
}
