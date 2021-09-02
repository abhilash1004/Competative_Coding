#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+5;
bool sieve[N];
bool isprime[N];
void sievefunc(int n){
	memset(sieve,1,sizeof(sieve));
	sieve[0] = 0;
	sieve[1] = 0;
	for(int i=2;i<=n;i++){
		if(sieve[i]){
			for(int j=i*i;j<=n;j+=i){
				sieve[j] = 0;
			}
		}
	}
	/*cout<<"sieve array: ";
	for(int i=2;i<=n;i++){
		if(sieve[i])
			cout<<i<<" ";
	}
	cout<<endl;*/
}

void findprime_a_to_b(int a,int b){
	memset(isprime,1,sizeof(isprime));
	int n = sqrt(b);
	sievefunc(n);
	for(int i=1;i<n;i++){
		if(sieve[i]){
			int curval = ((a+i-1)/i) * i;
			while(curval<=b){
				isprime[curval-a] = 0;
				if(curval<n && sieve[curval]) 
					isprime[curval-a] = 1;
				curval+=i;
			}
		}
	}
	for(int i=0;i<=(b-a);i++){
		if(isprime[i]){
			cout<<(i+a)<<" ";
		}
	}
	cout<<endl;
}

void solve(){
	int a,b;
	cin>>a>>b;
	findprime_a_to_b(a,b);
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