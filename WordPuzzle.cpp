#include<bits/stdc++.h>
using namespace std;

int n;
string word;
string ans,temp;
vector<vector<char>> v;
vector<vector<bool>> vis;
vector<pair<int,int>> vp;

int dx[] ={0,0,1,-1};
int dy[] ={1,-1,0,0};

bool check(int l,int r,int level){
	if(l>=0&&r>=0&&l<n&&r<n&&v[l][r]==word[level]&&!vis[l][r]){
		return 1;
	}
	return 0;
}

bool dfs(int l,int r,int level)
{
	if(level==word.size()){
		cout<<"yes "<<ans<<endl;
		return 1;
	}
	bool fnd = 0;
	vis[l][r] = 1;
	for(int i=0;i<4;i++){
		int nx=l+dx[i];
		int ny=r+dy[i];
		if(check(nx,ny,level)){
			ans.push_back((nx+1+'0'));
			ans.push_back((ny+1+'0'));
			fnd = dfs(nx,ny,level+1);
			ans.pop_back();
			ans.pop_back();
		}
		if(fnd){
			return 1;
		}
	}
	vis[l][r] = 0;
	return 0;
}

int main()
{
	cin>>n;
	cin>>word;
	v.resize(n);
	vis.resize(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch;
			v[i].push_back(ch);
			vis[i].push_back(0);
			if(word[0]==ch){
				vp.push_back({i,j});
			}
		}
	}
	bool fnd = 0;
	for(auto p:vp){
		int a = p.first;
		int b = p.second;
		if(check(a,b,0)){
			ans.push_back((a+1+'0'));
			ans.push_back((b+1+'0'));
			fnd = dfs(a,b,1);
			ans.pop_back();
			ans.pop_back();
			if(fnd){
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;


}