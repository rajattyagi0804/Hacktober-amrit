// Problem statement: find length of the longest common substring 
#include <iostream>
#include <string.h>
using namespace std;

void LongestCommonSubstring(char* str1, char* str2, int m, int n)
{
	

	int dp[m + 1][n + 1];
	int result = 0; 

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{

			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				result = max(result, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
    cout << "result: " << result << endl;
}

int main()
{
	char str1[] = "OldSite:GeeksforGeeks.org";
	char str2[] = "NewSite:GeeksQuiz.com";

	int m = strlen(str1);
	int n = strlen(str2);

    LongestCommonSubstring(str1, str2, m, n);
	return 0;
}
