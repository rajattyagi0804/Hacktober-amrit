//Problem statement: Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1, 
//compute how much water it is able to trap after raining.

#include <bits/stdc++.h>
using namespace std;
 
int maxWater(int arr[], int n)
{
    int res = 0;
 
    for (int i = 1; i < n - 1; i++) {
 
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);
 
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);
 
        res = res + (min(left, right) - arr[i]);
    }
 
    return res;
}
 
int main()
{
    int arr[] = { 3, 0, 2, 0, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << maxWater(arr, n);
 
    return 0;
}
