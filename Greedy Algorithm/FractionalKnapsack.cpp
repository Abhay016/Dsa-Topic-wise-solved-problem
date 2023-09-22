
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};


class Solution
{
public:
    static bool comp(Item a, Item b)
    {
        return ((float)a.value / a.weight) > ((float)b.value / b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        double res = 0;
        for (int i = 0; i < n; i++)
        {
            if (W > arr[i].weight)
            {
                res += arr[i].value;
                W -= arr[i].weight;
            }
            else if (arr[i].weight >= W)
            {
                res += (double(arr[i].value) / arr[i].weight) * W;
                break;
            }
        }
        return res;
    }
};