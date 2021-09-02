/*
U will be a given 2D grid of '.' & '#'. '#' is a wall. You will be
given 2 points i.e start and end and you have to find shortest dist
b/w those points

Sample Input
5 5                	//n,m
.....
.####
.#...
.##..
.....
0 0                	//start point
2 2                	//end point
Sample Output
10

Sample Input
5 5
.....
.####
.#..#
.###.
.....
0 0
2 2
Sample Output
inf

Sample Input
5 5
.....
.####
.#...
.##..
.....
0 0
4 4
Sample Output
8
   
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> ii;
#define F first
#define S second

vector<string> arr;
vector<vector<int>> dist;  //Graph
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<m && arr[x][y]!='#'){
		return 1;
	}
	return 0;
}

void findShortestPath(ii first){ // Doing BFS
	dist = vector<vector<int>>(n,vector<int>(m,1e9));
	dist[first.F][first.S] = 0;
	queue<ii> q;
	q.push(first);
	while(!q.empty()){
		ii temp = q.front();
		q.pop();
		int x = temp.F;
		int y = temp.S;
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(check(nx,ny) && dist[nx][ny]>(dist[x][y]+1)){
				q.push({nx,ny});
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ii start,end;
	cin>>start.F>>start.S>>end.F>>end.S;
	findShortestPath(start);

	if(dist[end.F][end.S]<1e9){
		cout<<dist[end.F][end.S]<<"\t";
	}else{
		cout<<"inf\n";
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dist[i][j]<1e9){
				cout<<dist[i][j]<<"\t";
			}else{
				cout<<"inf\t";
			}
		}
		cout<<"\n";
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