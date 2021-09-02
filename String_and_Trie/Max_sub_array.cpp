/*
Max XOR Subarray

Time-Limit: 5 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Given an array of integers. find the maximum XOR subarray value in the given array.


Input Format

The first line contains an integer T ( 1 ≤ T ≤ 10), the number of test cases.

The first line of each test case contains 2 space-separated integers N,1 ≤ N ≤ 10^5.

The second line of each test case contains N space-separated integers, 1≤ Ai ≤ 10^5


Output Format

For each test case print the answer in a new line.


Sample Input 1

3
5
1 2 3 4 5
6
7 14 6 8 6 65
5
74 14 5 6 9

Sample Output 1

7
79
78
*/
#include<bits/stdc++.h>
using namespace std;

struct TNode{
    TNode *child[2];
    int cnt;
    TNode(){
        child[0] = child[1] = NULL;
        cnt = 0;
    }
};

struct Trie{
    TNode *root;
    Trie(){
        root = new TNode;
    }
    void insert(int a){
        TNode *cur = root;
        for(int i=31;i>=0;i--){
            int x = (a>>i) & 1;
            if(!cur->child[x]){
                cur->child[x] = new TNode();
            }
            cur = cur->child[x];
            cur->cnt++;
        }
    }
    void del(int a){
        TNode *cur = root;
        for(int i=31;i>=0;i--){
            int x = (a>>i) & 1;
            cur = cur->child[x];
            cur->cnt--;
        }
    }
    int getMax(int a){
        TNode *cur = root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int x = (a>>i) & 1;
            if(x==0){
                if(cur->child[1] && cur->child[1]->cnt){
                    ans = ans | 1<<i;
                    cur = cur->child[1];
                }else{
                    cur = cur->child[0];
                }
            }else{
                if(cur->child[0] && cur->child[0]->cnt){
                    ans = ans | 1<<i;
                    cur = cur->child[0];
                }else{
                    cur = cur->child[1];
                }
            }
        }
        return ans;
    }
};

void solve(){
    Trie bt;
    bt.insert(0);
    int n;
    cin>>n;
    int xori=0,x,ans = 0;
    while(n--){
    	cin>>x;
    	xori ^= x;
    	ans = max(ans,bt.getMax(xori));
    	bt.insert(xori);
    	//cout<<bt.getMax(x)<<endl;
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