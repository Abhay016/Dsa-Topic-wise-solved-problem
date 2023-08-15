
/*   Merge Intervals   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        int x1=intervals[0][0], x2=intervals[0][1];
        int y1, y2;
        for(int i=1; i<n; i++)
        {
            y1=intervals[i][0], y2=intervals[i][1];
            if(x2<y1)
            {
                ans.push_back({x1,x2});
                x1=y1;
                x2=y2;
            }
            else if(x2==y1)
            {
                x2=y2;
            }
            else if(x2>y1 && x1<=y1)
            {
                x2=max(x2,y2);
            }
        }
        ans.push_back({x1,x2});
        return ans;
    }
    
    int main()
    {
        vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
        vector<vector<int>> ans=merge(intervals);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }