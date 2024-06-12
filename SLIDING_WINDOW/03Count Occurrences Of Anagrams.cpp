#include <bits/stdc++.h>
using namespace std;

int CountOfAnagram(const string& str, const string& pattern) {
    int n = str.length();
    int start = 0, end = 0;
    unordered_map<char, int> d;
    int ans = 0;
    int k = pattern.length();

    for (char c : pattern) {
        d[c]++;
    }
    int count = d.size();

    while (end < n) {
        if (d.find(str[end]) != d.end()) {
            d[str[end]]--;
            if (d[str[end]] == 0) {
                count--;
            }
        }

        if (end - start + 1 < k) {
            end++;
        } else if (end - start + 1 == k) {
            if (count == 0) {
                ans++;
            }

            if (d.find(str[start]) != d.end()) {
                d[str[start]]++;
                if (d[str[start]] == 1) {
                    count++;
                }
            }

            start++;
            end++;
        }
    }
    return ans;
}

int main() {
    string str = "forxxorfxdofr";
    string pattern = "for";
    cout << "Count of occurrences of anagrams: " << CountOfAnagram(str, pattern) << endl;
    return 0;
}
