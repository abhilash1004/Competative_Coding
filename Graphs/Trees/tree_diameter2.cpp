/*
Tree Diameter - II

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a tree consisting of n nodes. The diameter of a tree is the maximum distance between two nodes. Your task is to count the number of different diameters of the tree.


Input Format

The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.


Output Format

Print the count of diameters of the tree.


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

2

Note

Two diameters are:

2 → 1 → 3 → 4
2 → 1 → 3 → 5
*/


/*
My Sample Input 1:
14
1 2
2 3
2 14
4 6
5 6
6 14
14 7
7 8
8 9
8 10
7 11
11 12
11 13

My Sample Output 1:
16

My Sample Input 2:
13
1 2
2 3
2 7
4 6
5 6
6 7
7 8
8 9
8 10
7 11
11 12
11 13

My Sample Output 2:
24
*/
// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// int n;
// vector<int> g[200100];
// vector<int> dep;
// vector<int> par;

// vector<int> subTreeSize;

// void findsubTreeSize(int node,int parent){
//     subTreeSize[node] = 1;
//     for(auto i:g[node]){
//         if(i!=parent){
//             findsubTreeSize(i,node);
//             subTreeSize[node]+=subTreeSize[i];
//         }
//     }
// }
// int treeDepCnt = 0;
// /*int findDepthNodes(int node,int parent,int pd,int rd){
//     if(pd==rd){
//         return 1;
//     }
//     int ans = 0;
//     for(auto i:g[node]){
//         if(i!=parent){
//             ans += findDepthNodes(i,node,pd+1,rd);
//         }
//     }
//     return ans;
// }*/
// void findDepthNodes(int node,int parent,int pd,int rd){
//     if(pd==rd){
//         //return 1;
//         treeDepCnt++;
//     }
//     //int ans = 0;
//     for(auto i:g[node]){
//         if(i!=parent){
//             /*ans +=*/ findDepthNodes(i,node,pd+1,rd);
//         }
//     }
//     //return ans;
// }

// void dfs(int node,int parent,int depth){
//     dep[node] = depth;
//     par[node] = parent;
//     for(auto i:g[node]){
//         if(i!=parent){
//             dfs(i,node,depth+1);
//         }
//     } 
// }

// void solve(){
//     cin>>n;
//     par.resize(n+1);
//     dep.resize(n+1);
//     subTreeSize.resize(n+1);
    
//     for(int i=0;i<n-1;i++){
//         int a,b;
//         cin>>a>>b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     dfs(1,0,0);
//     int max_depth_node = 1;
//     for(int i=2;i<=n;i++){
//         if(dep[max_depth_node]<dep[i]){
//             max_depth_node = i;
//         }
//     }
//     dfs(max_depth_node,0,0);
//     int final_node = 1;
//     for(int i=2;i<=n;i++){
//         if(dep[final_node]<dep[i]){
//             final_node = i;
//         }
//     }

//     //cout<<dep[final_node]<<endl;

//     if(dep[final_node]%2==0){   //Has 1 Center
//         int center = final_node;
//         for(int i=0;i<(dep[final_node])/2;i++){
//             center = par[center];
//         }
//         vector<int> childSizes;
//         for(auto i:g[center]){
//             //findsubTreeSize(i,center);
//             //childSizes.push_back(subTreeSize[i]-1);
//             treeDepCnt = 0;
//             findDepthNodes(i,center,0,(dep[final_node]/2)-1);
//             childSizes.push_back(treeDepCnt);
//         }
//         int ans = 0;
//         /*for(int i=0;i<childSizes.size();i++){
//             for(int j=i+1;j<childSizes.size();j++){
//                 ans += 1ll*childSizes[i]*childSizes[j];
//             }
//         }*/
//         int sum = accumulate(childSizes.begin(),childSizes.end(),0);
//         for(auto i:childSizes){
//             ans += (i)*(sum-i);
//         }
//         cout<<ans/2<<endl;
//     }else{          //2 Centers
//         int center1 = final_node;
//         for(int i=0;i<(dep[final_node])/2;i++){
//             center1 = par[center1];
//         }
//         int center2 = par[center1];
//         //cout<<center1<<" "<<center2<<endl;
//         int x,y;
//         // x = findDepthNodes(center1,center2,0,(dep[final_node])/2);
//         // y = findDepthNodes(center2,center1,0,(dep[final_node])/2);
//        // cout<<x<<" "<<y<<endl;
//         treeDepCnt = 0;
//         findDepthNodes(center1,center2,0,(dep[final_node])/2);
//         x = treeDepCnt;
//         treeDepCnt = 0;
//         findDepthNodes(center2,center1,0,(dep[final_node])/2);
//         //int ans = 1ll*x*y;
//         int ans = treeDepCnt * x;
//         cout<<ans<<endl;
//     }
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t=1;
//     //cin>>t;
//     while(t--){
//         solve();
//     }
// }

//Some Mistake in above code

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using ii=pair<ll,ll>;
ll n;
vector<ll>g[200100];
ll d[200100];
ll vis[200100];
ll p[200100];
void dfs(ll node,ll par,ll dpt)
{
    vis[node]=1;
    d[node]=dpt;
    p[node]=par;
    for(auto it:g[node])
    {
        if(it==par) continue;
        if(!vis[it])
        {
            dfs(it,node,dpt+1);
        }
    }
}
ll cnt=0;
void dfs2(ll node,ll par,ll dpt,ll x)
{
    vis[node]=1;
    d[node]=dpt;
    if(dpt==x) cnt++;
    for(auto it:g[node])
    {
        if(it==par) continue;
        if(!vis[it])
        {
            dfs2(it,node,dpt+1,x);
        }
    }
}
void solve()
{
    cin>>n;
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n==1)
    {
        cout<<1<<endl;
        return ;
    }
    dfs(1,0,0);
    ll max_dis=-1,max_node=0;
    for(ll i=1;i<=n;i++)
    {
        if(max_dis<d[i])
        {
            max_dis=d[i];
            max_node=i;
        }
    }
    //cout<<max_node<<endl;
    memset(vis,0,sizeof(vis));
    dfs(max_node,0,0);
    ll dia=-1;
    ll other_end=0;
    for(ll i=1;i<=n;i++)
    {
        if(d[i]>dia)
        {
            dia=d[i];
            other_end=i;
        }
    }
    //cout<<other_end<<" "<<dia<<endl;
    if(dia%2==0)
    {
        ll c1=other_end;
        for(ll i=0;i<dia/2;i++)
        {
            c1=p[c1];
        }
        //cout<<c1<<endl;
        ll x=dia/2-1;
        vector<ll>v;
        memset(vis,0,sizeof(vis));
        for(auto it:g[c1])
        {
            cnt=0;
            dfs2(it,c1,0,x);
            v.push_back(cnt);
        }
        ll sum=0;
        for(auto it:v)
        {
            sum+=it;
        }
        ll ans=0;
        for(auto it:v)
        {
            ans+=(sum-it)*it;
        }
        cout<<ans/2<<endl;
    }
    else
    {
        ll c1=other_end,c2;
        for(ll i=0;i<dia/2;i++)
        {
            c1=p[c1];
        }
        c2=p[c1];
        memset(vis,0,sizeof(vis));
        cnt=0;
        //cout<<dia/2<<endl;
        dfs2(c1,c2,0,dia/2);
        ll x=cnt;
        //cout<<x<<endl;
        cnt=0;
        dfs2(c2,c1,0,dia/2);
        x=x*cnt;
        cout<<x<<endl;
    }
    
}
signed main(){  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}