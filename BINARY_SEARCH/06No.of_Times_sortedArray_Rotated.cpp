#include<bits/stdc++.h>
using namespace std;

int binary(int arr[], int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        int next=(mid+1)%n;
        int prev=(mid-1+n)%n;
        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev])
        {
            return mid;
        }
        else if(arr[low]<=arr[mid])
        {
           low=mid+1;
        }
        else if(arr[mid]<=arr[n-1]) {
            
             high=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={180,20,30,60,120,150};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result=binary(arr,n);
    cout<<result<<endl;
    
    return 0;
}