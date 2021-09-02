#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int ans = 0;

int rec(int l,int r,string s){
	if(l>r){
		return 1;
	}
	if(dp[l][r] != -1)return dp[l][r];
	if(l==r){
		return dp[l][r] = 1;
	}
	int cans=0;
	if(s[l]==s[r] && rec(l+1,r-1,s)){
		ans = max(ans,r-l+1);
		cans = 1;
	}else{
		rec(l+1,r,s);
		rec(l,r-1,s);
	}
	return dp[l][r] = cans;
}

signed main(){
	string s;
	cin>>s;
	//cout<<s;
	memset(dp,-1,sizeof(dp));
	rec(0,s.length()-1,s);
	/*for(int i=0;i<s.length();i++){
		for(int j=0;j<s.length();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<ans;
}