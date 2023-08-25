
#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int start = 0;
    long long int balance = 0;
    long long int left = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance + gas[i] - cost[i];
        if (balance < 0)
        {
            start = i + 1;
            left += balance;
            balance = 0;
        }
    }
    if ((left + balance) >= 0)
        return start;
    else
        return -1;
}

int main()
{
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};
    cout<<canCompleteCircuit(gas, cost);
}