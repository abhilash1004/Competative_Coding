#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int sp[N];

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		sp[i] = i;
	}
	//Using sieve
	for(int i=2;i<=n;i++){
		if(sp[i]==i){
			for(int j=i*i;j<=n;j+=i){
				if(sp[j]==j){
					sp[j] = i;
				}
			}
		}
	}

	int q;
	cin>>q;
	//cout<<"n ="<<n<<" q="<<q<<endl;
	while(q--){
		int p;
		cin>>p;
		while(p>1){
			cout<<sp[p]<<" ";
			p/=sp[p];
		}
		cout<<endl;
	}
	
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