/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_l
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int m,n;
int grid[1001][1001];
int dp[1001][1001];
int mod = 1e9 + 7;

int rec(int r,int c)
{
	if(r==m-1 && c==n-1)
	{
		dp[r][c] = 1;
		return 1;
	}
	if(r>=m || c>=n)
	{
		return 0;
	}
	//cout<<"Hi";
	if(!grid[r][c])
		return 0;
	if(dp[r][c]!=-1)
		return dp[r][c];
	int ans = ((rec(r+1,c)%mod) + (rec(r,c+1))%mod)%mod;
	return dp[r][c] = ans;
}

void solve(){
	cin>>m>>n;
	char ch;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>ch;
			switch(ch)
			{
			case '#':
				grid[i][j] = 0;
				break;
			case '.':
			default:
				grid[i][j] = 1;
			}
		}
	}
	
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)<<endl;
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<"\t";
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