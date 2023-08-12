#include <bits/stdc++.h> 
using namespace std;

void func(int source, int auxiliary, int destination, int n, vector<int> temp, vector<vector<int>> &res)
{
    if(n==1)
    {
        temp.push_back(source);
        temp.push_back(destination);
        res.push_back(temp);
        return;
    }
    func(source, destination, auxiliary, n-1, temp, res);
    temp.push_back(source);
    temp.push_back(destination);
    res.push_back(temp);
    temp.pop_back();
    temp.pop_back();
    func(auxiliary, source, destination, n-1, temp, res);

}
vector<vector<int>> towerOfHanoi(int n)
{
    //    Write your code here.
    int source=1;
    int auxiliary=2;
    int destination=3;
    vector<int> temp;
    vector<vector<int>> res;
    func(source, auxiliary, destination, n, temp, res);
    return res;
}
int main()
{
    int n=3;
    vector<vector<int>> ans=towerOfHanoi(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}