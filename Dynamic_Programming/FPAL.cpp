/*
//Infosys Exam Question
Andy has created a string "FPAL" for describing a string.
A string is called FPAL according to ANDY, if it doesn't contain a 
palindrome with a length greater than 1 as a substring.

For example: The string representation 4579 is an FPAL where as the 
string representation of the number 15668 is not an FPAL because 
it has palindrome 66.

Your task is to calculate the total no of FPAL numbers in given range.

Input Format:
L //Left Interger
R //Right Integer
//[L R]
Ouput Format:
Answer

Constraints:
1<=L<=R<=10^18


Smaple Input:
123
321

Sample Output:
153

Smaple Input 2:
123456789
987654321

Sample Output 2:
167386971

Smaple Input 3:
2
101

Sample Output 3:
89
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[19][2][2][10][10][19];
string L,R;
//string str="";
int Llen;
bool check(int l,int v,int pv1,int pv2,bool isMSB,int MSB){
	if(!isMSB && v==0) return 1;
	if(l<1) return 1;
	if(l<2 && v!=pv1) return 1;
	if(isMSB){
		if(v==0 && l==MSB){
			return 1;
		}
	} 
	if(pv1!=v && pv2!=v) return 1;
	return 0;
}

int rec(int level,int tlo,int thi,int pv1,int pv2,int MSB=0){
	if(level == R.length()){
		//cout<<str<<"\n";//<<MSB<<" "<<pv1<<" "<<pv2<<endl;
		return 1;
	}
	if(dp[level][tlo][thi][pv1][pv2][MSB]!=-1) return dp[level][tlo][thi][pv1][pv2][MSB];
	int lo,hi;
	tlo?(lo = L[level] - '0'):lo = 0;
	thi?(hi = R[level] - '0'):hi = 9;
	int ans = 0;
	for(int i=lo;i<=hi;i++){
		if(!check(level,i,pv1,pv2,MSB!=0,MSB))continue;
		int ntl = tlo,nth = thi;
		if(i!=L[level]-'0') ntl = 0;
		if(i!=R[level]-'0') nth = 0;
		//str+=(i+'0');
		if(!MSB && i) ans+= rec(level+1,ntl,nth,i,pv1,level+1);
		else ans+= rec(level+1,ntl,nth,i,pv1,MSB);
		//str.pop_back();
	}
	return dp[level][tlo][thi][pv1][pv2][MSB]=ans;
}

void solve(){
	cin>>L>>R;
	Llen = L.length();
	int diff = R.length() - L.length();
	string temp ="";
	while(diff--){ temp+="0";}
	L = temp + L;
	memset(dp,-1,sizeof(dp));
	//cout<<L<<" "<<R<<endl;
	cout<<rec(0,1,1,0,0)<<endl;
	//cout<<check(2,0,1,0,1,1);
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