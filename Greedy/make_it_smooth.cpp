/*
You are given an array A of size N. In one operation you can select any non-decreasing subarray and increment all the elements in the subarray by one. Your goal is to make the whole array non-decreasing in minimum operations.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n.

Next line contains n integers of array A.

 


Output Format

For each test case print a single integer in a new line: Minimum number of operations.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ Ai ≤ 109


Sample Input 1

2

4

5 3 2 5

3

1 1 1


Sample Output 1

3

0
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

/*void solve(){
	int n,ele=0,pele;
	cin>>n;
	int ans = 0,pans=0;
	for(int i=0;i<n;i++)
	{
		if(!i)
		{
			cin>>pele;
			continue;
		}
		cin>>ele;
		if(ele<pele)
		{
			ans = max(ans,(pele - ele)+pans);
			pans = (pele - ele)+pans;
			pele = ele;
			continue;
		}
		pans = 0;
		pele = ele;
	}
	cout<<ans<<endl;
}*/
void solve(){
	int n,ele=0,pele;
	cin>>n;
	int ans = 0,pans=0;
	for(int i=0;i<n;i++)
	{
		if(!i)
		{
			cin>>pele;
			continue;
		}
		cin>>ele;
		if(ele<pele)
		{
			ans += pele - ele;
		}
		pele = ele;
	}
	cout<<ans<<endl;
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