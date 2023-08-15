
/*   Maximum Subarray Sum   */

#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long int m=0, sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        m= max(sum, m);
        if(sum<0)
        {
            sum=0;
        }
    }
    return m;
}

int main()
{
    int arr[]={1,2,7,-4,3,2,-10,9,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxSubarraySum(arr, n);
}