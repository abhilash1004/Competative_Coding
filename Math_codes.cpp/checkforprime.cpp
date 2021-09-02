#include<bits/stdc++.h>
#define int long long
using namespace std;

bool solve(){
	int n;
	cin>>n;
	if(n<2){
		return 0;
	}
	if(n==2) return 1;
	for(int i=2;i*i<=n;i++){
		if(n%i) continue;
		return 0;
	}	
	return 1;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		if(solve()){
			cout<<"True\n";
		}else{
			cout<<"False\n";
		}
	}
}