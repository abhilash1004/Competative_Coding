/*
Description

We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit time to paint 1 unit of the board. The problem is to find the minimum time to get
this job done under the constraints that any painter will only paint continuous sections of boards.

Note:

2 painters cannot share a board to paint. A board cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. If a painter paints board 1 and 3 but not 2 is invalid.

Input Format

The first line contains a single integer T (1 ≤ T ≤ 100000) - the number of test cases.

The first line of each test case contains 2 space-separated integers N, K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100000) - the number of boards and the number of painters.

The second line of each test case contains N space-separated integers (0 ≤ xi ≤ 10^9) - the length of the boards.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the minimum time required to complete the painting in a new line.


Sample Input 

5
5 2
1 2 3 4 5
5 3
2 5 7 2 5
5 1
1 2 3 4 5
5 5
1 2 3 4 5
5 4
1 7 2 3 5

Sample Output 

9
7
15
5
7
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

/*************************
Logic: Paint n walls with <= k painters in <=x time. so for x time it is true if we need <=k painters else false
*************************/

bool check(vector<int> v,int k,int x)
{
	int req = 0;
	int cap = 0;
	for(auto i:v){
		if(i <= cap){
			cap -= i;
		}
		else{
			if(x<i){
				return 0;
			}
			req++;
			cap = x - i;
		}
	}
	return req<=k;
}

int find_max_time(vector<int> v,int k)
{
	int high = INT_MAX;
	for(auto i:v){
		high += i;
	}
	int low = *max_element(v.begin(), v.end());
	//int high = 1e18;
	int ans = high;
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
	cout<<find_max_time(v,k)<<endl;
}

signed main()
{
	cout<<"___________Painter_Partition__________\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}