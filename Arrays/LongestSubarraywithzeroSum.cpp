
/*   Longest Subarray With Zero Sum   */

#include <bits/stdc++.h>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	int maxLen=0;
	int sum=0;
	unordered_map<long long, int> mp;
	for(int i=0; i<arr.size(); i++)
	{
		sum+=arr[i];
		if(mp.count(sum))
		{
			maxLen=max(maxLen, i-mp[sum]);
		}
		if(mp.count(sum)==0)
		{
			mp[sum]=i;
		}
	}
	return maxLen;
}