//Check this question in geekforgeeks for testcases
#include<bits/stdc++.h>
using namespace std;


vector<int> nums;
string s;
int flag = 0;

bool check()
{
	int n = nums.size();
	if(n<3)
		return false;
	for(int i=n-1;i>1;i--)
	{
		if(nums[i] != nums[i-1] + nums[i-2])
		{
			return false;
		}
	}
	return true;
}

int getNum(int l,int r)
{
	string temp="";
	int n = s.size();
	if(l<n && r<n && l<=r)
	{
		for(int i=l;i<=r;i++)
			temp+=s[i];
	}
	else
	{
		return -1;
	}
	return stoi(temp);
}


void checkForSolution(int pos,int n,int previousLength)
{
	if(flag)
		return;
	if(pos==n)
	{
		if(check())
		{
			flag = 1;
			cout<<"Yes"<<endl;
			for(auto i:nums)
				cout<<i<<" ";
			cout<<endl;
		}
		return;
	}
	for(int i = pos ;i<n;i++)
	{
		int x = getNum(pos,i);
		if(x!=-1)
		{
			nums.push_back(x);
			checkForSolution(i+1,n,(i-pos+1));
			nums.pop_back();
		}
	}
}

void solve(){
	cin>>s;
	checkForSolution(0,s.size(),0);
	if(!flag)
	{
		cout<<"No"<<endl;
	}
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