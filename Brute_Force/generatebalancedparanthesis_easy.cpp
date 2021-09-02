/**
 Description

You have given a positive even integer n. Your task is to print all balanced parenthesis of length n in lexicographic order (https://en.wikipedia.org/wiki/Lexicographic_order). 

Balanced parentheses mean that each opening symbol has a corresponding closing symbol and the pairs of parentheses are properly nested.


Input Format

The only line of input contains a number n.


Output Format

Print all balanced parenthesis of length n in lexicographic order.


Constraints

2 ≤ n ≤ 24
It is guaranteed that n is even.


Sample Input 1

2

Sample Output 1

()

Sample Input 2

4

Sample Output 2

(())
()()

**/

#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
int n;

void generate(int level=1,int cnt_open_brackets=0)
{
	if(level==n)
	{
		assert(cnt_open_brackets==1);
		s.push_back(')');
		cout<<s<<endl;
		s.pop_back();
		return;
	}
	if(!cnt_open_brackets)
	{
		s.push_back('(');
		generate(level+1,cnt_open_brackets+1);
		s.pop_back();
		return;
	}
	if((n-level)>cnt_open_brackets)
	{
		s.push_back('(');
		generate(level+1,cnt_open_brackets+1);
		s.pop_back();
	}
	s.push_back(')');
	generate(level+1,cnt_open_brackets-1);
	s.pop_back();
}

void solve(){
	s="";
	cin>>n;
	generate();
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
