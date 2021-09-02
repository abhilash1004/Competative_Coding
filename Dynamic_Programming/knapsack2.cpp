/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_d
*/

/*
Constraints:
All values in input are integers.
1≤N≤100
1≤W≤10^9
1≤wi≤W
1≤vi≤10^3
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n,w;
int weights[100];
int profits[100];
long long dp[101][100010];

long long rec(int level,int rval)
{
	if(level == n)
	{
		if(rval==0)
			return 0;
		return 1e12;
	}
	if(dp[level][rval]!=-1)
		return dp[level][rval];
	long long ans = rec(level+1,rval);
	ans = min(ans,weights[level]+rec(level+1,rval-profits[level]));
	return dp[level][rval] = ans;
}

void solve(){
	cin>>n>>w;
	//cout<<"Hello";
	int tprofit = 0;
	for(int i=0;i<n;i++)
	{
		cin>>weights[i]>>profits[i];
		tprofit+=profits[i];
	}

	memset(dp,-1,sizeof(dp));
	//cout<<rec(0,0)<<endl;
	//rec(0,tprofit);
	int ans = 0;
	for(int i=0;i<=tprofit;i++)
	{

		if(rec(0,i)<=w)
			ans = i;
		/*if(rec(0,i)<1e10)
		cout<<rec(0,i)<<" "<<i<<endl;
		else cout<<-1<<" "<<i<<endl;*/
	}
	cout<<ans<<endl;
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