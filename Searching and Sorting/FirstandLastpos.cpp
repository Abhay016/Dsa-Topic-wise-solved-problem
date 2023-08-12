 
/*   First and last occurrences of x   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int firstocc(int arr[],int size , int key){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int lastocc(int arr[],int size , int key){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int odd[]={1, 3, 5, 5, 5, 5, 67, 123, 125};
    cout<<"First occurence is "<<firstocc(odd,9,5)<<endl;
    cout<<"Last occurence is "<<lastocc(odd,9,5)<<endl;
}