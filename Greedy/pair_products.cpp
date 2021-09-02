/*
Description

You have given an array of n numbers and a positive integer m. Lets define c(i, j) = |ai - aj|.
Your task is to find the product of c(i, j) for all 1 ≤ i < j ≤ n. Since this product can be very large, print it with modulo m.


Input Format

The first line contains two integers n, m (2 ≤ n ≤ 2 x 105, 1 ≤ m ≤ 1000) — number of numbers and modulo.
The second line contains n integers a1, a2, …, an (0 ≤ ai ≤ 109).


Output Format

Output a single integer.


Sample Input 1

2 10
8 5

Sample Output 1

3

Sample Input 2

3 12
1 4 5

Sample Output 2

0

Note

In the first sample, |8 − 5| = 3 ≡ 3 mod 10.
In the second sample, |1 − 4| ⋅ |1 − 5| ⋅ |4 − 5| = 3 ⋅ 4 ⋅ 1 = 12 ≡ 0 mod12.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
Solution: 
Let's consider 2 cases.

1. n ≤ m. Then we can calculate this product directly in O(n2).
2. n > m. Note that there are only m possible remainders under division by m, so 
   some 2 numbers of n have the same remainder. Then their difference 
   is divisible by m, so the entire product is 0 mod m.
   *******
   Pigeon Hole Principle
   *******
*/

void solve(){
	int n,m;
	cin>>n>>m;
	if(n>m)
	{
		cout<<0<<endl;
		return;
	}
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans = 1;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ans = (ans * (abs(a[i]-a[j]))%m)%m;
			/*
			ans= ((ans%m) * (abs(a[i]-a[j]) % m))%m;
			ans %= m;
			*/
		}
	}
	cout<<ans<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	/*int t;
	cin>>t;
	while(t--)*/{
		solve();
	}
}

