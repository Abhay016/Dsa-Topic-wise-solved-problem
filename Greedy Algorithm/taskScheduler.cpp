
#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < tasks.size(); i++)
    {
        freq[tasks[i] - 'A']++;
    }
    sort(freq.begin(), freq.end(), greater<int>());
    int maxVal = freq[0] - 1;
    int idle = maxVal * n;
    for (int i = 1; i < 26; i++)
    {
        idle -= min(freq[i], maxVal);
    }
    if (idle <= 0)
        return tasks.size();
    else
        return tasks.size() + idle;
}