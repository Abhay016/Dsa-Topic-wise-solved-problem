
/*   Magnetic force between two balls*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool func(vector<int> position, int m, int mid)
{
    int count = 1;
    int pos = position[0];
    for (int i = 0; i < position.size(); i++)
    {
        if ((position[i] - pos) >= mid)
        {
            count++;
            if (count == m)
                return true;
            pos = position[i];
        }
    }
    return false;
}
int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end());
    int n = position.size();
    int i = 1;
    int j = position[n - 1] - position[0];
    int ans = -1;
    while (i <= j)
    {
        int mid = (i + (j - i) / 2);
        if (func(position, m, mid))
        {
            ans = mid;
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3,4,7};
    int m = 3;
    cout << maxDistance(arr, m);
}