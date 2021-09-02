#include<bits/stdc++.h>
//#define int long long
using namespace std;
vector<int> status,comp_pos;
int n;

void print_vec(vector<int> v)
{
	for(auto i:v)
	{
		if(i==INT_MAX)
		{
			cout<<-1<<" ";
		}
		else
			cout<<i<<" ";
	}
	cout<<endl;
}

void change_min_dist(vector<int> &min_dist,int p)
{
	int t = p+1;
	while(t<n)
	{
		if(status[t])
			break;
		min_dist[t] = min(min_dist[t],abs(comp_pos[t]-comp_pos[p]));
		t++;
	}
	t = p-1;
	while(t>-1)
	{
		if(status[t])
			break;
		min_dist[t] = min(min_dist[t],abs(comp_pos[t]-comp_pos[p]));
		t--;
	}
}

int find_min_set_to_1(vector<int> &min_dist,int &p)
{
	int min = -1;
	for(int i=0;i<n;i++)
	{
		if(status[i])
			continue;
		if(min==-1)
		{
			min = i;
			continue;
		}	
		if(min_dist[min]>min_dist[i])
		{
			min = i;
		}
	}
	p = min;
	int temp = min_dist[min];
	min_dist[min] = INT_MAX;
	status[min] = 1;
	return temp;
}

void solve(){
	cin>>n;
	status.resize(n);
	for(int i=0;i<n;i++)
		cin>>status[i];
	comp_pos.resize(n);
	for(int i=0;i<n;i++)
		cin>>comp_pos[i];
	/*auto cmp = [](const pair<int,int> a,const pair<int,int> b){
		return a.second>b.second;
	};
	priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
	for(int i=0;i<n;i++)
	{
		if(!i && !status[i])
		{

		}
	}*/
	vector<int> min_dist(n,INT_MAX);
	int total_zeros = 0;
	for(int i=0;i<n;i++)
	{
		if(status[i])
			continue;
		total_zeros++;
		/*for(int j=0;j<n;j++)
		{
			if(status[j])
			{
				min_dist[i] = min(min_dist[i],abs(comp_pos[j]-comp_pos[i]));
				break;
			}
		}*/
		int j = i+1;
		while(j<n)
		{
			if(status[j])
			{
				min_dist[i] = min(min_dist[i],abs(comp_pos[j]-comp_pos[i]));
				break;
			}
			j++;
		}
		j = i-1;
		while(j>=0)
		{
			if(status[j])
			{
				min_dist[i] = min(min_dist[i],abs(comp_pos[j]-comp_pos[i]));
				break;
			}
			j--;
		}
	}
	int ans = 0;
	while(total_zeros--)
	{
		int i;
		ans+=find_min_set_to_1(min_dist,i);
		change_min_dist(min_dist,i);
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