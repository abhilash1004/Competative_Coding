/*
Hard Problem

Time-Limit: 6 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given a string S with length N. Each character is assigned a cost for removing it. Find the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains a string S.

The third line of each test case contains N space-separated integers - the cost of removing a character.


Output Format

For each test case, print the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.


Constraints

1≤ T ≤ 1000

1≤ N ≤ 10^5

1≤ Ai ≤ 10^9


Sample Input 1

3
5
hardd
3 5 1 6 10
7
hharred
1 1 7 10 3 6 8
5
abcde
1 2 3 4 5
 


Sample Output 1

1
2
0

Note

For the first test case, you need to remove the character ‘a’ (cost - 1).

For the second test case, you need to remove the character ‘h’ (cost - 1+1 = 2)

For the third test case, there is no need to remove any character.
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
int n;
//const char hard[] = "hard";
int dp[4];
int cost[100005];

void solve(){
	cin>>n;
	cin>>s;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		cin>>cost[i];
	for(int i=0;i<n;i++)
	{
		if(s[i]=='h') dp[0]+=cost[i];
		if(s[i]=='a') dp[1]=(min(dp[0] , dp[1] + cost[i]));
		if(s[i]=='r') dp[2]=(min(dp[1] , dp[2] + cost[i]));
		if(s[i]=='d') dp[3]=min(dp[2],dp[3] + cost[i]);
	}
	cout<<dp[3]<<"\n";

}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

/*
//Recursive solution:
#include<bits/stdc++.h>

using namespace std;

int n,k;
long long ans,fa;
string s;
//ofstream ofm;

long long rec(int i,char c,vector<int> &v,vector<vector<long long>> &dp){
	if(i==n)
		return 0;
	if(dp[i][c]!=-1)
		return dp[i][c];
	if(c==0 && s[i]=='h'){
        return dp[i][c]=min(rec(i+1,c+1,v,dp),v[i]+rec(i+1,c,v,dp));
    }else if(c==1 && s[i]=='a'){
        return dp[i][c]=min(rec(i+1,c+1,v,dp),v[i]+rec(i+1,c,v,dp));
    }else if(c==2 && s[i]=='r'){
        return dp[i][c]=min(rec(i+1,c+1,v,dp),v[i]+rec(i+1,c,v,dp));
    }else if(c==3 && s[i]=='d'){
        return dp[i][c]=rec(i+1,c,v,dp)+v[i];
    }else
        return dp[i][c]=rec(i+1,c,v,dp);
}

void solve(){
	cin>>n;
	cin>>s;
	vector<int> v(n);
	vector<vector<long long>> dp(n,vector<long long>(4,-1));
	for(k=0;k<n;k++)
		cin>>v[k];
	cout<<rec(0,0,v,dp)<<"\n";
	//ofm<<rec(0,0,v,dp)<<"\n";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	//ofm.open("ans.txt");
	while(t--)
		solve();
	//ofm.close();
}
*/