
/*   Insertion Sort   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
    int arr[]={5,1,1,2,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1; i<n; i++)
    {
        if(arr[i]<arr[i-1])
        {
            int temp=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>temp)
            {
                arr[j+1]=arr[j];
                j--;
                
            }
            arr[j+1]=temp;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}