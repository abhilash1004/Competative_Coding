/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_d
*/

/*
Constraints:
All values in input are integers.
1≤N≤100
1≤W≤10^5
1≤wi≤W
1≤vi≤10^9
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n,w;
int weights[100];
int profits[100];
long long dp[101][100010];

long long rec(int level,int pweight)
{
	if(level==n)
	{
		if(pweight<=w)
		{
			return 0;
		}
		return -1e9;
	}
	if(dp[level][pweight]!=-1)
	{
		return dp[level][pweight];
	}
	//cout<<level<<" "<<pweight<<" "<<rec(level+1,pweight)<<" "<<(profits[level]*1ll + rec(level+1,pweight+weights[level]))<<endl;
	return dp[level][pweight] = max(rec(level+1,pweight),profits[level]*1ll + rec(level+1,pweight+weights[level]));
}

void solve(){
	cin>>n>>w;
	//cout<<"Hello";
	for(int i=0;i<n;i++)
	{
		cin>>weights[i]>>profits[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)<<endl;
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