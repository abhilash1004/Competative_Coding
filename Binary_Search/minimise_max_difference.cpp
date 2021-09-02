/*
You are given N distinct points on the number line in a sorted 
array A. You can place at most K more points on the 
Line (Integer coordinates only). 
You have to make the maximum separation between any two 
consecutive points in the final configuration as minimum as 
possible. Output this minimal value.  

Note - You can place the points anywhere you like, but you 
cannot place more than one point at the same position on the line. 

Sample Input:
5
5 5
1 2 3 4 5
5 0
2 5 7 8 10
3 2
100 200 230
6 5
1 3 5 7 9 11
6 4
1 4 8 13 19 26

Sample Output:
1
3
34
1
4
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
/*************************
Logic: true if <=x needs <=k points else false
*************************/
bool check(vector<int> v,int k,int x)
{
	int needs = 0;
	for(int i=1;i<v.size();i++){
		int d = v[i] - v[i-1];
		needs += (d+x-1)/x - 1/*(d-1)/x*/ ; // nothing but floor((d-1) / x). this is to know how many points need to be placed to get x difference in between a[i] and a[i-1]
	}
	return needs<=k;
}

int min_max_diff(vector<int> v,int k)
{
	int ans = 0;
	for(int i = 1;i<v.size();i++){
		ans = max(ans,v[i] - v[i-1]);
	}
	int low = 1;
	int high = ans;
	//int ans = ans;
	while(low<=high){
		int mid = low + (high-low) / 2;
		if(check(v,k,mid)){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid + 1;
		}
		//cout<<mid<<" "<<ans<<endl;
	}
	return ans;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	cout<<min_max_diff(v,k)<<endl;
}

signed main()
{
	cout<<"___________Minimise_Max_Difference_Between_Points__________\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}