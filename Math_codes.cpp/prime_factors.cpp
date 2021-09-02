#include<bits/stdc++.h>
#define int long long
using namespace std;
using ii = pair<int,int>;

void solve(){
	int n;
	cin>>n;
	vector<ii> v; 
	//int t = n;
	for(int i=2;i*i<=n;i++){
		if(!(n%i)){
			int cnt = 0;
			while(!(n%i)){
				n = n/i;
				cnt++;
			}
			//cout<<i<<" "<<cnt<<" "<<n<<endl;
			v.push_back({i,cnt});
		}
	}
	if(n>1){
		v.push_back({n,1});
	}
	for(auto i:v){
		cout<<i.first<<"^"<<i.second<<" ";
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