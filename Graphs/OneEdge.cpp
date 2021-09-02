/*
One Edge

Time-Limit: 2 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an undirected graph with n nodes, and m edges between them. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.


Input Format

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line has two integers a and b: there is an edge between those nodes.
An edge always connects two different nodes, and there is at most one edge between any two nodes.


Output Format

Print the number of ways to add such edge, described in the statement.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 4
1 2
2 3
1 3
4 5

Sample Output 1

6

Sample Input 2

4 3
1 2
2 3
3 4

Sample Input 3

0

Note

Explanation 1:
There are 6 ways to add edge so that the number of connected components in the graph decreases: (1, 4), (1, 5), (2, 4), (2, 5), (3, 4), (3, 5).

Explanation 2:
The given graph is already connected. Even if add any edge, we can't decrease the number of connected components.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<bool> vis;
vector<int> compLength;
vector<int> nodeComponent;
void dfs(int level){
	if(vis[level]) return;
	vis[level] = 1;
	if(compLength.size()){
		compLength[compLength.size()-1]++;
		nodeComponent[level] = compLength.size();
	}
	for(auto i:graph[level]){
		if(!vis[i]){
			dfs(i);
		}
	}
}

void solve(){
	cin>>n>>m;
	graph.clear();
	graph.resize(n+1);
	nodeComponent.resize(n+1);

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	compLength.clear();
	vis.assign(n+1,0);
	int components = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			components++;
			compLength.push_back(0);
			dfs(i);
		}
	}

	int ans = 0;
	for(int i=0;i<compLength.size();i++){
		ans += (compLength[i] * (n-compLength[i]));
	}
	ans /= 2;
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