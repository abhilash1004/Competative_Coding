/*
Rearrange Marbles

Time-Limit: 2 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given N1 indistinguishable marbles of green colour and N2 indistinguishable marbles of red colour. You have to find the number of arrangements such that no more than K1 consecutive marbles of green colour and no more than K2 consecutive marbles of red colour are adjacent to each other.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first and only line of each test case contains four space-separated integers N1, N2, K1, K2.


Output Format

For each test case, print the required number of arrangements. Since the answer can be large, print it modulo 108.


Constraints

1≤ T ≤ 1000

1≤ N1, N2 ≤ 100

1≤ K1, K2 ≤ 10


Sample Input 1

3
2 2 1 5
2 4 1 2
3 5 2 1

Sample Output 1

3
5
0

Note

For the first test case, the following are the 3 different arrangements possible:




For the second test case, the following are the 5 different arrangements possible:






For the third test case, there are no arrangements possible.
*/
// #include<bits/stdc++.h>
// #define int long long
// using namespace std;

// const int mod = 1e8;
// //int dp[101][101][11][11];
// int dp[101][101][2][11];
// int n1,n2,k1,k2;

// /*int rec(int pn1,int pn2,int cnt1,int cnt2)
// {
// 	//int pn2 = level - pn1;
// 	if(pn1>n1 && pn2>n2)
// 	{
// 		return 0;
// 	}
// 	if(pn1==n1  && pn2==n2)
// 	{
// 		return 1;
// 	}
// 	if(dp[pn1][pn2][cnt1][cnt2]!=-1)
// 		return dp[pn1][pn2][cnt1][cnt2];
// 	int ans = 0;
// 	if(cnt1<k1 && pn1<n1)
// 		ans += (rec(pn1+1,pn2,cnt1+1,0)%mod);
// 	if(cnt2<k2 && pn2<n2)
// 		ans += (rec(pn1,pn2+1,0,cnt2+1)%mod);
// 	return dp[pn1][pn2][cnt1][cnt2]=(ans%mod);
// }*/

// int rec(int pn1,int pn2,int prev,int cnt)
// {
// 	if(pn1>n1 || pn2>n2)
// 	{
// 		return 0;
// 	}
// 	if(pn1==n1  && pn2==n2)
// 	{
// 		return 1;
// 	}
// 	if(dp[pn1][pn2][prev][cnt]!=-1)
// 	{
// 		return dp[pn1][pn2][prev][cnt];
// 	}
// 	int ans = 0;
// 	if(!prev)
// 	{
// 		ans += rec(pn1,pn2+1,1,1);
// 		if(cnt < k1)
// 		{
// 			ans += (rec(pn1+1,pn2,0,cnt+1)%mod);
// 		}
// 	}
// 	else{
// 		ans += rec(pn1+1,pn2,0,1);
// 		if(cnt < k2)
// 		{
// 			ans += (rec(pn1,pn2+1,1,cnt+1)%mod);
// 		}
// 	}
// 	return dp[pn1][pn2][prev][cnt] = (ans%mod);
// }


// void solve(){
// 	memset(dp,-1,sizeof(dp));
// 	cin>>n1>>n2>>k1>>k2;
// 	//cout<<rec(0,0,0,0)<<endl;
// 	cout<<(rec(1,0,0,1)%mod + rec(0,1,1,1)%mod)%mod<<endl;
// }

// signed main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);cout.tie(0);
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		solve();
// 	}
// }

//Another Solution
#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int mod = 1e8;
int n1,n2,k1,k2;
int dp[101][101][2];

int rec(int rn1,int rn2,int prev)
{
	if(rn1==0 && rn2==0)
		return 1;
	if(dp[rn1][rn2][prev]!=-1)
		return dp[rn1][rn2][prev];
	int ans = 0;
	if(prev == 0)
	{
		for(int i=1;i<=min(rn1,k1);i++)
		{
			ans = (ans + rec(rn1-i,rn2,1-prev))%mod;  
		}
	}
	else
	{
		for(int i=1;i<=min(rn2,k2);i++)
		{
			ans = (ans + rec(rn1,rn2-i,1-prev))%mod;
		}
	}
	return dp[rn1][rn2][prev] = ans;
}

void solve(){
	cin>>n1>>n2>>k1>>k2;
	memset(dp,-1,sizeof(dp));
	cout<<(rec(n1,n2,0) + rec(n1,n2,1))%mod<<endl;
	//cout<<"Hello";
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