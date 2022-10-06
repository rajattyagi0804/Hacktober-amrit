#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> arr, int size)
{
    int curSum=INT_MIN;
    int maxSum=INT_MIN;

    for (int i = 0; i < size; i++) {
        curSum = curSum + arr[i];
        if (maxSum < curSum)
            maxSum = curSum;

        if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    int max_sum = maxSubArraySum(arr, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
