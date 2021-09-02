/*
Input:
9 14 1
1 2 0
1 8 1
2 8 1
2 3 1
8 9 1
8 7 1
3 9 1
3 6 0
9 7 1
3 4 0
4 6 1
4 5 1
5 6 1
7 6 1

Output:
0 0 1 1 2 1 2 1 2 

*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> ii;
vector<vector<ii>> graph;
int n,m;
vector<int> par;
vector<int> dist;

void bfs01(int source){
	deque<int> dq;
	dist.assign(n+1,1e9);
	par.assign(n+1,0);
	dq.push_back(source);
	dist[source] = 0;
	while(!dq.empty()){
		int x = dq.front();
		dq.pop_front();
		for(auto i:graph[x]){
			int neighbour = i.first;
			int weight = i.second;
			if(dist[neighbour]>dist[x]+weight){
				dist[neighbour] = dist[x]+weight;
				par[neighbour] = x;
				if(weight){
					dq.push_back(neighbour);
				}else{
					dq.push_front(neighbour);
				}
			}
		}
	}

}

void solve(){
	int source;
	cin>>n>>m>>source;
	graph.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	bfs01(source);
	for(int i=1;i<=n;i++){
		cout/*<<i<<"="*/<<dist[i]<<" ";
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