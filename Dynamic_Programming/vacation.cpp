/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_c
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

int a[100010][3];
int dp[100010][3];
int n;

int rec(int level,int prev)
{
	if(level == n)
	{
		return 0;
	}
	if(dp[level][prev]!=-1)
		return dp[level][prev];
	int ans = 0;
	for(int i=0;i<3;i++)
	{
		if(i!=prev)
		{
			ans = max(ans,rec(level+1,i) + a[level][i]);
		}
	}
	return dp[level][prev] = ans;
}


void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	int ans=0;
	for(int i=0;i<3;i++)
	{ 
		ans = max(ans,rec(1,i) + a[0][i]);
	}
	cout<<ans<<endl;
	/*
	//Iterative Solution
	memset(dp,0,sizeof(dp));
	for(int i=0;i<3;i++)
	{
		dp[n-1][i] = a[n-1][i];
	}
	for(int i=n-2;i>=0;i--)
	{
		dp[i][0] = max(dp[i+1][1] , dp[i+1][2]) + a[i][0];
		dp[i][1] = max(dp[i+1][0] , dp[i+1][2]) + a[i][1];
		dp[i][2] = max(dp[i+1][0] , dp[i+1][1]) + a[i][2];
	}
	int ans = dp[0][0];
	for(int i=1;i<3;i++)
	{
		ans = max(ans,dp[0][i]);
	}
	cout<<ans<<endl;*/

	/*
	//Debugging dp 
	for(int j=0;j<3;j++)
	{
		for(int i=1;i<n;i++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	/*int t;
	cin>>t;
	while(t--)*/{
		solve();
	}
}