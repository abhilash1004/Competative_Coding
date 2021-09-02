/*You have given a grid of N x M. 
You are initially at position A(0, 0) and you want to reach B(N, M). From the given cell (i, j), we are allowed to move to cells (i + 1, j) and (i, j + 1) only.
Find the number of different ways to reach B from A?
 */

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9 + 7;
int fact[2000020] = {0};
int ___fact_flag = 1;

int power(int a,int b,int p) //Here p is primary mod number
{
	int ans = 1;
	while(b){
		if(b&1 == 1)	
		{
			ans = ans * a % p;
		}
		a = a * a % p;
		b/=2;
	}
	return ans;
}

int factorial(int a){
	fact[0] = 1;
	if(fact[a] == 0)
	{	
		for(int i = ___fact_flag;i<=a;i++){
			fact[i] = ((i%mod) * fact[i-1])%mod;
		}
		___fact_flag = a+1;
	}
	return fact[a];
}

int mod_inverse(int num){
	return power(num,mod-2,mod);
}

int combination(int n,int r){
	int a = factorial(n);
	int b = factorial(r);
	int c = factorial(n-r);
	/*return (((factorial(n) * mod_inverse(factorial(r)))%mod) * 
									mod_inverse(factorial(n-r)) )%mod;*/
	return ((a * (mod_inverse(b)%mod))%mod * (mod_inverse(c)%mod)) %mod;
}

void solve(){
	int n,m;
	cin>>n>>m;
	cout<<combination(n+m,m)<<endl;
}

signed main()
{
	cout<<"___________Total_No_Of_Ways_To_Reach_Dest___________\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	// cout<<factorial(10)<<endl;
	// cout<<power(3,mod-2,mod)<<endl<<mod-2<<endl;
	// cout<<combination(5,2);
	return 0;
}