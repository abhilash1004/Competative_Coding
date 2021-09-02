/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[100010];
int a[100010];
int n;

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
	int ans1= abs(a[level]-a[level+1])+rec(level+1);
	int ans2 = abs(a[level]-a[level+2])+rec(level+2);
	return dp[level] = min(ans1,ans2);
}

void solve(){
	//memset(a,0,sizeof(a));
	cin>>n;
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