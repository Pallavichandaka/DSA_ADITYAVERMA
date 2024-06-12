#include <bits/stdc++.h>
using namespace std;

vector<int> printFirstNegativeInteger(int A[], int N, int K) {
    int i = 0, j = 0;
    deque<int> ans;
    vector<int> res;
    
    while (j < N) {
        if (A[j] < 0) {
            ans.push_back(A[j]);
        }
        if (j - i + 1 < K) {
            j++;
        } else if (j - i + 1 == K) {
            if (ans.empty()) {
                res.push_back(0);
            } else {
                res.push_back(ans.front());
                if (A[i] == ans.front()) {
                    ans.pop_front();
                }
            }
            i++;
            j++;
        }
    }

    return res;
}

int main() {
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    vector<int> result = printFirstNegativeInteger(arr, N, K);

    cout << "First negative number in every window of size " << K << " is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
