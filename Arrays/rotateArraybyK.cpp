
/*   Rotate Array by k   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(arr, k);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}