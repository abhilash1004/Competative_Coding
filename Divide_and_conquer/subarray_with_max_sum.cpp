#include <bits/stdc++.h>

#define ll long long

using namespace std;

//Can solve in O(n) or theta(n) using kadane's Algorithm
//This code time complexity:- theta(nlogn). T(n) = 2T(n/2) * theta(n)

int maxi(ll a,ll b,ll c){
	ll temp = max(a,b);
	temp = max(temp,c);
	if(temp == a){
		return 1;
	}
	else if(temp == b)
		return 2;
	else
		return 3;
}

ll contigious_max_sub_array(vector<int> v,int low,int mid,int high,int &ml,int &mh){
	ll lsum = INT_MIN,rsum = INT_MIN,sum = 0;
	ml = mid;
	for(int i=mid;i>=low;i--){
		sum = sum + v[i];
		if(sum>lsum){
			lsum = sum;
			ml = i;
		}
	}
	sum = 0;
	mh = mid + 1;
	for(int i=mid + 1;i<=high;i++){
		sum = sum + v[i];
		if(sum > rsum){
			rsum = sum;
			mh = i;
		}
	}
	return lsum + rsum;
}

ll max_sub_array(vector<int> v,int low,int high,int &ml,int &mh)
{
	if(low == high){
		ml = mh = low;
		return v[low];
	}
	int mid = (low + high)/2;
	int al,ah,bl,bh,cl,ch;
	ll ans1,ans2,ans3;
	ans1 = max_sub_array(v,low,mid,al,ah);
	ans2 = max_sub_array(v,mid+1,high,bl,bh);
	ans3 = contigious_max_sub_array(v,low,mid,high,cl,ch);
	int flag = maxi(ans1,ans2,ans3);
	switch(flag){
		case 1:
			ml = al; mh = ah;
			return ans1;
			break;
		case 2:
			ml = bl; mh = bh;
			return ans2;
			break;
		case 3:
		default:
			ml = cl; mh = ch;
			return ans3;
			break;
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int l,h;
	cout<<"Max Sum = "<<max_sub_array(v,0,n-1,l,h)<<endl;
	cout<<"Sub Array: ";
	for(int i=l;i<=h;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cout<<"subarray_with_max_sum: "<<endl<<endl;
	ll t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}