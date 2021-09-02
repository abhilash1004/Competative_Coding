/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_b
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[100010];
int a[100010];
int n,k;

int rec(int level)
{
	if(level>=n)
	{
		return 1e9;
	}
	if(dp[level]!=-1)
	{
		return dp[level];
	}
	int ans = 1e9;
	for(int i=1;i<=k;i++)
	{
		ans = min(ans,abs(a[level]-a[level+i])+rec(level+i));
	}
	return dp[level] = ans;
}

void solve(){
	//memset(a,0,sizeof(a));
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	dp[n-1] = 0;
	//cout<<"Helo\n";
	cout<<rec(0)<<endl;
	/*for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<"-"<<a[i]<<"\n";
	}
	cout<<"Helo2\n";*/
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