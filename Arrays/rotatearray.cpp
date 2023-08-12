 
/*   Cyclically rotate an array by one   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void rotate(vector<int>& arr, int n) 
{
    int temp=arr[n-1];
    for(int i=n-1; i>=1; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}

int main()
{
    vector<int> arr={1,2,3,4,5};
    rotate(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
}