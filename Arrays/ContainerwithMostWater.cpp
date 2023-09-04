
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &arr)
{
    int res = 0;
    int s = 0, e = arr.size() - 1;
    while (s < e)
    {
        res = max(res, (e - s) * min(arr[s], arr[e]));
        if (arr[s] > arr[e])
            e--;
        else
            s++;
    }
    return res;
}