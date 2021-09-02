#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i], a[i] = a[i]*a[i];
	int l = 0,r = n-1,i=0;
	while(i<n){
		if(a[l]>a[r]){
			//swap(a[l],a[r]);
			
			cout<<a[r]<<" ";
			r--;
		}
		else{
			cout<<a[l]<<" ";
			//r--;
			l++;
		}
		i++;
	}
	//for(int i=0;i<n;i++) cout<<a[i]<<" ";

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