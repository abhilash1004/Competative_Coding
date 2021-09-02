/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_l
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n;
vector<int> v(3001,-1);
long long dp[3010][3010];
bool flag[3010][3010];

long long rec(int l,int r)
{
	if(l>r)
		return 0;
	if(flag[l][r])
		return dp[l][r];
	//int ans = -1e18;
	long long ans = v[l] - rec(l+1,r);
	ans = max(ans,v[r] - rec(l,r-1));
	flag[l][r] = 1;
	return dp[l][r] = ans;
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	memset(dp,-1,sizeof(dp));
	memset(flag,0,sizeof(flag));
	cout<<rec(0,n-1);

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