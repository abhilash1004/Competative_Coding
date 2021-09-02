/*
Creating Teams

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are n students in AlgoZenith Course and m friendships between them. Your task is to divide the students into two teams in such a way that no two students in a team are friends. You can freely choose the sizes of the teams. The size of each team should be positive.


Input Format

The first input line has two integers n and m: the number of students and friendships. The students are numbered 1, 2, …, n.
Then, there are m lines describing friendships. Each line has two integers a and b: students a and b are friends.
Every friendship is between two different students. You can assume that there is at most one friendship between any two students.


Output Format

Print ‘YES’ if it's possible to divide students in two teams, otherwise print ‘NO’.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

5 3
1 2
1 3
4 5

Sample Output 1

YES

Sample Input 2

4 3
1 2
2 3
1 3

Sample Output 2

NO
*/

#include<bits/stdc++.h>
//#define int long long
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
	isBipartite?(cout<<"YES\n"):(cout<<"NO\n");

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
