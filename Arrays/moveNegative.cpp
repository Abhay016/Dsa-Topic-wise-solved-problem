
/*   Move all negative numbers to beginning and positive to end with constant extra space   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void separateNegativeAndPositive(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        if (arr[j] >= 0)
        {
            j--;
        }
        else if (arr[i] < 0)
        {
            i++;
        }
        else if (arr[i] >= 0 && arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    vector<int> arr={-12, 11, -13, -5, 6, -7, 5, -3, -6};
    separateNegativeAndPositive(arr);
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}