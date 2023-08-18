
/*   Sort By set Bit count   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int setBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1)
        {
            count++;
        }
        a = a >> 1;
    }
    return count;
}

bool comparator(int a, int b)
{
    int count1 = setBits(a), count2 = setBits(b);
    if (count1 == count2)
    {
        return a <= b;
    }
    return count1 < count2;
}

vector<int> sortByBits(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), comparator);
    return arr;
}

int main()
{
    vector<int> arr={1,2,3,4,5,6};
    vector<int> ans=sortByBits(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}