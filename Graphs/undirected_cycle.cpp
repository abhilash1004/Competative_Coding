#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<bool> vis;
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