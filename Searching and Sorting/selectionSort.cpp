
/*    Selection sort   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
    int arr[]={5,1,1,2,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n-1; i++)
    {
        int minIndex=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[minIndex]>arr[j])
            minIndex=j;
        }
        if(minIndex!=i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}