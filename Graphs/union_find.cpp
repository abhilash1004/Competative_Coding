/*
Also known as Disjoint Union Algorithm
*/
/*
Disjoint Union

Time-Limit: 0.2 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Write a program that manipulates a disjoint set S = S1, S2, ..., Sk.

First of all, the program should read an integer n, then make a disjoint set where each element consists of 0, 1, ..., n-1 respectively.

Next, the program should read an integer q and manipulate the set of q queries. There are two kinds of queries for different operations:

unite(x, y): unite sets that contain x and y, say Sx and Sy, into a new set.
same(x, y): determine whether x and y are in the same set.

Input Format

The first line contains two space-separated integers n and q, (1 ≤ n ≤ 104, 1 ≤ q ≤ 105).
Then, q queries are given in the form com x y, where com represents the type of queries. '0' denotes unite and '1' denotes same operation (x != y).


Output Format

For each same operation, print 1 if x and y are in the same set, otherwise 0, in a line.


Sample Input 1

5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
 


Sample Output 1

0
0
1
1
1
0
1
1
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

struct Union{
	int n,set_size ;//No of	components
	int *rank,*parent;
	Union(){}
	Union(int a){
		n = set_size = a;
		rank = new int(n+1);
		parent = new int(n+1);
		for(int i=0;i<n;i++){rank[i] = 1;parent[i] = i;}
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
	/*void reset(){
		set_size = n;
		for(int i=0;i<n;i++){
			rank[i] = 1;parent[i] = i;
		}
	}
	int size(){
		return set_size;
	}
	void print(){
		for(int i=0;i<n;i++){
			cout<<i<<"->"<<parent[i]<<endl;
		}
	}*/
	bool checkSet(int x,int y){
		if(find(x)==find(y)){
			return 1;
		}
		return 0;
	}
};


void solve(){
	int n;
	cin>>n;
	Union un(n);
	int q;cin>>q;
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		//cout<<a<<b<<c<<endl;
		if(a){
			cout<<un.checkSet(b,c)<<endl;
		}else{
			un.merge(b,c);
		}
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