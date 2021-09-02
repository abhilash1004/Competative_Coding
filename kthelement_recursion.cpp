#include<bits/stdc++.h>
using namespace std;

int findMin(int a[],bool flag[],int n){
	int min = 1e9;
	int pos = -1;
	
	for(int i=0;i<n;i++){
		if(flag[i]==0){
			if(a[i]<min){
				min = a[i];
				pos = i;
			}
		}
	}
	return pos;
}

int kthMini(int a[],bool flag[],int n,int k){
	if(k<1){
		return -1;
	}
	if(k==1){
		int p = findMin(a,flag,n);
		flag[p] = 1;
		return a[p];
	}
	kthMini(a,flag,n,k-1);
	int p = findMin(a,flag,n);
	flag[p] = 1;
	return a[p];
}

signed main()
{
	int n;
	cin>>n;
	int a[n];
	bool flag[n];
	memset(flag,0,sizeof(flag));
	for(int i=0;i<n;i++)
		cin>>a[i];
	int q,k;
	cin>>q;
	while(q--){
		cin>>k;
		cout<<kthMini(a,flag,n,k)<<endl;
		memset(flag,0,sizeof(flag));
	}

}