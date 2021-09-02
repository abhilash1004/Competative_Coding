/*
Given a bitonic array A consisting of N integers and an integer Q. 
n each query, you will be given an integer K, 
find the positions of K in A. Integer K exists in A.

Bitonic array - A bitonic sequence is a sequence 
with A[1]<A[2]<A[3]....A[k]>A[k+1]>A[k+2]....>A[N] for some 1<=K≤N.

Sample Input:
1
6 4
1 2 5 3 2 1
1
2
5
3

Sample Output:
1 6
2 5
3
4
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;


int check(const vector<int> &v,int x){
	/*if(!x) return 0;
	return v[x-1]>v[x];*/
	if(!x) return 1;
	return v[x]>=v[x-1];
}


int getIndex(const vector<int> &v)
{
	int l = 0,h = v.size()-1;
	int ans = 0;
	while(l<=h)
	{
		int m = l + (h-l)/2;
		//cout<<m<<" "<<check(v,m)<<endl;
		/*if(check(v,m)){
			ans = m;
			h = m - 1;
		}
		else{
			l = m+1;
		}*/
		if(check(v,m)){
			ans = m;
			l = m + 1;
		}
		else{
			h = m - 1;
		}
	}
	//cout<<endl;
	return ans;
}

int binary_search(const vector<int> &v,int x,int low,int high,int asc=1){
	while(low<=high){
		int mid = low + (high - low)/2;
		if(asc){
			if(v[mid] == x){
				return mid;
			}
			else if(v[mid]> x){
				high = mid - 1;
			}
			else{
				low = mid + 1;
			}
		}
		else{
			if(v[mid] == x){
				return mid;
			}
			else if(v[mid]< x){
				high = mid - 1;
			}
			else{
				low = mid + 1;
			}
		}
	}
	return -1;
}


void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int pos = getIndex(v);
	//cout<<"pos="<<pos<<endl;
	vector<int> ele(q);
	for(int i=0;i<q;i++){
		cin>>ele[i];
	}
	for(int i=0;i<q;i++){
		if(pos){
			int temp = binary_search(v,ele[i],0,pos-1);
			if(temp!=-1){
				cout<<temp+1<<" ";
			}
		}
		int temp2 = binary_search(v,ele[i],pos,n-1,0);
		if(temp2!=-1){
			cout<<temp2+1;
		}
		cout<<endl;
	}
}

signed main()
{
	//cout<<"___________Biotonic_Array___________\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}