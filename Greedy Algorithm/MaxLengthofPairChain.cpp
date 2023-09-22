
#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), comp);
    int count = 1;
    int val = pairs[0][1];
    for (int i = 1; i < pairs.size(); i++)
    {
        if (pairs[i][0] > val)
        {
            count++;
            val = pairs[i][1];
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << findLongestChain(pairs);
}