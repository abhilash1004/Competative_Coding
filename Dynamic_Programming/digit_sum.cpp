/*
Question Link:
https://atcoder.jp/contests/dp/tasks/dp_s
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int dp[10001][2][2][100];
string l,r;
int d;

int rec(int level,int tl,int tr,int psum){
	//cout<<level<<" "<<tl<<" "<<tr<<" "<<psum<<endl;
	if(level == r.length()){
		if(psum==0){
			return 1;
		}
		return 0;
	}

	if(dp[level][tl][tr][psum]!=-1) return dp[level][tl][tr][psum];

	int lo,hi;
	/*int lo = 0;
	if(tl){lo = l[level] - '0';}*/
	tl?(lo = l[level] - '0'):lo = 0;
	/*int hi = 9;
	if(tr){hi = r[level] - '0';}*/
	tr?(hi = r[level] - '0'):hi = 9;
	int ans =0 ;

	for(int i=lo;i<=hi;i++){
		int ntl = tl,nth = tr;
		if(i!=l[level]-'0') ntl = 0;
		if(i!=r[level]-'0') nth = 0;
		ans += rec(level+1,ntl,nth,(psum + i)%d);
		ans %= mod;
	}
	return dp[level][tl][tr][psum] = ans;
}

void solve(){
	//cin>>l>>r; //Give l input as 1 for this question.(Just generalising the question) 
	l = "1";
	cin>>r;
	cin>>d;
	memset(dp,-1,sizeof(dp));
	int temp = r.length() - l.length();
	string tempstr = "";
	while(temp--){
		tempstr += "0";
	}
	l = tempstr + l;
	//cout<<l<<endl<<r<<endl;
	cout<<rec(0,1,1,0)<<endl;
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