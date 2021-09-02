/*
Description

You are given a list of N intervals. The i-th interval is [li, ri), 
which denotes a range of numbers greater than or equal to li and 
strictly less than ri. 
Find the minimum integer x such that you can select x intervals from 
the given N intervals so that the union of the selected intervals is [0, L).


Input Format

The first line contains two integers N (1 ≤ N ≤ 2×105) and 
L (1 ≤ L ≤ 1012), where N is the number of 
intervals and L is the length of the range to be covered, respectively. 
The i-th of the following N lines contains two integers li 
and ri (0 ≤ li < ri ≤ L), representing the range of the i-th interval [li, ri). 
You can assume that the union of all the N intervals is [0, L).


Output Format

Output integer x mentioned in the problem statement.


Constraints

1 ≤ N ≤ 2×10^5
1 ≤ L ≤ 10^12
0 ≤ li < ri ≤ L

Sample Input 1

5 8
0 4
5 8
2 5
3 6
3 8

Sample Output 1

2

Sample Input 2

5 4
0 2
2 4
0 3
1 3
3 4

Sample Output 2

2

Sample Input 3

2 4
0 4
0 4

Sample Output 3

1

Note

For Testcase 1:

Consider the interval from 0 to 8. There are 5 different intervals given . 

The intervals which on union give the interval [0,8) are

1.  [0,4) U [3,6) U [5,8)

2.  [0,4) U [3,8)

3.  [0,4) U [2,5) U [5,8)

Clearly, the minimum number of intervals required to cover the 
complete intervals is 2 i.e. intervals [0,4) and [3,8). So the output is 2.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	if ((a.second - a.first) > (b.second - b.first))
	{
		return true;
	}
	else if((a.second - a.first) == (b.second - b.first))
	{
		return a.first < b.first;
	}
	return false;
}

void solve(){
	int n,x;
	//cout<<"Hi: ";
	cin>>n>>x;
	vector<pair<int,int>> points(n);
	for(int i=0;i<n;i++)
	{
		int _t1,_t2;
		cin>>_t1>>_t2;
		points[i] = {_t1,_t2};
	}

	map<int,int> mp;
	for(auto it:points)
	{
		mp[it.first] = max(mp[it.first],it.second);
	}
	int last = 0,maxi=0,ans = 0;
	for(auto it:mp)
	{
		if(it.first == last)
		{
			maxi = max(maxi,it.second);
			last = maxi;
			ans++;
		}
		else if(it.first>last)
		{
			ans++;
			last = maxi;
		}
		maxi = max(maxi,it.second);

	}
	if(last<x)
	{
		ans++;
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

/*
**********Solution:
This problem utilizes the sweep-line technique. The sweep line is dragged along the entire number line. At each point of the number line, the count of the minimum number of intervals that cover all regions upto that point is maintained. This process is continued until the end of the number line is reached, and the value of count gives the desired answer.


EXAMPLE RUN :  

Intervals are given as [L,R)

6 8

0 2

0 4

5 8

2 5

3 6

3 8

There are 6 intervals given, and the length is L=8

Sort all the intervals : [0,2)[0,4) [2,5) [3,6) [3,8) [5,8)

Initially, covered point c is 0. So the first interval with L>c is [2,5). Till here, we take the interval that covers maximum distance, including start=0 i.e., interval [0,4), and the count of the interval is 1.

Points covered till now are c=4. Again take the first interval with L>c i.e.[5,8). In between, take the interval that covers maximum distance after [0,4) and starts before or at 4. Here such an interval is [3,8). Again count of interval increments by now.

The points covered till now are 8 which is the length of the total number line. So the value of count = 2 is the minimum number of intervals required. The intervals are [0,4) and [3,8).

TIME COMPLEXITY: O(NlogN)
*/