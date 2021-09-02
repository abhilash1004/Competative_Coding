#include<bits/stdc++.h>
using namespace std;

struct Union{
	int n,set_size ;//No of	components
	int *rank,*parent;
	Union(){}
	Union(int a){
		n = set_size = a;
		rank = new int(n+1);
		parent = new int(n+1);
		for(int i=1;i<=n;i++){rank[i] = 1;parent[i] = i;}
	}
	int find(int x){
		if(parent[x]==x) return x;
		return parent[x] = find(parent[x]);
	}
	void merge(int x,int y){
		int a = find(x);
		int b = find(y);
		if(a==b) return;

		if(rank[a] <= rank[b]){
			parent[a] = b;
			rank[b] += rank[a];
			rank[a] = 0;
		}else{
			parent[b] = a;
			rank[a] += rank[b];
			rank[b] = 0;
		}
		set_size--;
	}
	void reset(){
		set_size = n;
		for(int i=1;i<=n;i++){
			rank[i] = 1;parent[i] = i;
		}
	}
	int size(){
		return set_size;
	}
	void print(){
		for(int i=1;i<=n;i++){
			cout<<i<<"->"<<parent[i]<<endl;
		}
	}
	bool checkSet(int x,int y){
		if(find(x)==find(y)){
			return 1;
		}
		return 0;
	}
};

vector<pair<int,int>> g[100100];

void solve(){
	int n,e;
	cin>>n>>e;

	vector<pair<int,pair<int,int>>> edge;
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge.push_back({c,{a,b}});
	}
	sort(edge.begin(),edge.end());
	Union unset(n);
	int cost = 0,addededge = 0;
	for(auto v:edge){
		int x = v.second.first;
		int y = v.second.second;
		if(!unset.checkSet(x,y)){
			cost+=v.first;
			unset.merge(x,y);
			g[x].push_back({y,v.first});
			g[y].push_back({x,v.first});
			addededge++;
		}
		//cout<<x<<" "<<y<<" "<<v.first<<endl;
	}
	if(addededge != n-1){
		cout<<"Spanning Tree Can't Be Created\n";
		//return;	
	}else{
		cout<<"Minimum Cost = "<<cost<<endl;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}