/*
Building Roads

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Zenithland has n cities and m roads between them. The goal is to construct new roads so that there is a route between any two cities. A road is bidirectional.
Your task is to find out the minimum number of roads required.


Input Format

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
 


Output Format

Print the number of minimum roads required.


Constraints

1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

4 2
1 2
3 4

Sample Output 1

1

Note

Construct a road between cities 1 and 3.
*/
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<bool> vis;

void dfs(int level){
    vis[level] = 1;
    for(auto i:graph[level]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void solve(){
    cin>>n>>m;
    graph.clear();
    graph.resize(n+1);

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
            dfs(i);
        }
    }
    cout<<components-1<<endl; //Total No of roads = comp -1
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