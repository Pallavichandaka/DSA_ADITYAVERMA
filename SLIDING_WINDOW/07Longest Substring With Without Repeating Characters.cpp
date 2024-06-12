#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeatingChars(const string& s) {
    int n = s.size();
    if (n == 0) return 0;

    unordered_map<char, int> charIndex;
    int maxLength = 0;

    for (int i = 0, j = 0; j < n; j++) {
        if (charIndex.find(s[j]) != charIndex.end() && charIndex[s[j]] >= i) {
            i = charIndex[s[j]] + 1;
        }

        charIndex[s[j]] = j;
        maxLength = max(maxLength, j - i + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: "
         << longestSubstringWithoutRepeatingChars(s) << endl;
    return 0;
}
