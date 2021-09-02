#include<bits/stdc++.h>
using namespace std;
struct hashi{
	int n;
	vector<list<int>> v;
	hashi(int a){
		n = a;
		v.resize(n);
		///v.assign(n);
	}
	void add(int ele){
		int pos = ele%n;
		v[pos].push_back(ele);
	}
	bool search(int ele){
		int pos = ele%n;
		auto it = find(v[pos].begin(),v[pos].end(),ele);
		return (it!=v[pos].end());
	}
	void print(){
		for(auto it:v){
			if(it.size()){
				for(auto it2:it){
					cout<<it2<<" ";
				}
				cout<<endl;
			}
		}
	}
};
void solve(){
	int size;
	cin>>size;
	hashi h(size);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		h.add(temp);
	}
	//h.print();
	cout<<h.search(10);
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