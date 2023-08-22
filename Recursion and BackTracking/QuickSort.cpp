
#include <bits/stdc++.h> 
using namespace std;

int partition(vector<int>& arr, int s, int e)
{
    int temp=arr[s];
    int count=0;
    for(int i=s+1; i<=e; i++)
    {
        if(temp>=arr[i])
        {
            count++;
        }
    }
    int pivotIndex=s+count;
    swap(arr[s], arr[pivotIndex]);
    int i=s, j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<temp)
        {
            i++;
        }
        while(arr[j]>temp)
        {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
}

void sort(vector<int>& arr, int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int i=partition(arr, s, e);
    sort(arr, s, i-1);
    sort(arr, i+1, e);
}

void quickSort(vector<int>& arr)
{
    sort(arr, 0, arr.size()-1);
}

int main()
{
    vector<int> arr = {3, 5, 6, 2, 1, 5, 7, 3, 6, 8, 9};
    quickSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }   
}