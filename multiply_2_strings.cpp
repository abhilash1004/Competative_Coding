#include<bits/stdc++.h>
//#define int long long
using namespace std;



string multiply(string s1,string s2){
	if(s1.length()>s2.length()){
		swap(s1,s2);
	}
	int i = s1.length()-1;
	string ans = "";
	int _t = s1.length()+s2.length();
	while(_t--){
		ans+="0";
	}
	/*int c = 0,c2 = 0;
	int t1,t2;
	int k1 = ans.length()-1;
	while(i>=0){
		//cout<<ans<<i<<endl;
		int j=s2.length()-1;
		t1 = s1[i] - '0';
		int k2 = k1;
		while(j>=0){
			t2 = s2[j] - '0';
			int temp = c + t1*t2;
			int dig = temp%10;
			c = temp/10;
			int v = ans[k2] - '0';
			v = c2 + v + dig;
			c2 = v/10;
			v %=10;
			ans[k2] = v + '0';
			int tk2 = k2-1;
			while(c2!=0 && tk2>=0){
				int tv = ans[tk2] = '0';
				tv += c2;
				c2 =tv/10;
				ans[tk2] = tv%10 + '0';
				tk2--; 
				cout<<ans<<endl;
			}
			j--;k2--;
		}
		if(c){
			j = s2.length();
			ans[j]=(ans[j]-'0')+ (c+'0');
		}
		i--;k1--;
		cout<<"_____"<<ans<<"\n";
	}
	if(c){
		//cout<<c<<endl;
		ans[0]=(ans[0]-'0')+ (c+'0');
	}*/
	int ik1 = 0,ik2 = 0;
	for(int i=s1.length()-1;i>=0;i--){
		//cout<<ans<<endl;
		int carry = 0;
		int t1 = s1[i] - '0';
		ik2 = 0;
		for(int j=s2.length()-1;j>=0;j--){
			int t2 = s2[j] - '0';
			int tot = t1*t2+carry+(ans[ik1+ik2]-'0');
			carry = tot/10;
			ans[ik1+ik2] = tot % 10 + '0';
			ik2++;
		}
		if(carry>0){
			ans[ik1+ik2] = (ans[ik1+ik2]-'0' + carry) + '0';
		}
		ik1++;
	}
	reverse(ans.begin(),ans.end());
	return ans;
	/*if(c){

	}*/
}
/*void factorial(string s){
	//vector<string> v;
	
}*/
void solve(){
	string n1,n2;
	cin>>n1>>n2;
	cout<<multiply(n1,n2)<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}