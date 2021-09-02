#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin>>s;
	cout<<s<<endl;
	n = s.length();
	cout<<n<<endl;
	int kmp[n+1];
	int i=0,j=-1;kmp[0] = -1;
	while(i<n){
		while(j!=-1 && s[i]!=s[j]) { j = kmp[j]; cout<<j<<" "<<i<<endl;}
		i++;j++;
		kmp[i] = j;
	}
	for(int i=0;i<=n;i++) cout<<kmp[i]<<" ";
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