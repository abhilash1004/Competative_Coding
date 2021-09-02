#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	for(int i=1;i*i<=n;i++){
		if(n%i)continue;
		if(i!=(n/i))
		cout<<i<<" "<<(n/i)<<" ";
		else{
			cout<<i<<" ";
		}
	}	
	cout<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}