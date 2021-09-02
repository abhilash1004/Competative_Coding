#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int data;
	int height;
	node *left;
	node *right;
	node(){
		data=0;
		height = 1;
		left = right = NULL;
	}
	node(int a){
		data=a;
		height = 1;
		left = right = NULL;
	}
	
	//void insert
};

struct AVLTree{
	node *root;
	AVLTree(){
		root=NULL;
	}
	void printLO(){
		queue<node*> q;
		if(root)
			q.push(root);
		while(!q.empty()){
			node *cur = q.front();
			q.pop();
			if(!cur){
				cout<<"N ";
				continue;
			}
			cout<<"("<<cur->data<<" "<<getBalance(cur)<<")"<<" ";

			//if(cur->left)
				q.push(cur->left);
			//if(cur->right)
				q.push(cur->right);
		}
		cout<<endl;
	}
	int getBalance(node *cur){
		if(!cur){
			return 0;
		}
		return height(cur->left) - height(cur->right);

	}
	node* addNode(node* cur,node* elen){
		if(!cur){
			return elen;
		}
		if(elen->data<cur->data){
			cur->left = addNode(cur->left,elen);
		}else if(elen->data>cur->data){
			cur->right = addNode(cur->right,elen);
		}
		cur->height = max(height(cur->right),height(cur->left))+1;
		int bal = height(cur->left) - height(cur->right);
		if(bal>1 && elen->data < cur->left->data){	//Leftleft
			//cout<<cur->data<<"LL"<<elen->data<<endl;
			return rightrotate(cur);
		}else if(bal > 1 && elen->data > cur->data){ //LeftRight
			//cout<<cur->data<<"LR"<<elen->data<<endl;
			cur->left = leftrotate(cur->left->left);
			return rightrotate(cur);
		}else if(bal < -1 && elen->data > cur->right->data){	//Right Right
			//cout<<cur->data<<"RR"<<elen->data<<endl;
			return leftrotate(cur);
		}else if(bal < -1 && elen->data < cur->right->data){	//Right Left
			//cout<<cur->data<<"RL"<<elen->data<<endl;
			cur->right = rightrotate(cur->right);
			return leftrotate(cur);
		}
		return cur;
	}
	void insert(int ele){
		node *temp = new node(ele);
		if(!root){ ///This if is not required
			root = temp;
			return;
		}
		root = addNode(root,temp);
	}
	int height(node* n){
		if(!n){
			return 0;
		}
		return n->height;
	}

	node* leftrotate(node *x){
		node *y = x->right;
		node *yl = y->left;
		y->left = x;
		x->right = yl;
		x->height = max(height(x->right),height(x->left))+1;
		y->height = max(height(y->right),height(y->left))+1;
		return y;
	}

	node* rightrotate(node *x){
		node *y = x->left;
		node *yr = y->right;
		y->right = x;
		x->left = yr;
		x->height = max(height(x->right),height(x->left))+1;
		y->height = max(height(y->right),height(y->left))+1;
		return y;
	}
};

void solve(){
	int n,temp;
	AVLTree tree;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		tree.insert(temp);
	}
	tree.printLO();
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