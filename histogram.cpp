#include<bits/stdc++.h>
using namespace std;

signed main(){
	int p,m;
	cin>>p>>m;
	vector<vector<int>> A(p),arr;
	for(int i=0;i<p;i++){
		for(int j=0;j<p;j++){
			int temp;
			cin>>temp;
			A[i].push_back(temp);
		}
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		vector<int> _t;
		_t.push_back(a);
		_t.push_back(b);
		arr.push_back(_t);
	}


	vector<int> hist;
	for(int i=0;i<p;i++){
		int sum = 0;
		for(int j=0;j<p;j++){
			sum+=A[j][i];
		}
		hist.push_back(sum);
	}
	/*for(auto i:hist){
		cout<<i<<" ";
	}
	cout<<"\n";*/
	vector<int> ans;
	for(int v=0;v<m;v++){
		
		
		/*for(int i=0;i<hist.size();i++){
			if(hist[i]==arr[v][0]){
				hist[i] = arr[v][1];
			}
		}*/
		for(auto &i:hist){
			if(i==arr[v][0]){
				i = arr[v][1];
			}
		}
		int temp=0;
		for(int i=0;i<hist.size()-1;i++){
			temp+=abs( hist[i]-hist[i+1]);
		}
		
		//cout<<temp<<endl;
		ans.push_back(temp);
	}
	for(auto i:ans){
		cout<<i<<"\n";
	}
	// for(int i=0;i<m;i++){
	// 	cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
	// }
}