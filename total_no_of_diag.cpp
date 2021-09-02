#include<bits/stdc++.h>
using namespace std;
using lli= long long int;
lli mod= 1e9 + 7;
#define For(i,n) for(int i=0;i<n;i++)

lli powerbinary(lli a, lli b){
	lli ans = 1;
	while(b){
		if(b%2==1){
			ans = ans*a %mod;
		}
		a = a*a % mod;
		b/=2;
	}
	return ans;
}

lli inverse(lli a){
	return powerbinary(a,mod-2);    //n(n-1)/2 - n  
}

void solve(){
	lli n;
	cin >> n;
	//cout << (((n*(n-1)%mod)*(inverse(2)%mod))%mod -(n%mod)) % mod << "\n";
	cout<< (((n%mod) * (n-3)%mod)%mod * (inverse(2))%mod)%mod<<endl;

}

signed main(){
     ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lli t;
    cin>>t;
    //factorial();
    while(t--)
         solve();

}