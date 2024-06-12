#include <bits/stdc++.h>
using namespace std;

int longestSubstring(const string& s, int k) {
    int n = s.size();
    unordered_map<char, int> charCount;
    int maxLength = 0, i = 0, j = 0;

    while (j < n) {
        charCount[s[j]]++;

        if (charCount.size() < k) {
            j++;
        } else if (charCount.size() == k) {
            maxLength = max(maxLength, j - i + 1);
            j++;
        } else {
            while (charCount.size() > k) {
                charCount[s[i]]--;
                if (charCount[s[i]] == 0) {
                    charCount.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }

    return maxLength;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    cout << "Longest substring with " << k << " unique characters is of length: " 
         << longestSubstring(s, k) << endl;
    return 0;
}
