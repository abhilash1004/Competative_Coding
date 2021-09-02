/*
Rotate an array by k times in O(n) time and O(1) space excluding 
the given array space.
*/

#include<bits/stdc++.h>
//#define int long long
using namespace std;

void rotate_array(int a[],int n,int k){
	k = k % n;
	int count = 0;
	for(int st = 0;count<n;st++){
		int cur = st;
		int prev = a[st];
		do{
			int next = (cur + k) % n;
			int temp = a[next];
			a[next] = prev;
			prev = temp;
			cur = next;
			count++;
		}while(cur!=st);
	}
}

void solve(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	//rotate_array(a,n,k);
	//Another Method
	{
		k %= n;
		reverse(a,a+n);
		reverse(a,a+k);
		reverse(a+k,a+n);
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
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