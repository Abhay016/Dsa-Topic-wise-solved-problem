
/*   Sort An Array of 0s, 1s and 2s   */

/* Using Dutch National Flag algorithm or Three-way partitioning */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void sortArray(vector<int>& arr, int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr={2, 2, 2, 2, 0, 0, 1, 0};
    sortArray(arr, arr.size());
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}
