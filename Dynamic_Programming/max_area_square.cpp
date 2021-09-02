/*
Maximum Area of Square

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a grid of size n*m with 0s and 1s, you need to find the area of the largest square containing only 1.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the next n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the maximum area.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 107.


Sample Input 1

3
2 3
0 1 1
0 0 0
3 3
1 0 1
0 1 1
0 1 1
2 2
0 0
0 0

Sample Output 1

1
4
0

*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

bool arr[1001][1001];
int dp[1001][1001];
int m,n;

int rec(int r,int c)
{
	if(r==0 && c==0)
	{
		return dp[r][c] = arr[r][c];
	}
	if(r<0 || c<0)
	{
		return 0;
	}
	if(dp[r][c]!=-1)
	{
		return dp[r][c];
	}
	
	int ans = min({rec(r-1,c)+1,rec(r,c-1)+1,rec(r-1,c-1)+1});

	if(arr[r][c] == 0)
		return dp[r][c] = 0;
	return dp[r][c] = ans;
}

void solve(){
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j] = -1;
			cin>>arr[i][j];
		}
	}
	rec(m-1,n-1);
	int ans = 0;
	for(int i = 0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans*ans<<endl;
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