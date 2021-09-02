/*
Distinct Subsequences

Time-Limit: 2 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given a string, count the number of distinct subsequences of it (including empty subsequence).
A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.


Input Format

The first line of input contains T - the number of test cases.
The only line of each test case contains a string S.
It is guaranteed that all characters of S will be uppercase English alphabets.


Output Format

For each test case, print the number of distinct subsequences of S on a new line modulus 10^9+7.


Constraints

1 ≤ T ≤ 10
1 ≤ |S| ≤ 105
Sum of the length of all strings over all test cases ≤ 5 x 105 


Sample Input 1

4
AAA
ABBA
ABCDEFG
CODECRAFT

Sample Output 1

4
11
128
496

Note

Explanation 1:
Distinct subsequences: "", "A", "AA", "AAA".

Explanation 2:
Distinct subsequences: "", "A", "B", "AB", "AA", "ABB", "BB", "ABA", "BA", "BBA", "ABBA".

*/


/**
 * To understand the solution try writing combinations for ababa and check distinct subsequences
**/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
string s;
int dp[(int)(1e5+1)];
//int prevlen[26];
int flag[26];

void solve(){
	cin>>s;
	//memset(prevlen,0,sizeof(prevlen));
	memset(flag,0,sizeof(flag));
	int n = s.size();
	dp[0] = 1;
	for(int i=1;i<=n;i++)
	{
		/*//Diff style
		int x = s[i-1] - 'A';
		int cur = ((dp[i-1] - prevlen[x])+mod)%mod;
		dp[i] =(cur + dp[i-1])%mod;
		prevlen[x] = (prevlen[x] + cur)%mod;*/

		//or
		
		int pos = s[i-1] - 'A';
		int cur;
		if(flag[pos])
		 	cur = dp[i-1] - dp[flag[pos]-1];
		else
			cur = dp[i-1];
		cur = (cur + mod)%mod;
		dp[i] = (cur + dp[i-1])%mod;
		flag[pos] = i;
	}
	cout<<dp[n]<<endl;
	/*for(int i=0;i<=n;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;*/
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