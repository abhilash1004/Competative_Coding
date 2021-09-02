#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<bool> vis;

void dfs(int level){
	//if(vis[level]) return; //Not required
	vis[level] = 1;
	for(auto i:graph[level]){
		if(!vis[i]){
			dfs(i);
		}
	}
}

void solve(){
	cin>>n>>m;
	/*graph =graph.assign(n,vector<int>(m,100));*/
	graph.clear();
	graph.resize(n+1);

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<(int)graph[i].size();j++){
			cout<<i<<" "<<graph[i][j]<<"->";
		}
		cout<<endl;
	}*/

	vis.assign(n+1,0);
	int components = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			components++;
			dfs(i);
		}
	}
	cout<<"components = "<<components<<endl;
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