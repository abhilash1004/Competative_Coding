/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_d
*/

/*
Constraints:
1≤N≤2999
N is odd
pi is a real number and has two decimal places.
0≤pi≤1
*/

/*
Recursive solution
#include<bits/stdc++.h>
//#define int long long

using namespace std;

int n;
double prob[3000];
//double dp[3000][3000];
double ans = 0;

void rec(int level,int heads,double pans)
{
	if(level==n)
	{
		if(heads*2>n)
		{
			ans+=pans;
		}
		return;
	}
	rec(level+1,heads,pans*(1-prob[level]));
	rec(level+1,heads+1,pans*prob[level]);
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>prob[i];
	}
	rec(0,0,1);
	cout<<setprecision(20)<<ans<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	solve();
}*/

#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n;
float prob[3000];
double dp[3000][3000];

double rec(int level,int rheads)
{
	if(level==n)
	{
		if(rheads==0)
			return 1;
		return 0;
	}
	if(dp[level][rheads]!=-1)
		return dp[level][rheads];
	double ans = rec(level+1,rheads-1) * prob[level] + rec(level+1,rheads) * (1-prob[level]);
	return dp[level][rheads] = ans;
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>prob[i];
	}
	for(int i=0;i<3000;i++)
	{
		for(int j=0;j<3000;j++)
		{
			dp[i][j] = -1;
		}
	}
	long double ans = 0;
	for(int i=((n/2)+1);i<=n;i++)
	{
		ans+=rec(0,i);
	}
	cout<<fixed<<setprecision(15)<<ans<<endl;
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