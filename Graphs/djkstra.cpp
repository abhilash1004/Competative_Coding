/*
9 15 1
1 2 4
2 8 8
2 3 8
2 8 11
3 4 7
3 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 8 6
6 7 1
7 8 7
1 9 2

Output:
0 4 12 19 14 12 13 6 2 
*/

#include<bits/stdc++.h>
#define lli long long
using namespace std;
typedef pair<int,int> ii;
#define F first
#define S second
#define MP make_pair

const int N = 1e6 + 5;

class cmp
{
public:
	bool operator()(const ii &p1,const ii &p2){
		return p1.S > p2.S;
	}	
};


int n;
vector<ii> graph[N];
vector<lli> dist;
vector<int> vis;

void dijkstras(int source){
	dist.assign(n+1,1e18);
	vis.assign(n+1,0);
	dist[source] = 0;

	auto cmp2 = [](const ii &p1,const ii &p2){
		return p1.S > p2.S;
	};

	//priority_queue<ii,vector<ii>,cmp> pq;
	priority_queue<ii,vector<ii>,decltype(cmp2)> pq(cmp2);

	pq.push({source,0});

	/*for(auto i:graph[source]){
		pq.push(i);
		cout<<i.F-1<<" "<<i.S<<endl;
	}
	cout<<"____\n";
	while(!pq.empty()){
		cout<<pq.top().F-1<<" "<<pq.top().S<<endl;
		pq.pop();
	}*/

	while(!pq.empty()){
		ii currNode = pq.top();
		pq.pop();
		if(vis[currNode.F]) continue;
		vis[currNode.F] = 1;
		for(auto i:graph[currNode.F]){
			int neigh = i.F;
			int weight = i.S;
			if(dist[neigh] > dist[currNode.F] + weight){
				dist[neigh] = dist[currNode.F] + weight;
				pq.push({neigh,dist[neigh]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	std::cout<<endl;


}

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
	//adj format vector of 2 column having adjacent node and edge weight
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        vector<int> vis(V,0);
        priority_queue<pair<int,int>> pq;
        pq.push({0,S});
        dist[S]=0;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int node = p.second;
            int curdist = -p.first; 
            if(vis[node])continue;
            for(auto v:adj[node]){
                int nnode = v[0];
                int w = v[1];
                if(dist[nnode]>(curdist + w)){
                    dist[nnode] = curdist+w;
                    pq.push({-(curdist+w),nnode});
                }
            }
        }
        return dist;
    }
    
};

void solve(){
	int m,source;
	cin>>n>>m>>source;
	//source++;
	for(int i=1;i<=n;i++)
		graph[i].clear();
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		//a++;b++;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	dijkstras(source);
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