/*
Find the Number of Rooms

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n × m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.


Input Format

The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either ‘.’ (floor) or '#' (wall).


Output Format

Print one integer: the number of rooms.


Constraints

1 ≤ n, m ≤ 1000


Sample Input 1

5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output 1

3
*/

#include<bits/stdc++.h>
//#define int long long
using namespace std;

vector<string> strs;
int vis[1001][1001];
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<m&&strs[x][y]!='#'){
		return 1;
	}
	return 0;
}

void dfs(int x,int y){
	vis[x][y] = 1;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!vis[nx][ny] && check(nx,ny)){
			dfs(nx,ny);
		}
	}
}

void solve(){
	cin>>n>>m;
	strs.resize(n);
	for(int i=0;i<n;i++){
		cin>>strs[i];
	}
	memset(vis,0,sizeof(vis));
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && strs[i][j]!='#'){
				dfs(i,j);
				ans++;
			}
		}
	}


	cout<<ans<<endl;

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