/**
 * Mininum number of characters required to append to a string to 
 * make it a palindrome.
 **/

/*
Sample Input:
8
ab
abc
aba
abede
aabb
deep
sososososos
sosososososo

Sample Output:
1
2
0
2
2
3
0
1
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	//int n=s.size();
	string rev = s;
	reverse(rev.begin(),rev.end());
	string temp = rev + "@" + s;
	int kmp[temp.size()+1];
	int i=0,j=-1;
	kmp[0] = -1;
	while(i<(temp.size()+1)){
		while(j!=-1 && temp[i]!=temp[j]){
			j = kmp[j];
		}
		i++;
		j++;
		kmp[i] = j;
	}
	cout<<(s.size()-kmp[temp.size()])<<endl;

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
