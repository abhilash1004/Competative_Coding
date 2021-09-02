/*
Tiling

Time-Limit: 5 sec Score: 100
Difficulty : 5 Star
 Memory: 256 MB Accepted Submissions: 100
Description

Find the number of ways to Tile NxM rectangle with dominoes. 
A domino is 2 * 1 or 1 * 2 rectangle.


Input Format

The first line contains an integer T (1 ≤ T ≤ 100) - the number 
of testcases.

The first line of each test case contains two space-separated 
integers N, M. 1 ≤ N, M ≤ 12.


Sample Input 1

7
10 3
10 5
2 3
10 1
2 4
5 4
9 11

Sample Output 1

571
185921
3
1
5
95
0

*/

/*
Hint:
If the number of columns and number of rows is odd, 
the answer would be 0 since each domino occupies an area of 2. 
You can consider each column as a binary number which gives 
the information whether the i-th bit in that column is filled 
with a domino or not.

Solution Approach:
We make the DP array as DP[pos][vis] (1-based indexing for pos) 
which denotes the number of ways to fill the grid where pos is 
the current row and vis denotes the blocks filled in the current row. 
All the blocks before the pos row must be completely filled. 
One way to make the transition would be to find DP[pos][vis] 
from DP[pos-1][n_vis] by using the different possible values of 
n_vis for which there exists a filling of pos-th row with the same 
set of filled blocks. But you will get TLE in this since the 
time complexity will be O(N * 2^(2*M))

Complete Approach:
Instead of finding all the different possible masks of the previous 
rows, we can find the different possible masks for the current row 
to get the answer. This means that we need to find the number of 
ways to fill the current row with blocks filled as vis. We can make 
the following cases:

1. If the current block is already filled, we go on to the next block.

2. If the current block is not filled, we can place the block as 
   either 1*2 or 2*1 form and go on to the next block after updating 
   the blocks visited for the current row and the next 
   row (for 1*2 domino)

Whenever we fill the current row completely, a new set of blocks are 
marked in the next row because of the 1*2 dominos, so we need to add 
that to the answer for the next row. For i = 0, filling 0 cells is 
possible so the base case is DP[0][0] = 1. We need to fill all the n 
rows such that the columns visited for the next row is 0 and all rows 
before n are completely filled, so the final answer would be DP[n][0].

Time Complexity per test case: O(N^2 * M * 2^M)

*/
/*#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[13][(1<<12)];
int n, m;

void dfs(int x, int y, int vis, int nvis) {
    if(x == n) {
        return ;
    }
    if(y >= m) {
        dp[x+1][nvis] += dp[x][vis];
        return ;
    }
    int mask = 1<<y;
    if(vis & mask) {
        dfs(x, y+1, vis, nvis);
    }
    else {
        dfs(x, y+1, vis, nvis | mask);
        if(y + 1 < m && !(vis & mask) && !(vis & (mask << 1))) {
            dfs(x, y+2, vis, nvis);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1<<m); ++j) {
                dfs(i, 0, j, 0);
            }
        }
        cout << dp[n][0] << "\n";
    }
    return 0;
}
*/


/*
2nd Solution:
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vs vector<string>
#define vc vector<char>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvd vector<vd>
#define vvll vector<vll>
#define vvc vector<vc>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define w(x)  \
    int x;    \
    cin >> x; \
    for (ll tc = 1; tc <= x; tc++)
#define in(i, x, y) for (ll i = x; i < y; i++)
#define rin(i, x, y) for (ll i = x; i >= y; i--)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define lb lower_bound
#define ub upper_bound

ll fxp(ll a, ll b) {
    assert(b >= 0);
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res % mod;
}

inline ll minv(ll x) { return fxp(x, mod - 2); }

void c_p_c() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int mXn = 13;
const ll inf = 1e18;
int n, m;
int tot;

ll dp[mXn][mXn][1 << mXn];
ll go(int r, int c, int mask) {
    if (r == n)return (mask == tot);
    ll &ans = dp[r][c][mask];
    if (ans != -1)return ans;
    ans = 0;
    int nr = r, nc = c + 1;
    if (nc == m)nr++, nc = 0;
    if ((mask & 1) == 0) {
        //if up cell is not filled then compulsorily place domino vertical
        int nmask = (mask >> 1) | (1 << (m - 1));
        ans = (ans + go(nr, nc, nmask));
    }
    else {
        //just don't fill domino at this pos
        ans = (ans + go(nr, nc, (mask >> 1)));
        if ((mask & (1 << (m - 1))) == 0 && c > 0) {
            //if left pos is unfilled then fill horizontal
            int nmask = mask | (1 << (m - 1));
            nmask >>= 1;
            nmask |= (1 << (m - 1));
            ans = (ans + go(nr, nc, nmask));
        }
    }
    return ans;
}

signed main() {
    c_p_c();
    w(T) {
        //cout << "Case #" << tc << ": ";
        cin >> n >> m;
        tot = (1 << m) - 1;
        memset(dp, -1, sizeof(dp));
        cout << go(0, 0, tot) << endl;
    }
}
*/

/*
3rd Solution:
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(p) p.begin(),p.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define test(t) int t;cin>>t;while(t--)
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define MAXN 1000006
#define pii pair<ll,ll>
#define F first
#define S second
ll n,m;
ll dp[13][13][5005];
ll rec(ll r,ll c,ll mask){
    if(r==n){
        if(mask==((1<<m)-1))
            return 1;
        else
            return 0;
    }
    if(c==m){
        return rec(r+1,0,mask);
    }
    if(dp[r][c][mask]!=-1)
        return dp[r][c][mask];
    ll ans=0;
    if(r==0){
        ans += rec(r,c+1,mask>>1);
        if(c){
            if((mask&(1<<(m-1)))==0)
                ans += rec(r,c+1,(mask|(1<<(m-1))|(1<<m))>>1);
        }
    }
    else{
        if(c){
            if((mask&1)==0)
                ans += rec(r,c+1,(mask|(1<<m))>>1);
            else{ 
                ans += rec(r,c+1,mask>>1);
                if((mask&(1<<(m-1)))==0)
                    ans +=rec(r,c+1,(mask|(1<<m)|(1<<(m-1)))>>1);
            }
        }
        else{
            if((mask&1)==0)
                ans += rec(r,c+1,(mask|(1<<m))>>1);
            else
                ans += rec(r,c+1,mask>>1);
        }
    }
    return dp[r][c][mask]=ans;
}
signed main(){
    IOS
    test(t){
        cin>>n>>m;
        memset(dp,-1,sizeof(dp));
        ll ans = rec(0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[13][1<<12];
int n,m;

int dfs(int i,int j,int mask){

}

void solve(){
    cin>>n>>m;
    memset(dp,0,sizeof(dp));

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