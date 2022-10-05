#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& nums,int x){
    int lo = 0;
    int hi = nums.size()-1;
    int m;

    while(lo<=hi){
        m = lo + (hi-lo)/2;

        if(nums[m] == x){
            return m;
        }
        else if (nums[m]<x){
            lo = m+1;
        }
        else{
            hi = m-1;
        }

    }
    return -1;
}

int main(){
    cout << "Enter array size:"<<endl;

    int n;
    cin >> n;

    cout << "Enter sorted integer array:"<<endl;

    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin >> nums[i]; 
    }

    int x;
    cout << "Enter element to search in array:"<<endl;
    cin >> x;

    int pos = binary_search(nums,x);

    if (pos==-1){
        cout << "Not found"<<endl;
    }
    else{
    cout << "Found at position "<<pos+1<<endl;
    }

    return 0;
}