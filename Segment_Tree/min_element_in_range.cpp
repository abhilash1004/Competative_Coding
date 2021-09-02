/*
Design a DS to solve the below queries:
U are given with an array of length n
Query 1: 1 x v :meaning replace x element with v
Query 2: 2 l r :find min in range[l,r] and it's count
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200100;
int a[N];

struct node{
	int mini;
	int cnt;
	node(int m=1e9,int c=0){
		mini = m;
		cnt = c;
	}
};

node tree[4*N];
int n;

node merge(node n1,node n2)
{
	if(n1.mini==n2.mini)
		return node(n1.mini,n1.cnt+n2.cnt);
	if(n1.mini<n2.mini)
		return n1;
	return n2;
}

void buildtree(int index,int l,int r)
{
	if(l==r)
	{
		tree[index] = node(a[l],1);
		return; 
	}
	int mid = l + (r-l)/2;
	buildtree(2*index,l,mid);
	buildtree(2*index+1,mid+1,r);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
}

void replace(int index,int l,int r,int pos,int val){
	if(pos<l || pos>r) return;
	if(l==r){
		tree[index]= node(val,1);
		a[pos] = val;
		//cout<<index<<" pos="<<pos+1<<" "<<tree[index].mini<<endl;
		return;
	}
	int mid = l + (r-l)/2;
	replace(2*index,l,mid,pos,val);
	replace(2*index+1,mid+1,r,pos,val);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
}

struct node getValue(int index,int l,int r,int ql,int qr)
{
	if(ql>r || qr<l) return node(1e9,0);
	if(ql<=l && r<=qr)
		return tree[index];
	int mid = l + (r-l)/2;
	node n1,n2;
	n1 = getValue(2*index,l,mid,ql,qr);
	n2 = getValue(2*index+1,mid+1,r,ql,qr);
	//return merge(tree[2*index],tree[2*index+1]);
	return merge(n1,n2);
}

void solve(){
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>a[i];
	buildtree(1,0,n-1);
	/*for(int i=1;i<2*n;i++){
		cout<<i<<" "<<tree[i].mini<<" "<<tree[i].cnt<<"\n";
	}
	cout<<endl;*/
	int v,l,r;
	while(q--){
		cin>>v>>l>>r;
		if(v==1){
			replace(1,0,n-1,l-1,r);
		}else{
			node s = getValue(1,0,n-1,l-1,r-1);
			cout<<"Min = "<<s.mini<<" and Count = "<<s.cnt<<endl;
		}
	}
	/*for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<2*n;i++){
		cout<<i<<" "<<tree[i].mini<<" "<<tree[i].cnt<<"\n";
	}
	cout<<endl;*/
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