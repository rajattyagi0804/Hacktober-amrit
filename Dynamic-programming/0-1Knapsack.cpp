// Problem statement: Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
//In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
//Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
 using namespace std;

 void Knapsack01(int W, int wt[],int val[], int n)
 {
     int dp[n+1][W+1];
     for(int i=0;i<=n;i++)
     {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(wt[i-1]<=j)
            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];

        }
     }
     cout<<dp[n][W]<<"\n";
 }

 int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
     
    Knapsack01(W, wt, val, n);
     
    return 0;
}