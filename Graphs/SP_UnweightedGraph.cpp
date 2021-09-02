/*
Input:
8 10 1 8
1 2
1 4
2 3
4 5
4 8
5 6
5 7
5 8
6 7
7 8

Output:
1=0 2=1 3=2 4=1 5=2 6=3 7=3 8=2 
1->4->8->
*/


#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> graph;
vector<int> par;
vector<int> dist; 
int n,m;

void bfs(int source){
	dist.resize(n+1);
	dist.assign(n+1,1e9);
	queue<int> q;
	dist[source] = 0;
	q.push(source);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto i:graph[x]){
			if(dist[i]>dist[x]+1){
				dist[i] = dist[x] + 1;
				par[i] = x;
				q.push(i);
			}
		}
	}
}


void solve(){
	int source,dest;
	cin>>n>>m>>source>>dest;
	graph.resize(n+1);
	par.assign(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(source);
	for(int i=1;i<=n;i++){
		cout<<i<<"="<<dist[i]<<" ";
	}
	cout<<endl;
	int x = dest;
	vector<int> route;
	route.push_back(dest);
	while(par[x]){
		route.push_back(par[x]);
		x = par[x];
	}
	reverse(route.begin(),route.end());
	for(auto i:route){
		cout<<i<<"->";
	}

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