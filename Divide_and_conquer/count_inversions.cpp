#include<bits/stdc++.h>
#define lli long long

using namespace std;

lli count_inversions(lli a[],lli l,lli r){
	if(l>=r){
		return 0;
	}
	lli ans = 0;
	lli m = /*(l+r)/2;*/ l + (r-l)/2;

	

	ans += count_inversions(a,l,m);
	ans += count_inversions(a,m+1,r);

	lli leftSize = m-l+1;
	lli rightSize = r - m;

	lli *left=new lli[leftSize];
	lli *right=new lli[rightSize];

	for(lli i=0;i<leftSize;i++){
		left[i] = a[l+i];
	}

	for(lli i=0;i<rightSize;i++){
		right[i] = a[m+1+i];
	}
	

	lli i = 0,j=0,k=l;
	while(i<leftSize && j<rightSize){
		if(left[i]<=right[j]){
			a[k++]=left[i++];
		}
		else{
			ans += leftSize-i;
			a[k++]=right[j++];
		}
	}
	while(i<leftSize){
		a[k++]=left[i++];
	}
	while(j<rightSize){
		a[k++]=right[j++];
	}
	return ans;
}

void solve(){
	lli n;
	cin>>n;
	lli a[n];
	for(lli i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<count_inversions(a,0,n-1)<<endl;
	
}

int main(int argc, char const *argv[])
{
	cout<<"___________Count_Inversions___________\n";
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	lli t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}