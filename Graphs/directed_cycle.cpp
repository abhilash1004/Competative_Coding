/*
8 9
1 2
2 3
3 4
4 5
1 6
6 7
7 8
7 5
5 2

Output:
Yes

8 8
1 2
2 3
3 4
4 5
1 6
6 7
7 8
7 5       //Cross Edge(Depends On Traversal)

Output:
No

*/



#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vis;
vector<vector<int>> graph;
int n,m;
bool isCycle = 0;

void dfs(int node){
	vis[node] = 1;
	for(auto i:graph[node]){
		if(!vis[i]){			// front edge
			dfs(i);
		}else if(vis[i] == 1){ 	// back edge
			isCycle = 1;
		}else{					// Cross edge
		}
	}
	vis[node] = 2;				// Marking track finished 
}

void solve(){
	cin>>n>>m;

	graph.clear();
	graph.resize(n+1);
	vis.assign(n+1,0);

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
	}
	//cout<<"HEy\n";
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	//cout<<"HEy\n";
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