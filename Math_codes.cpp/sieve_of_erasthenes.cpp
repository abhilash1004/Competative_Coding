#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
bool sieve[N] = {0};

void solve(){
	memset(sieve,1,sizeof(sieve));
	int n;
	cin>>n;
	sieve[0] = 0;
	sieve[1] = 0;
	for(int i=2;i<=n;i++){
		if(sieve[i]){
			for(int j=i*i;j<=n;j+=i){
				sieve[j] = 0;
			}
		}
	}
	int cnt = 0;
	for(int i=2;i<=n;i++){
		if(sieve[i])
			cnt++;
	}
	cout<<cnt<<endl;
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