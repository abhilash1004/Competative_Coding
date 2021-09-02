/*
Tree Diameter - I

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a tree consisting of n nodes. The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.


Input Format

The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.


Output Format

Print the diameter of the tree.


Constraints

1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5
1 2
1 3
3 4
3 5

Sample Output 1

3

Note

The diameter corresponds to the path 2→1→3→5.
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n;
vector<int> g[200100];
vector<int> dep;

void dfs(int node,int parent,int depth){
	dep[node] = depth;
	for(auto i:g[node]){
		if(i!=parent){
			dfs(i,node,depth+1);
		}
	}
}

void solve(){
	cin>>n;
	dep.resize(n+1);
	for(int i=0;i<=n;i++){
		g[i].clear();
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0,0);
	int max_depth_node = 1;
	for(int i=2;i<=n;i++){
		if(dep[max_depth_node]<dep[i]){
			max_depth_node = i;
		}
	}
	dfs(max_depth_node,0,0);
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans,dep[i]);
	}
	cout<<ans<<endl;
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