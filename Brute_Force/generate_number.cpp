/*
Generate Numbers from L to R such that number should be a special
number.
A number is called special number if it satisfies the below condition:
The difference between adjacent digits is 1.
*/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

string L,R;
vector<string> ans;
string cans;
void generateNums(int level,int tlo,int thi,int prev,bool MSB){
	if(level == R.length()){
		if(cans.length()){
			ans.push_back(cans);
			cout<<cans<<endl;
		}else{
			cout<<0<<endl;
			ans.push_back("0");
		}
		return;
	}
	int lo = 0,hi = 9;
	tlo?lo = L[level]-'0':lo = 0;
	thi?hi = R[level]-'0':hi = 9;
	for(int i=lo;i<=hi;i++){
		int ntl = tlo,nth = thi;
		if(i!=L[level]-'0')ntl = 0;
		if(i!=R[level]-'0')nth = 0;
		if(MSB){
			if(abs(prev-i)!=1) continue;
			cans.push_back((i+'0'));
			generateNums(level+1,ntl,nth,i,MSB);
			cans.pop_back();
		}else{
			if(i){
				cans.push_back((i+'0'));
				generateNums(level+1,ntl,nth,i,1);
				cans.pop_back();
			}else{
				generateNums(level+1,ntl,nth,i,MSB);
			}
		}
	}
}
void solve(){
	cin>>L>>R;
	int diff = R.length()-L.length();
	string temp="";
	while(diff--){
		temp+="0";
	}
	L = temp + L;
	generateNums(0,1,1,0,0);
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