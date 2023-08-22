
#include <bits/stdc++.h> 
using namespace std;

void factors(int n, vector<int> temp, vector<vector<int>>& res, vector<int> fac, int i)
{
	if(i==fac.size())
	{
		return;
	}
	if(n==1)
	{
		res.push_back(temp);
		return;
	}
	if((n%fac[i])==0)
	{
		temp.push_back(fac[i]);
		factors(n/fac[i], temp, res, fac, i);
		temp.pop_back();
	}
	factors(n, temp, res, fac, i+1);
}

vector<vector<int>> factorCombinations(int n) 
{
	vector<vector<int>> res;
	vector<int> temp;
	vector<int> fac;
	for(int i=2; i<=n/2; i++)
	{
		if(n%i==0)
		fac.push_back(i);
	}
	factors(n, temp, res, fac, 0);
	return res;
}

int main()
{
    vector<vector<int>> res=factorCombinations(16);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
}