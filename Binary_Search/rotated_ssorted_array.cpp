/*Given a rotated sorted array. 
Find the index of the minimum element in the array.
All the elements are distinct.*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int check(const vector<int> &v,int x){
	if(!x) return 0;
	return v[x]<v[0];
}


int getIndex(const vector<int> &v)
{
	int l = 0,h = v.size()-1;
	int ans = 0;
	while(l<=h)
	{
		int m = l + (h-l)/2;
		//cout<<m<<" "<<check(v,m)<<endl;
		if(check(v,m)){
			ans = m;
			h = m - 1;
		}
		else{
			l = m+1;
		}
	}
	//cout<<endl;
	return ans;
}


void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	cout<<getIndex(v)<<"\n";
}

signed main()
{
	cout<<"___________Rotated_Sorted_Array___________\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}