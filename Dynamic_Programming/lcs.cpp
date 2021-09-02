/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_f

Famous Question: Longest common subsequence
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

string s,t;

int dp[3001][3001];
int back[3001][3001];

int rec(int level1,int level2)
{
	if(level1==s.size() || level2==t.size())
	{
		return 0;
	}

	if(dp[level1][level2]!=-1)
		return dp[level1][level2];
	int ans =0 ;
	if(s[level1]==t[level2])
	{
		ans = 1 + rec(level1+1,level2+1);
		back[level1][level2] = 3;
	}
	else
	{
		int temp = ans = rec(level1,level2+1);
		ans = max(ans,rec(level1+1,level2));
		if(temp==ans)
		{
			back[level1][level2] = 2;
		}else{
			back[level1][level2] = 1;
		}
	}
	return dp[level1][level2] = ans;
}
void getanswer(int len)
{
	int p = 0;
	int i,j;
	i=j=0;
	while(p<len)
	{
		if(i==s.length() || j==t.length())
			break;
		switch(back[i][j])
		{
			case 1:
				i++;
				break;
			case 2:
				j++;
				break;
			case 3:
				cout<<s[i];
				i++;
				j++;
				p++;
				break;
		}

	}
	cout<<endl;

}

void solve(){
	cin>>s>>t;
	memset(dp,-1,sizeof(dp));
	memset(back,0,sizeof(back));
	cout<<rec(0,0)<<endl;
	/*for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<t.length();j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	getanswer(rec(0,0));
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