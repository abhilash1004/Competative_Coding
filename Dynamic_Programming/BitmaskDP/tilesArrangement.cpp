/*
An n*3 grid has numbers. U have to place k 1*2 tile on the grid either 
vertically or horizontally. If u place them on the grid u will get 
that many points. So place the tiles on the grid to get maximum 
points.
Note: Overlapping of tiles is not allowed.
Constraints:
1<=N,k<=1000  

Input:
first line contains N and K
Next N lines contains the values of grid

Sample Input:
5 3
2 1 -1
1 3 2
0 2 3
2 1 1
3 3 0

Sample Output:
16

Sample Input 2:
2 2
0 4 1
3 5 1

Sample Output 2:
13
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

int findMax(int i,int j,int mask,int rk){
	if(rk==0){
		return 
	}
}

int n,k;
int arr[1001][3];
int dp[1001][3][1<<3];
bool dpcheck[1001][3][1<<3];
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	memset(dpcheck,0,sizeof(dpcheck));
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}