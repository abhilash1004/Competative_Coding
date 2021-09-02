#include<bits/stdc++.h>
#define lli long long 

using namespace std;

void solve_query(vector<int> &v){
	string s;
	int num;
	cin>>s;
	//cout<<s<<" ";
	// for(auto i:v){
	// 	cout<<i<<" ";
	// }
	// cout<<endl;
	//cout<<s[0]<<endl;
	switch(s[0]){

		case 'a':
			cin>>num;
			v.push_back(num);
			break;
		case 'r':
			if(v.size()>0){
				// auto it = v.end();
				// it--;
				// v.erase(it);
				v.pop_back();
			}
			break;
		case 'p':
			cin>>num;
			if(v.size()>num){
				cout<<v[num]<<endl;
			}
			else{
				cout<<0<<endl;
			}
			break;
		case 'c':
			v.clear();
	}
}

void solve(){
	lli t;
	cin>>t;
	vector<int> v;
	while(t--){
		solve_query(v);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli t;
	cin>>t;
	while(t--){
		solve();
	}
}