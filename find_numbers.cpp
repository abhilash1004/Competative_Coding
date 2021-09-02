#include<bits/stdc++.h>
//#define int long long
using namespace std;
vector<int> arr;
bool getAns(int level,int r,int rsum,int k){
	if(k==0){
		if(rsum == 0)
			return 1;
		return 0;
	}
	if(level>=r){
		return 0;
	}
	return(getAns(level,r,rsum-arr[level],k-1) | getAns(level+1,r,rsum-arr[level],k-1) | getAns(level +1,r,rsum,k));
}

void solve(){
	int n=3000;
	//cin>>n;
	arr.resize(n);
	for(int i=0;i<3000;i++) {
		if(i%2){
			arr[i] = 1;
		}else{
			arr[i] = -1;
		}
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	for(int i=1;i<n;i++){
		if(getAns(0,i,arr[i],3)) ans++;
		//cout<<ans<<" ";
	}
	cout<<ans<<endl;
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