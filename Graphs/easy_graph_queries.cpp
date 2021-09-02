/*
Easy Graph Queries

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an undirected graph G with N nodes and M edges. You've to answer Q queries. Each query is either of the following two types:

1 X: Print the size of the connected components containing node X.
2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected component, else print ‘NO’ (without quotes).

Input Format

The first line of input contains three space-separated integers N, M, and Q (1 ≤ N, M, Q ≤ 105).
Next M lines contain two space-separated integers u and v (1 ≤ u, v ≤ N).
Each of the next Q lines contains queries of one of the types as described in the statement.


Output Format

Print Q lines as the answer to the Q queries, each on a new line.


Sample Input 1

6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6

Sample Output 1

3
1
NO
2
YES
*/
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> graph[100100];
vector<int> component;
vector<int> compSize;

void dfs(int node,int curComponent){
	component[node] = curComponent;
	compSize[curComponent]++;
	for(auto i:graph[node]){
		if(!component[i]){
			dfs(i,curComponent);
		}
	}
}

void solve(){
	int q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		graph[i].clear();
	}
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	component.assign(n+1,0);
	compSize.assign(n+1,0);
	int comp = 0;
	for(int i=1;i<=n;i++){
		if(!component[i]){
			comp++;
			dfs(i,comp);
		}
	}

	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int a;
			cin>>a;
			cout<<compSize[component[a]]<<endl;
		}else{
			int a,b;
			cin>>a>>b;
			component[a]==component[b]?cout<<"YES\n":cout<<"NO\n";
		}
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