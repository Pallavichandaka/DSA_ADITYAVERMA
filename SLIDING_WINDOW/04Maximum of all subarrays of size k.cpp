 #include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans(nums.size() - k + 1);
    deque<int> q;

    int i = 0, j = 0;

    while (j < nums.size()) {
        // Calculation
        while (!q.empty() && q.back() < nums[j]) {
            q.pop_back();
        }
        q.push_back(nums[j]);

        // Move j pointer
        if (j - i + 1 < k) {
            j++;
        }
        // When we hit the window size
        else if (j - i + 1 == k) {
            // Answer calculation
            ans[i] = q.front();

            // Slide the window
            if (nums[i] == q.front()) {
                q.pop_front();
            }

            // Move pointers
            i++;
            j++;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximum of all subarrays of size " << k << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}