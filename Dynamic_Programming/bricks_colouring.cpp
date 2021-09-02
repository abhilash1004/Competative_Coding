/*
Bricks Colouring

Time-Limit: 5 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given N bricks in a line and M different coloured buckets of paint. You have to find the number of ways you can colour the brick wall such that there are exactly K positions out of the N bricks such that it has a different colour from the brick wall on its immediate left. (except the first brick, since there is no left brick). Print it modulo 10^9+7.

 

 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first and only line of each test case contains three space-separated integers N, M, K.

 


Output Format

For each test case, print the number of ways you can colour the brick wall satisfying the given condition % 10^9+7.


Constraints

1≤ T ≤ 100

1≤ N, M ≤ 2000

0≤ K ≤ N-1

It is guaranteed that the sum of N*K over all test cases does not exceed 4*108.


Sample Input 1

3
3 2 2
2 2 1
3 5 0

Sample Output 1

2
2
5

Note

For the first test case, the following are the 2 different arrangements possible:



For the second test case, the following are the 2 different arrangements possible:



For the third test case, the following are the 5 different arrangements possible:






*/
/*#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,m,k;
int dp[2001][2001];

int rec(int level,int remaining)
{
	if(level==n)
	{
		if(remaining == 0)
		{
			return 1;
		}
		else return 0;
	}
	if(dp[level][remaining]!=-1)
		return dp[level][remaining];
	int ans = ((m-1) * rec(level+1,remaining-1))%mod + rec(level+1,remaining)%mod;
	return dp[level][remaining] = (ans%mod);
}

void solve(){
	cin>>n>>m>>k;
	memset(dp,-1,sizeof(dp));
	cout<<(m*(rec(1,k))%mod)<<endl;
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
}*/


//Iterative solution
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int mod=1000000007;
int dp[2001][2001];

signed main() {
    IOS
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=k;j++)
                dp[i][j] = 0;
        dp[1][0] = m;
        for (int i = 2; i <= n; ++i) {
            for (int j =0; j <= k; ++j) {
                dp[i][j] = dp[i-1][j];
                if(j)
                    dp[i][j] = (dp[i][j] + (dp[i-1][j-1]*(m-1))%mod)%mod;
            }
        }
        cout << dp[n][k] << "\n";
        for(int i=0;i<=n;i++)
        {
        	for(int j=0;j<=k;j++)
        	{
        		cout<<dp[i][j]<<" ";
        	}
        	cout<<endl;
        }
    }
    return 0;
}