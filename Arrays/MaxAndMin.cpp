
/*   Maximum and minimum of an array using minimum number of comparisons   */

#include <bits/stdc++.h>
#define MOD 1000000007 
using namespace std;

int main()
{
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int max_val=INT_MIN;
    int min_val=INT_MAX;
    for (int i = 0; i < size; i++)
    {
        max_val=max(max_val, arr[i]);
        min_val=min(min_val, arr[i]);
    }
    cout<<max_val<<" "<<min_val<<endl;
}