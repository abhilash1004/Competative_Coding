#include<bits/stdc++.h>
#define int long long
using namespace std;

void count_min_near_cost(int a[],int n,int k)
{
	int ans = 0;
	int flag = 1;
	for(int i=1;i<(1<<n);i++)
	{
		int temp = i,p = 0,tans = ~0;
		//tans>>1;
		while(temp)
		{
			//cout<<(temp&1);
			if(temp & 1)
			{
				//
				tans&= a[p];
			}
			temp=temp>>1;
			p++;
		}
		//cout<<endl;
		//cout<<abs(tans-k)<<endl;
		ans = min(abs(tans-k),ans);
		if(flag){
			ans = abs(tans-k);
			flag = 0;
		}

	}
	cout<<ans<<endl;
}


void solve(){
	int n,k;
	cin>>n>>k;
	/*char str[n];
	cin>>str;*/
	//cal_substing(str,n);
	//cout<<"hey\n";
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	count_min_near_cost(a,n,k);

}

signed main()
{
	//cout<<"Hello\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}