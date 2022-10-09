//Problem statement: Given an array that contains both positive and negative integers, find the product of the maximum product subarray. 
//Expected Time complexity is O(n) and only O(1) extra space can be used.


#include <bits/stdc++.h>
using namespace std;

int maxSubarrayProduct(int arr[], int n)
{
    int max_end = arr[0];
    int min_end = arr[0];
  
    int max_so_far = arr[0];
    for (int i = 1; i < n; i++) {
        int temp = max({ arr[i], arr[i] * max_end, arr[i] * min_end });
        min_end = min({ arr[i], arr[i] * max_end, arr[i] * min_end });
        max_end = temp;
        max_so_far = max(max_so_far, max_end);
    }
    return max_so_far;
}
  
int main()
{
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is " << maxSubarrayProduct(arr, n);
    return 0;
}
