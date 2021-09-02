#include<bits/stdc++.h>
#define int long long
using namespace std;

map<char,int> mp;
int n;
string currstr;
vector<string> allpermutations;
void findpermutations(int level=0)
{
	if(level==n)
	{
		allpermutations.push_back(currstr);
		return;
	}
	for(auto i:mp)
	{
		if(i.second)
		{
			currstr.push_back(i.first);
			mp[i.first]--;
			findpermutations(level+1);
			currstr.pop_back();
			mp[i.first]++;
		}
	}
}

void solve(){
	string s;
	cin>>s;
	for(auto i:s)
	{
		mp[i]++;
	}
	n = s.size();
	findpermutations();
	for(auto i:allpermutations)
	{
		cout<<i<<endl;
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