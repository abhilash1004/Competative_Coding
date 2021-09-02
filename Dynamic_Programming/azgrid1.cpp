/*
Number of Paths in Grid - 1

Time-Limit: 1 sec Score: 100 
Memory: 256 MB 
Relevant For:
Description

Given a grid of size n*m, you need to find the number of paths from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1). The grid may have some blocked cells, represented by 1, and it is not allowed to move to a blocked cell. An empty cell is represented by 0.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the following n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the number of paths modulo 109 + 7.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 106.


Sample Input 1

3
2 3
0 1 0
0 0 0
3 3
0 0 1
0 0 0
0 0 0
2 2
1 0
0 0

Sample Output 1

1
5
0

Note

For the first test case, there is only one path, (1, 1) → (2, 1) → (2, 2) → (2, 3).

For the third test case, no path can reach (2, 2) since the starting point is blocked.
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
    if(grid[0][0] || grid[m-1][n-1])
        return 0;
    //cout<<"Hi";
    if(grid[r][c])
        return 0;
    if(dp[r][c]!=-1)
        return dp[r][c];
    int ans = ((rec(r+1,c)%mod) + (rec(r,c+1))%mod)%mod;
    return dp[r][c] = ans;
}

void solve(){
    cin>>m>>n;
    //char ch;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
            /*switch(ch)
            {
            case '#':
                grid[i][j] = 1;
                break;
            case '.':
            default:
                grid[i][j] = 0;
            }*/
            //For iterative
            dp[i][j] = 0;
        }
    }
    
    //memset(dp,-1,sizeof(dp));
    //cout<<rec(0,0)<<endl;
    /*for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }*/

    //iterative solution:
    //memset(dp,0,sizeof(dp));
    if(grid[0][0] || grid[m-1][n-1])
    {
        cout<<0<<endl;
        return;
    }
    dp[0][0] = 1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            if(grid[i][j])
                continue;
            if(i)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                
            }
            if(j)
            {
                dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
                
            }

        }
    }
    cout<<dp[m-1][n-1]<<endl;
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
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}