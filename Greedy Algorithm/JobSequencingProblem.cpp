
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[2]>b[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comp);
    int n=jobs.size();
    int maxDead=INT_MIN;
    for(int i=0; i<n; i++)
    {
        maxDead=max(maxDead, jobs[i][1]);
    }
    vector<int> vec(maxDead, -1);
    int maxProfit=0, count=0;
    for(int i=0; i<n; i++)
    {
        int currDead=jobs[i][1];
        for(int j=currDead-1; j>=0; j--)
        {
            if(vec[j]==-1)
            {
                count++;
                maxProfit+=jobs[i][2];
                vec[j]=jobs[i][0];
                break;
            }
        }
    }
    return {count, maxProfit};
}