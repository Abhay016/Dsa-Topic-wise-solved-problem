
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

class StockSpanner
{
    public:
    stack<pair<int, int>> s;
    StockSpanner()
    {
    }

    int next(int price)
    {
        if (s.empty())
        {
            s.push({1, price});
            return 1;
        }
        int res = 1;
        while (!s.empty() && s.top().second <= price)
        {
            res += s.top().first;
            s.pop();
        }
        s.push({res, price});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */