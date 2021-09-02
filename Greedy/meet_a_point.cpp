/*
Description

There are n friends in a 2D plane who want to meet at some common point. Each of their position is given to you as x & y coordinates.

 The distance a person covers to go from position (x1 , y1) to (x2 , y2) is the manhattan distance i.e. |x1-x2| + |y1-y2|.

They choose the meeting point such that the sum of distances covered by each of them to reach it is minimum. Find this minimum sum of distances.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n.

Each of the next n lines contain two integers x y.

 


Output Format

For each test case output one integer: The minimum sum of distances covered by them.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ x,y ≤ 106


Sample Input 1

1

3

0 4

4 0

2 2


Sample Output 1

8


Note

Point (2,2) is the optimal meeting point in this case.
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

/**
 * Solution:
 * The point of meeting is median. 
 * To Understand why to take a median than mean consider a 1d array and check
**/

void solve(){
	int n;
	cin>>n;
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	int mx,my;
	int m = (n-1)/2;
	mx = x[m];
	my = y[m];
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		ans+= (abs(x[i]-mx) + abs(y[i]-my));
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