#include<bits/stdc++.h>
using namespace std;
int solutions=0;
void printsol(vector<int> ans,int d)
{
int i;
cout<<"Subset "<<solutions+1<<": [";
for(i=0;i<ans.size()-1;i++)
{
cout<<ans[i]<<",";
}
cout<<ans[i];
cout<<"] ---> (";
for(i=0;i<ans.size()-1;i++)
{
cout<<ans[i]<<" + ";
}
cout<<ans[i]<<" = "<<d<<")\n\n";
}
int subsum(int arr[],int d,int sum,int index,int n,vector<int> ans) {
int i,curr_sum=0;
if(sum==d)
{
printsol(ans,d);
solutions++;
}
else{
for(i=index;i<n;i++)
{
curr_sum=sum+arr[i];

if(curr_sum>d)
{
return 0;
}
ans.push_back(arr[i]);
if(subsum(arr,d,curr_sum,i+1,n,ans))
{
return 1;
}
else{
ans.pop_back();
}
}
}
return 0;
}
int main()
{
int i, n, j, total = 0, d;
cout<<"**SUBSET SUM PROBLEM**\n";
cout<<"\nEnter the size of array: ";
cin >> n;
cout<<"\nEnter "<<n<<" elements: ";
int arr[n];
for (i = 0; i < n; i++)
{
cin >> arr[i];
}
cout<<"\nEnter the sum of subset to be found: ";
cin>>d;
vector<int> ans;

sort(arr, arr + n);
cout<<"\nAll possible solutions are:\n\n";
subsum(arr, d, 0, 0, n, ans);
if (solutions == 0)
{
cout << "\n<----No feasible changes there-----\n";
}
else
cout << "\nThe total number of solutions possible are: " << solutions << endl;
  cout<<"Time complexity is n^n";
return 0;
}
