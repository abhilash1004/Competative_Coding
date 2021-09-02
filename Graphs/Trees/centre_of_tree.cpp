/*
Center of Tree

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a tree consisting of n nodes. Find the center of a tree. If there exist multiple centers, print -1.


Input Format

The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.


Output Format

Print the center of a tree. If there exist multiple centers, print -1.


Constraints

1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n


Sample Input 1

3
1 2
1 3

Sample Output 1

1
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

int n;
vector<int> g[200100];
vector<int> dep;
vector<int> par;

void dfs(int node,int parent,int depth){
    dep[node] = depth;
    par[node] = parent;
    for(auto i:g[node]){
        if(i!=parent){
            dfs(i,node,depth+1);
        }
    }
}


void solve(){
    cin>>n;
    par.resize(n+1);
    dep.resize(n+1);
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
    int final_node = 1;
    for(int i=2;i<=n;i++){
        if(dep[final_node]<dep[i]){
            final_node = i;
        }
    }
    //cout<<dep[final_node]<<" "<<final_node<<endl;
    /*for(int i = 1;i<=n;i++){
        cout<<i<<"-parent->"<<par[i]<<endl;
    }*/
    if(dep[final_node]%2==1){
        cout<<-1<<endl;
    }else{
        int x = final_node;
        for(int i=0;i<(dep[final_node]/2);i++){
            x = par[x];
        }
        cout<<x<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    {
        solve();
    }
}