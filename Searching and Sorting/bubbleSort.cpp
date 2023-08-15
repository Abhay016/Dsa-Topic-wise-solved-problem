
/*    Bubble sort   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
    int arr[]={5,1,1,2,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=n-1;
    while(i>0)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
        i--;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}