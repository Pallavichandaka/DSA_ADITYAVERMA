#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector <int> &nums, int target)
{
    int n= nums.size();
    int low=0;
    int high= n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (nums[mid]==target){
            return mid;
        }
        else if (nums[mid] > target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums ={1, 2, 3, 4, 5, 6};
     int target= 6;
     int index= binarysearch(nums, target);
    if (index == -1){
    cout << "The target is not present." << endl;
    }
    else {
    cout << "The target is at index: " << index << endl;
    }
    return 0;


}