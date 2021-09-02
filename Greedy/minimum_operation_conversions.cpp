/*
Description

You are given a number X, you can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Return the minimum number of operations needed to convert number X to Y.


Input Format

The first line contains an integer T (number of test cases), 1 ≤ T ≤ 10^6.

The next T lines contain 2 space-separated integers X, Y where 1 ≤ X,Y ≤ 10^18.


Output Format

For each test case print the minimum number of operations required in a new line.


Constraints

1 ≤ T ≤ 10^6.
1 ≤ X,Y ≤ 10^18

Sample Input 1

3
10 15
21 14
10 22

Sample Output 1

4
7
7

Note

TEST CASE 1: X=10 Y=15

MOVES : 10 → 9 → 8 → 16 → 15     #Moves = 4
 

TEST CASE 2: X=21 Y =14

MOVES : 21 → 20 → 19 → 18 → 17 → 16 → 15 → 14    # moves = 7
 

TEST CASE 3: X=10 Y=22

MOVES : 10 → 9 → 8 → 7 → 6 → 12 → 11 → 22 # moves = 7
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int min_operations(int x,int y)
{
	if(y<x)
		return (x-y);
	int ans=0;
	while(y>x)
	{
		if(y%2)
		{
			y++;
			ans++;
		}
		y/=2;
		ans++;
	}
	if(y<x)
		ans+=(x-y);
	return ans;
}

void solve(){
	int x,y;
	cin>>x>>y;
	cout<<min_operations(x,y)<<endl;
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
/**
 * Solution:
 * 
 * Hint:
 * Consider the different scenarios of x and y. Clearly , x > y , you can only apply x → x-1 move. So the number of moves then becomes (x-y). But about x<y ? 
 * 
 * Solution Aproach:
 * The greedy approach to this problem would be to consider how to make x from y (instead of y from x ). So the moves become y → y/2 and y → y+1.

	This is due to the fact that we always greedily divide by two. 

	Consider 2 scenarios : 

	For y = even, then if we perform 2 additions and one division, we could instead perform one division and one addition for less operations [(Y+2) / 2 vs Y/2 + 1].

	y → y+1 → y+2 → (y+2)/2= y/2+1

	y → y/2 → y/2+1

	For y=odd   then if we perform 3 additions and one division, we could instead perform 1 addition, 1 division, and 1 addition for less operations [(Y+3) / 2 vs (Y+1) / 2 + 1].

	y → y+1 → y+2 →y+3 → (y+3)/2= (y+1)/2+1

	y → y+1 →(y+1)/2 → (y+1)/2+1

	Clearly, in both cases, we see that dividing by 2  requires a minimum number of steps to reach the same value than the addition of 1.

	Solution Complete Approach:

	Using the above greedy approach, the question can be easily divided into stages.

	If y > x and it is odd then first add 1 to make it even, then divide by 2 and continue.

	If y > x and it is already even, then divide by 2.

	Continue till y <= x

	Then lastly , (x-y) addition moves are required to reach the desired answer,

	EXAMPLE RUN : 

	1

	10 15

	X = 10 Y=15

	15>10 and it is odd

	15 → 16 → 8 # moves = 2

	Now y<x 

	# moves = 2+(10-8) = 4 .
**/