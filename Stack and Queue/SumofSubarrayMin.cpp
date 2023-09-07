
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void prevSmaller(vector<int> arr, vector<int> &res, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(i);
            res.push_back(-1);
        }
        else
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
                res.push_back(-1);
            else
                res.push_back(s.top());
            s.push(i);
        }
    }
}
void nextSmaller(vector<int> arr, vector<int> &res, int n)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            s.push(i);
            res[i] = n;
        }
        else
        {
            while (!s.empty() && arr[s.top()] > arr[i])
            {
                s.pop();
            }
            if (s.empty())
                res[i] = n;
            else
                res[i] = s.top();
            s.push(i);
        }
    }
}
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prev;
    prevSmaller(arr, prev, n);
    vector<int> next(n);
    nextSmaller(arr, next, n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = ((i - prev[i]) * (next[i] - i)) % MOD;
        sum = (sum + (1LL * arr[i] * temp) % MOD) % MOD;
    }
    return sum;
}

int main()
{
    vector<int> arr = {11, 81, 94, 43, 3};
    cout << sumSubarrayMins(arr);
}