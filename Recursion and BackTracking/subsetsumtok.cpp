
#include <bits/stdc++.h> 
using namespace std;

void subsequence(int input[], int i, vector<int> temp, int k, int sum, int size)
{
    if(i==size)
    {
        if(sum==k)
        {
            for(int i=0; i<temp.size(); i++)
            {
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    subsequence(input, i+1, temp, k, sum, size);
    temp.push_back(input[i]);
    subsequence(input, i+1, temp, k, sum+input[i], size);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> temp;
    subsequence(input, 0, temp, k, 0, size);
}

int main()
{
    int input[]={5,12,3,17,1,18,15,3,17};
    printSubsetSumToK(input, 9, 6);
}