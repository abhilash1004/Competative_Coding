/*
Description

You have given two positive integers n and k. Your task is to print all balanced parenthesis of length n in lexicographic order (https://en.wikipedia.org/wiki/Lexicographic_order) with depth exactly k. 

Balanced parentheses mean that each opening symbol has a corresponding closing symbol and the pairs of parentheses are properly nested.

Note:

depth("") = 0.
depth('(' + A + ')) = depth(A) + 1, where A is a balanced paranthesis sequence.
depth(A + B) = max(depth(A), depth(B)), where A and B are both balanced paranthesis sequence.
depth("(") = depth(")") = 0

Input Format

The only line of input contains two numbers number n and k.


Output Format

Print all balanced parenthesis of length n with depth k in lexicographic order.


Constraints

2 ≤ n ≤ 24
1 ≤ k ≤ n / 2
It is guaranteed that n is an even number.


Sample Input 1

6 2

Sample Output 1

(()())
(())()
()(())

Sample Input 2

4 2

Sample Output 2

(())
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
int n,k;

void generate(int level=1,int cnt_open_brackets=0,int depth=0,int mdepth=0)
{
	if(level==n)
	{
		assert(cnt_open_brackets==1);
		s.push_back(')');
		if(mdepth==k)
			cout<<s<<endl;
		s.pop_back();
		return;
	}
	if(!cnt_open_brackets)
	{
		s.push_back('(');
		generate(level+1,cnt_open_brackets+1,depth+1,max(mdepth,depth+1));
		s.pop_back();
		return;
	}
	if((n-level)>cnt_open_brackets && cnt_open_brackets < k)
	{
		s.push_back('(');
		generate(level+1,cnt_open_brackets+1,depth+1,max(mdepth,depth+1));
		s.pop_back();
	}
	s.push_back(')');
	generate(level+1,cnt_open_brackets-1,depth-1,max(mdepth,depth-1));
	s.pop_back();
}

void solve(){
	s="";
	cin>>n>>k;
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