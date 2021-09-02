/*Description

Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?


Input Format

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).


Output Format

Print one integer: the number of ways you can place the queens.


Sample Input 1

........
........
..*.....
........
........
.....**.
...*....
........

Sample Output 1

65*/

#include<bits/stdc++.h>
#define lli long long
using namespace std;

#define n 8

bool chessboard[n][n];
int ans;
vector<int> pos;

bool check(int l,int r)
{
	if(chessboard[l][r])
		return false;
	for(int i=0;i<pos.size();i++)
	{
		if(l==i || r==pos[i] || abs(pos[i]-r)==abs(i-l))
			return false;
	}
	return true;
}

void count_ans(int level)
{
	if(level==n)
	{
		ans++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(check(level,i))
		{
			pos.push_back(i);
			count_ans(level+1);
			pos.pop_back();
		}
	}
}

void solve(){
	char ch;
	ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>ch;
			if(ch=='*')
				chessboard[i][j] = 1;
			else
				chessboard[i][j] = 0;
		}
	}
	count_ans(0);
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