#include<bits/stdc++.h>
#define int long long
using namespace std;

void bruteForce(vector<int> v,int k){
	for(int i=0;i<v.size()-k+1;i++){
		int maxi = v[i];
		for(int j=i+1;j<k+i;j++){
			maxi = max(maxi,v[j]);
		}
		cout<<maxi<<" ";
	}
	cout<<endl;
}

void multiset_sol(vector<int> v, int k){
	multiset<int> mp;
	for(int i=0;i<k;i++){
		mp.insert(v[i]);
	}
	cout<<*(--mp.end())<<" ";
	for(int i=k;i<v.size();i++){
		mp.erase(mp.find(v[i-k]));
		mp.insert(v[i]);
		cout<<*(--mp.end())<<" ";
	}
	cout<<endl;
}
void deque_sol(vector<int> v,int k){
	deque<int> dq;
	for(int i=0;i<v.size();i++){
		if(i>=k){
			if(dq.front()==v[i-k]){
				dq.pop_front();
			}
		}
		while(!dq.empty() && dq.back()<v[i]){
			dq.pop_back();
		}
		dq.push_back(v[i]);
		if(i>=k-1){
			cout<<dq.front()<<" ";
		}
	}
	cout<<endl;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<v.size();i++){
		cin>>v[i];
	}
	cout<<"By Brute Force: \n";
	bruteForce(v,k);
	cout<<"By using multiset: \n";
	multiset_sol(v,k);
	cout<<"By using monotne deque: \n";
	deque_sol(v,k);
}

signed main()
{
	cout<<"___________Max_Elements_In_K_Size_Subarray___________\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	int x = 1;
	while(t--){

		cout<<"\nTestCase "<<x++<<"\n";
		solve();
	}
}
