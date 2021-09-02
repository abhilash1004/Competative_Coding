/**
 * U will be give an array of speeds of different vehicles and their 
 * starting positions are their index values. These vehicles travel 
 * infinite distance and you have to tell no of overtakes happen.
 * 
 * Sample Input:
 * 5
 * 2 4 1 3 5
 * 
 * Sample Output:
 * 3
 * 
 * 
 **/

#include<bits/stdc++.h>
//#define int long long
using namespace std;


int speed[1000001];
int tree[4000005];

int getanswer(int index,int l,int r,int val){
	if(l==r){
		return 0;
	}
	int mid = l + (r-l)/2;
	int ans = 0;
	if(val<=mid){
		ans +=getanswer(2*index,l,mid,val);
		ans += tree[2*index+1];
	}else{
		ans+=getanswer(2*index+1,mid+1,r,val);
	}
	return ans;
}

void addeletotree(int index,int l,int r,int ele){
	if(l==r){
		tree[index]++;
		return;
	}
	int m = l + (r-l)/2;
	if(ele<=m){
		addeletotree(2*index,l,m,ele);
	}else{
		addeletotree(2*index+1,m+1,r,ele);
	}
	tree[index]++; 
}


void solve(){
	int n;
	cin>>n;
	memset(tree,0,sizeof(tree));
	for(int i=0;i<n;i++) cin>>speed[i];
	int N = *max_element(speed,speed+n);
	addeletotree(1,0,N,speed[0]);
	int ans = 0;
	for(int i=1;i<n;i++){
		ans+=getanswer(1,0,N,speed[i]);
		addeletotree(1,0,N,speed[i]);
	}
	cout<<ans<<endl;

	/*int ans2 = 0;
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(speed[j]>speed[i]){
				ans2++;
			}
		}
	}
	cout<<ans2<<endl;*/
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