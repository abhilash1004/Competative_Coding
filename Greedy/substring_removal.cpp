/*
Description

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.

For example, when removing "ab" from "cabxbae" it becomes "cxbae".

Remove substring "ba" and gain y points.

For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.


Input Format

The first line contains an integer T (number of test cases), 1 ≤ T ≤ 10^5.

The next T lines contain a string S and 2 space-separated integers S, X, Y where 1 ≤ X,Y ≤ 10^9, 1 ≤ |S| ≤ 10^6.

Sum of |S| across all test cases ≤ 10^7.


Output Format

For each test case print the maximum point possible in a new line.


Constraints

1 ≤ T ≤ 10^5
1 ≤ X,Y ≤ 10^9
1 ≤ |S| ≤ 10^5.
Sum of |S| across all test cases ≤ 10^6.

Sample Input 1

4
abdsbab 23 50
babababa 45 32
ujaabba 4 5
cxbaeab 17 9

Sample Output 1

73
167
9
26

Sample Input 2

20
ab 7 4
aaba 10 8
baba 6 4
ba 4 8
baabbbb 5 6
aaabab 1 7
babaaba 8 10
b 1 8
abbaaa 2 7
b 5 6
aa 7 4
bbbaa 8 4
bbbba 7 6
babba 8 7
bababbab 3 1
baa 6 9
babbba 3 6
aa 9 2
baababaaba 10 8
bbbbbbaab 3 6

Sample Output 2

7
10
10
8
11
8
30
0
14
0
0
8
6
15
9
9
12
0
38
12

Note

For the first sample input:

TEST CASE 1: 

S = abdsbab x=23  y=50

Remove “ba”  Points = 50 S =  “abdsb”.
Remove “ab”  Points = 50+23 = 73 S =  “dsb”.
Nothing else to remove ,  so total points is 73.


 

TEST CASE 2: 

S = babababa x=45  y=32

Remove “ab”  Points = 45 S =  “bababa”.
Remove “ab”  Points = 45+45 = 90 S =  “baba”
      3.   Remove “ab”  Points = 90+45 = 135 S =  “ba”

      4.   Remove “ba”  Points = 135+32 = 167 S = “ ”


 

Nothing else to remove ,  so total points is 167.


 

TEST CASE 3. 

S = ujaabba x=4  y=5

Remove “ba”  Points = 5 S =  “ujaab”.
Remove “ab”  Points = 5+4 = 9 S =  “uja”
      

Nothing else to remove ,  so total points is 9.

 

TEST CASE 4. 

S = cxbaeab x=17  y=9

Remove “ab”  Points = 17 S =  “cxbae”.
Remove “ba”  Points = 17+9 = 26 S =  “cxe”
Nothing else to remove ,  so total points is 26
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

/*void solve(){
	string str;
	int x,y;
	cin>>str>>x>>y;
	string s1 = "ab",s2 = "ba";
	if(y >  x)
	{
		swap(s1,s2);
		swap(x,y);
	}
	int ans = 0;
	int i=0;
	while(str.size() && i<str.size()-1)
	{
		//cout<<"1:"<<i<<str<<endl;
		if(str[i]==s1[0] && str[i+1]==s1[1])
		{
			str.erase(str.begin()+i,str.begin()+i+2);
			ans+=x;
			if(i)
				i--;
			continue;
		}
		i++;
	}
	i=0;
	while(str.size() && i<str.size()-1)
	{
		//cout<<"2:"<<i<<str<<endl;
		if(str[i]==s2[0] && str[i+1]==s2[1])
		{
			str.erase(str.begin()+i,str.begin()+i+2);
			//cout<<str<<endl;
			ans+=y;
			if(i)
				i--;
			continue;
		}
		i++;
	}
	cout<<ans<<endl;
}*/

void solve()
{
	string str;
	int x,y;
	cin>>str>>x>>y;
	string s1 = "ab",s2 = "ba";
	if(y >  x)
	{
		swap(s1,s2);
		swap(x,y);
	}
	int ans = 0;
	for(int i=0;(i+1)<str.size();i++)
	{
		while((i+1)<str.size() && str[i]==s1[0] && str[i+1]==s1[1]){
			str.erase(str.begin()+i,str.begin()+i+2);
			ans+=x;
			if(i)
			i--;
		}
		//cout<<i<<str<<endl;
	}
	for(int i=0;(i+1)<str.size();i++)
	{
		while((i+1)<str.size() && str[i]==s2[0] && str[i+1]==s2[1]){
			str.erase(str.begin()+i,str.begin()+i+2);
			ans+=y;
			i--;
		}
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