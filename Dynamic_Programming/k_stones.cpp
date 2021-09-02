/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_k
*/

#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n,k;
int a[101];
int dp[1000001];

int rec(int level)
{
	if(level<=0)
	{
		return 0;
	}
	if(dp[level]!=-1)
		return dp[level];
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=level)
		{
			if(!rec(level-a[i]))
			{
				ans = 1;
				break;
			}
		}
	}
	return dp[level] = ans;
}

void solve(){
	cin>>n>>k;
	//cout<<"Hi";
	for(int i=0;i<n;i++)
		cin>>a[i];
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	//cout<<"HI";
	/*for(int i=0;i<n;i++)
	{
		dp[a[i]]=1;
	}*/
	//cout<<rec(k)<<endl;
	/*for(int i=0;i<=k;i++)
		cout<<dp[i]<<" ";*/
	if(rec(k))
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;
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