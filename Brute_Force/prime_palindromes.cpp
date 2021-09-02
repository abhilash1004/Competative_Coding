/*
Description

A number which is both a prime number as well as palindrome is called a Prime Palindrome. 151 is a prime as well as a palindrome, hence 151 is a prime palindrome.
Your task is to find the count of Prime Palindromes belonging to the given range [a, b].


Input Format

The only line of input contains two space-separated numbers: a and b.


Output Format

Print the count to Prime Palindromes in-between the range [a, b].


Constraints

2 ≤ a ≤ b ≤ 109


Sample Input 1

5 500

Sample Output 1

12
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a,b;
int ans;

bool isPrime(int num)
{
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0)
			return false;
	}
	return true;
}

bool check(int x)
{
	if(x<a || x>b || !isPrime(x))
	{
		return 0;
	}
	return 1;
}
void generateNums(int lo,int hi,int mul=10){
	int x = hi*mul;
	if(x+lo>b)
		return;
	if(check(x+lo))
	{
		ans++;
		//cout<<x+r<<endl;
	}
	for(int i=0;i<10;i++)
	{
		//generateNums(x+i,r);
		if(check((hi*10+i)*mul + lo))
		{
			ans++;
		}
	}
	for(int i=0;i<10;i++)
	{
		generateNums(lo+i*mul,hi*10+i,mul*10);
	}

}

void solve(){
	cin>>a>>b;
	ans = 0;
	for(int i=a;i<10;i++)
	{
		if(check(i))
		{
			//cout<<i<<endl;
			ans++;
		}
	}
	generateNums(1,1);
	generateNums(3,3);
	generateNums(5,5);
	generateNums(7,7);
	generateNums(9,9);
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