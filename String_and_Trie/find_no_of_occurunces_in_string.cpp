/*
Sample Input:
4
abbabb ab
aaaaaaa a
abbbbabbabab ab
geeksforgeeks eeks

Sample Output
2
7
4
2

*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s,key;
	cin>>s>>key;
	int n = s.length();
	string temp = key + "@" + s;

	int kmp[temp.length()+1];
	kmp[0] = -1;
	int i=0,j=-1;
	while(i<temp.length()){
		while(j!=-1&& temp[i]!=temp[j]) j = kmp[j];
		i++;j++;
		kmp[i] = j;
	}
	/*cout<<0<<"\t";
	for(int i=0;i<temp.length();i++){
		cout<<temp[i]<<"\t";
	}
	cout<<endl;
	for(int i=0;i<=temp.length();i++){
		cout<<kmp[i]<<"\t";
	}
	cout<<endl;*/
	cout<<count(kmp,kmp+(temp.length()+1),key.length())<<endl;
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