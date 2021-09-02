/*
Maximum path sum in grid

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m with non-negative integers, you need to find the maximum path sum from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1).


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the following n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the maximum path sum.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 107

It is guaranteed that the sum of n*m over all test cases does not exceed 106.


Sample Input 1

3
2 3
3 2 1
4 1 1
3 3
1 2 1
3 5 1
4 1 1
2 2
1 2
3 4

Sample Output 1

9
11
8

Note

For the first test case, path 3 → 4 → 1 → 1 maximises the sum.

For the second test case, path 1 → 2 → 5 → 1 → 1 and 1 → 3 → 4 → 1 → 1 maximises the sum.

For the third test case, path 1 → 3 → 4 maximises the sum.


1

*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int grid[1005][1005];
int dp[1005][1005];

void solve(){
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
			dp[i][j] = 0;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i && j)
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];
			}
			else if(i)
			{
				dp[i][j] = dp[i-1][j] + grid[i][j];
			}
			else{
				dp[i][j] = dp[i][j-1] + grid[i][j];
			}
		}
	}
	cout<<dp[m-1][n-1]<<endl;
	
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}