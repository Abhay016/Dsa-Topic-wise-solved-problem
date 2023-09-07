
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    priority_queue<int> pq;
    int i;
    for (i = 0; i < heights.size() - 1; i++)
    {
        if (heights[i + 1] - heights[i] <= 0)
        {
            continue;
        }
        int d = heights[i + 1] - heights[i];
        if (bricks >= d)
        {
            bricks -= d;
            pq.push(d);
        }
        else if (ladders > 0)
        {
            if (!pq.empty())
            {
                int temp = pq.top();
                if (temp > d)
                {
                    bricks += temp;
                    pq.pop();
                    pq.push(d);
                    bricks -= d;
                }
            }
            ladders--;
        }
        else
        {
            break;
        }
    }
    return i;
}

int main()
{
    vector<int> heights={4,12,2,7,3,18,20,3,19};
    int bricks=10, ladders=2;
    cout<<furthestBuilding(heights, bricks, ladders);
}