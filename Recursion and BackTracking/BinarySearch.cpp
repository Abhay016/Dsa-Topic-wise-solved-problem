
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> vec, int key, int s, int e)
{
    if (s > e)
    {
        return -1;
    }
    int mid = (s + (e - s) / 2);
    if (vec[mid] == key)
    {
        return mid;
    }
    else if (vec[mid] > key)
    {
        return solve(vec, key, s, mid - 1);
    }
    else
    {
        return solve(vec, key, s + 1, e);
    }
}
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 9;
    cout << solve(vec, key, 0, vec.size() - 1);
}