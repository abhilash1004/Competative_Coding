/**
 * The below code gives the prefix sum in O(logn) and 
 * we can also change a value of an array in O(logn)
 **/

/*
Range Queries I

Time-Limit: 1 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A of n elements. Your task is to process q queries of the following types.

1 i x : Update the value at position i to x.
2 i j : Print the sum of values in the range [i, j].

Input Format

The first input line has two integers n and q: the number of values and queries.
The second line has n integers A1, A2, …, An: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 i x" or "2 i j".


Output Format

Print the result of each query of type 2.


Constraints

1 ≤ n, q ≤ 2 x 105
1 ≤ Ai, x ≤ 109
1 ≤ i ≤ n
1 ≤ i ≤ j ≤ n


Sample Input 1

8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4

Sample Output 1

14
2
11
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200100;
int n;
int a[N];
int tree[4 * N];



void buildtree(int index,int l,int r)
{
	if(l==r)
	{
		tree[index] = a[l];
		return;
	}
	int mid = l + (r - l)/2 ;
	buildtree(2*index,l,mid);
	buildtree(2*index+1,mid+1,r);
	tree[index] = tree[2*index] + tree[2*index + 1];
}

void changevalue(int index,int l,int r,int pos,int val)
{
	if(pos<0 || pos>=n) return;
	if(pos<l || pos>r) return;
	if(l==r)
	{
		//The below commented is not required since we are binary searching the position
		/*if(l!=pos)
			return;*/
		//cout<<"Pos = "<<l<<"\n";
		a[pos] = val;
		tree[index] = val;
		return;
	}
	int mid = l + (r-l)/2;
	//if(pos<=mid)
		changevalue(2*index,l,mid,pos,val);
	//else
		changevalue(2*index + 1,mid+1,r,pos,val);
	tree[index] = tree[2*index] + tree[2*index + 1];
}

int getPrefixSum(int index,int l,int r,int ql,int qr)
{
	if(l>qr || ql>r) return 0;
	if(ql<=l && r<=qr)
		return tree[index];
	int mid = l + (r-l)/2;
	return getPrefixSum(2*index,l,mid,ql,qr) + getPrefixSum(2*index+1,mid+1,r,ql,qr);
}

void solve(){
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	/*for(int i=1;i<(n);i++)
		cout<<a[i]<<" ";
	cout<<endl;*/
	buildtree(1,0,n-1);
	/*for(int i=1;i<(2*n);i++)
		cout<<tree[i]<<" ";
	cout<<endl;*/

	
	for(int i=0;i<q;i++)
	{
		int v,l,r;
		cin>>v>>l>>r;
		switch(v){
			case 1:
				//int p,val;
				//cin>>p>>val;
				changevalue(1,0,n-1,l-1,r);
				break;
			case 2:
				//int l,r;
				//cin>>l>>r;
				cout<<getPrefixSum(1,0,n-1,l-1,r-1)<<endl;
				break;
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