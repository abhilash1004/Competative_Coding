/*
Smaple Input:
8
the 
a
there
answer
any
by
bye
their
8
1 the
1 these
1 their
2 their
1 their
2 thaw
2 agfhj
2 the

Sample Output:
YES
NO
YES
Deleted
NO
String Not Present
String Not Present
Deleted
*/

#include<bits/stdc++.h>
using namespace std;

struct TNode{
	int cnt;
	vector<string> wend;
	TNode *child[26];
	TNode(){
		cnt = 0;
		for(int i=0;i<26;i++){
			child[i] = NULL;
		}
	}
};

struct Trie{
	TNode *root;
	Trie(){
		root = new TNode;
	}
	void insert(const string &s);
	bool search(const string &s);
	void del(const string &s);
	bool delUtility(const string &s,TNode *cur,int pos);
};

void Trie::insert(const string &s){
	TNode *cur = root;
	for(int i=0;i<s.size();i++){
		cur->cnt++;
		int x = s[i] - 'a';
		//cout<<x<<endl;
		if(cur->child[x] == NULL){
			//cout<<(char)(x+'a')<<endl;
			cur->child[x] = new TNode;
		}
		cur=cur->child[x];
	}
	cur->wend.push_back(s);
}

bool Trie::delUtility(const string &s,TNode *cur,int pos){
	if(pos==s.size()){
		auto it = cur->wend.begin();
		for(;it!=cur->wend.end();it++){
			if(*it==s){
				break;
			}
		}
		if(it==cur->wend.end()){
			return 0;
		}
		cur->wend.erase(it);
		return 1;
	}	
	int x = s[pos] - 'a';
	cur->cnt--;
	if(!cur->child[x]){
		cur->cnt++;
		return 0;
	}
	if(!delUtility(s,cur->child[x],pos+1)){
		cur->cnt++;
		return 0;
	}
	return 1;	
}

void Trie::del(const string &s){
	if(delUtility(s,root,0)){
		cout<<"Deleted\n";
	}else{
		cout<<"String Not Present\n";
	}
}

bool Trie::search(const string &s){
	TNode *cur = root;
	for(int i=0;i<s.size();i++){
		int x = s[i] - 'a';
		if(!cur->child[x]){
			return 0;
		}
		cur = cur->child[x];
	}
	for(auto str:cur->wend){
		if(str==s){
			return 1;
		}
	}
	return 0;
}



void solve(){
	int n;
	cin>>n;
	//cout<<n<<endl;
	string s;
	Trie tr;
	for(int i=0;i<n;i++){
		cin>>s;
		//cout<<s<<endl;
		tr.insert(s);
	}
	int q;
	cin>>q;
	//cout<<q<<endl;
	while(q--){
		int ch;
		cin>>ch>>s;
		//cin>>s;
		//cout<<s<<endl;
		if(ch==1)
			tr.search(s)?cout<<"YES\n":cout<<"NO\n";
		else if(ch==2)
			tr.del(s);
		//cout<<tr.root->cnt<<endl;
	}
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