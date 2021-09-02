#include<bits/stdc++.h>


#define parent(i) i/2
#define left(i) 2*i
#define right(i) 2*i + 1
using namespace std;

void swap(int &a,int &b){
	a ^= b;
	b ^= a;
	a ^= b;
}

void max_heapify(vector<int> &v,int i,int n){
	if(i==0 || n==0){
		return;
	}
	int l = left(i);
	int r = right(i);
	//int n = v.size();
	int largest = i;
	if(l<n && v[l]>v[i]){
		largest = l;
	}
	if(r<n && v[r]>v[largest]){
		largest = r;
	}
	if(largest!=i){
		//Swap
		v[largest] ^= v[i];
		v[i] ^= v[largest];
		v[largest] ^= v[i];
		max_heapify(v,largest,n);
	}
}
void print_heap(const vector<int> &v){
	for(int i=1;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void build_max_heap(vector<int> &v,int n){
	for(int i=n/2;i>=1;i--){
		max_heapify(v,i,n);
	}
}

void heap_sort(vector<int> &v){
	int n = v.size();
	build_max_heap(v,n);
	
	for(int i=n-1;i>1;i--)
	{
		swap(v[i],v[1]);
		n--;
		max_heapify(v,1,n);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cout<<"-------------Heap-------------------\n";
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++)
		cin>>v[i];
	heap_sort(v);
	print_heap(v);
	return 0;
}
