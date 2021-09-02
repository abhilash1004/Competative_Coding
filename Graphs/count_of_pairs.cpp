/*
Find no of unodered pairs (x,y) which are able do to 
decrease number of components of the graph.
Sample input:
9 8
1 3
1 4
4 3
2 3
5 6
6 7
5 7
8 9

Sample output:
26

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
	/*graph =graph.assign(n,vector<int>(m,100));*/
	graph.clear();
	graph.resize(n+1);
	nodeComponent.resize(n+1);

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
	//1st method
	int ans1 = 0;
	for(int i=0;i<compLength.size();i++){
		for(int j=i+1;j<compLength.size();j++){
			ans1+=(compLength[i] * compLength[j]);
		}
	}
	cout<<ans1<<endl;

	//2nd Method
	int ans2 = 0;
	for(int i=0;i<compLength.size();i++){
		ans2 += (compLength[i] * (n-compLength[i]));
	}
	ans2 /= 2;
	cout<<ans2<<endl;
	//cout<<"components = "<<components<<endl;
	for(int i=1;i<nodeComponent.size();i++){
		cout<<i<<"->"<<nodeComponent[i]<<" ";
	}
	cout<<endl;
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