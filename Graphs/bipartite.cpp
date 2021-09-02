#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<bool> vis;
vector<int> color;
bool isBipartite = 1;

void dfs(int level,int prevcolor){
	//if(vis[level]) return;
	vis[level] = 1;
	color[level] = 1 - prevcolor;
	for(auto i:graph[level]){
		if(!vis[i]){
			dfs(i,color[level]);
		}else{
			if(color[i] == color[level]){
				isBipartite = 0;
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	/*graph =graph.assign(n,vector<int>(m,100));*/
	graph.clear();
	graph.resize(n+1);
	color.clear();
	color.resize(n+1);

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	vis.assign(n+1,0);
	int components = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			components++;
			color[i] = 0;
			dfs(i,0);
		}
	}
	//cout<<"components = "<<components<<endl;
	/*if(isBipartite){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}*/
	isBipartite?(cout<<"Yes\n"):(cout<<"No\n");

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