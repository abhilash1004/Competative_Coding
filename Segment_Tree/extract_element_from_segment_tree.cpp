/*
Range Queries II

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A of n elements. Your task is to process q queries of the following types.

1 i j x : Increase each value at positions from [i, j] by x.
2 i : Print the value at position i.

Input Format

The first input line has two integers n and q: the number of values and queries.
The second line has n integers A1, A2, …, An: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 i j x" or "2 i".


Output Format

Print the result of each query of type 2.


Constraints

1 ≤ n, q ≤ 2 x 105
1 ≤ Ai, x ≤ 109
1 ≤ i ≤ n
1 ≤ i ≤ j ≤ n


Sample Input 1

8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

Sample Output 1

5
6 
*/

/*******************
//Solution 1
********************/

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5;
int n;
//int a[N];
int tree[4*N];

int merge(int a,int b){return a+b;}

void addElement(int index,int l,int r,int pos,int val){
	if(pos<l || pos>r)return;
	if(l==r)
	{
		tree[index] += val;
		return;
	}
	int mid = l + (r-l)/2;
	addElement(2*index,l,mid,pos,val);
	addElement(2*index+1,mid+1,r,pos,val);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
}
int getElement(int index,int l,int r,int ql,int qr){
	if(ql>r || qr<l) return 0;
	if(ql<=l && r<=qr){
		return tree[index];
	}
	int mid = l + (r-l)/2;
	return getElement(2*index,l,mid,ql,qr) + getElement(2*index+1,mid+1,r,ql,qr);
}

void solve(){
	memset(tree,0,sizeof(tree));
	int q,x;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>x;
		addElement(1,0,n-1,i,x);
		addElement(1,0,n-1,i+1,-x);
	}
	while(q--){
		int v;
		cin>>v;
		//cout<<v<<" ";
		if(v==2){
			int x;
			cin>>x;
			x--;
			cout<<getElement(1,0,n-1,0,x)<<endl;
		}else{
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			addElement(1,0,n-1,l,x);
			addElement(1,0,n-1,r+1,-x);
		}
	}
	/*for(int i=1;i<(2*n);i++)
		cout<<tree[i]<<" ";
	cout<<endl;*/
}


//2nd solution

/*int a[N];

void build2(int index,int l,int r){
	if(l==r) return a[l];

	int mid = l + (r-l)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
} */

void addElementRange2(int index,int l,int r,int ql,int qr,int value){
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		//cout<<l<<" "<<r<<endl;
		tree[index]+=value;
		return;
	}
	int mid = l + (r-l)/2;
	addElementRange2(2*index,l,mid,ql,qr,value);
	addElementRange2(2*index+1,mid+1,r,ql,qr,value);
}

int getElement2(int index,int l,int r,int pos){
	if(l>pos || r<pos) return 0;
	if(l==r){
		return tree[index];
	}
	int mid = l + (r-l)/2;
	if(pos<=mid){
		return getElement2(2*index,l,mid,pos) + tree[index];
	}
	else{
		return getElement2(2*index+1,mid+1,r,pos) + tree[index];
	}

}

void solve2(){
	memset(tree,0,sizeof(tree));
	int q,x;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>x;
		addElementRange2(1,0,n-1,i,i,x);
		//addElement(1,0,n-1,i+1,-x);
	}
	//addElementRange2(1,0,n-1,0,0,10);
	while(q--){
		int v;
		cin>>v;
		//cout<<v<<" ";
		if(v==2){
			int x;
			cin>>x;
			x--;
			cout<<getElement2(1,0,n-1,x)<<endl;
		}else{
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			addElementRange2(1,0,n-1,l,r,x);
			//addElement(1,0,n-1,r+1,-x);
		}
	}
	for(int i=1;i<(2*n);i++)
		cout<<tree[i]<<" ";
	cout<<endl;
}


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//solve();
	solve2();
}