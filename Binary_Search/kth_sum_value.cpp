/*
Description

Given two arrays A of size N and B of size M and an integer K. Create a new array C of size N*M consisting of A[i]+B[j] for 1≤i≤N, 1≤j≤M. Find the Kth smallest element in the array C.


Input Format

The first line contains T, the number of test cases (1<=T<=10000).

The first line contains 3 space-separated integer N, M, K where 1<=N<=10^6, 1<=M<=10^6, 1<=K<=N*M.

Next line contains N space-separated integers (0<=Ai<=1e4).

Next line contains M space-separated integers (0<=Bi<=1e4).

Sum of min(N, M) across all test cases<=10^5.


Output Format

For each test case print the Kth smallest element in the array C.


Sample Input 1

1
3 3 6
1 2 3
4 5 6

Sample Output 1

7

Note

Array C -> [1+4,1+5,1+6,2+4,2+5,2+6,3+4,3+5,3+6] -> [5,6,7,6,7,8,7,8,9]
Array C after sorting - [5,6,6,7,7,7,8,8,9]
6th element is 7.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

/*************************
Logic: # of elements in c <=x is >=k then true else false
*************************/
bool check(vector<int> v1,vector<int> v2,int k,int x)
{
	int c = 0;
	for(auto i:v1){
		c = c + upper_bound(v2.begin(),v2.end(),x - i) - v2.begin();
		/*
		Finding number of elements in b are < (x - a[i])
		This finds number of a[i] + b[i] <=x
		*/
	}
	//cout<<c<<" "<<x<<endl;
	return c>=k;
}

int find_kth_min_sum(vector<int> v1,vector<int> v2,int k)
{
	int low = v1[0] + v2[0];
	int high = v1.back()+v2.back();
	int ans = high;
	while(low<=high){
		int mid = low + (high-low) / 2;
		if(check(v1,v2,k,mid)){
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
	int n1,n2,k;
	cin>>n1>>n2>>k;
	vector<int> v1(n1),v2(n2);
	for(int i=0;i<n1;i++){
		cin>>v1[i];
	}
	for(int i=0;i<n2;i++){
		cin>>v2[i];
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if(n1>n2){
		swap(n1,n2);
		swap(v1,v2);
	}
	cout<<find_kth_min_sum(v1,v2,k)<<endl;
}

signed main()
{
	//cout<<"___________Kth_Sum_Value__________\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}