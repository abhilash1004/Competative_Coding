/*
Round Trip

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Zenithland has n cities and m roads between them. Your task is to check for the existence of a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.


Input Format

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.


Output Format

Print ‘YES’ if such round trip exists, otherwise print ‘NO’.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 6
1 3
1 2
5 3
1 5
2 4
4 5

Sample Output 1

YES

Sample Input 2

4 3
1 2
1 3
3 4

Sample Output 2

NO
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<bool> vis(100001);
bool isCycle = 0;

void dfs(int node,int parent){
	//if(isCycle) return;
	vis[node] = 1;
	for(auto i:graph[node]){
		if(!vis[i]){
			dfs(i,node);
		}else if(i==parent){
			continue;
		}
		else{
			//cout<<"("<<node<<" "<<i<<") ";
			isCycle = 1;
			return;
		}
	}
}

void solve(){
	cin>>n>>m;

	graph.clear();
	graph.resize(n+1);
	//vis.resize(n+1);
	vis.assign(n+1,0);

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,0);
		}
	}
	isCycle?(cout<<"Yes\n"):(cout<<"No\n");
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