
#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);
    int s = 0, e = N - 1;
    int minVal = 0, maxVal = 0;
    while (s <= e)
    {
        minVal += candies[s];
        e -= K;
        s++;
    }
    s = 0, e = N - 1;
    while (s <= e)
    {
        maxVal += candies[e];
        s += K;
        e--;
    }
    return {minVal, maxVal};
}