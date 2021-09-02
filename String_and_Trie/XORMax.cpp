/*
XORMax

Time-Limit: 5 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given q queries and a multiset A, initially containing only integer 0. There are three types of queries:

"+ x" — add integer x to multiset A.

"- x" — erase one occurrence of integer x from multiset A. It's guaranteed that at least one x is present in the multiset A before this query.

"? x" — you are given integer x and need to compute the value , i.e. the maximum value of bitwise exclusive OR (also know as XOR) of integer x and some integer y from the multiset A.


Input Format

First line contains an integer q, 1 ≤ q ≤ 10^5.

Each of the following q lines of the input contains one of three characters '+', '-' or '?' and an integer xi (1 ≤ xi ≤ 109). It's guaranteed that there is at least one query of the third type.

Note, that the integer 0 will always be present in set A.


Output Format

For each query of the type '?' print one integer — the maximum value of bitwise exclusive OR (XOR) of integer xi and some integer from the multiset A.


Sample Input 1

12
? 4
+ 4
? 4
+ 4
? 3
- 4
- 4
? 3
+ 4
? 4
+ 1
+ 1

Sample Output 1

4
4
7
3
4
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
    int q;
    cin>>q;
    while(q--){
        char ch;
        int a;
        cin>>ch>>a;
        if(ch=='+'){
            bt.insert(a);
        }else if(ch=='-'){
            bt.del(a);
        }else{
           cout<<bt.getMax(a)<<endl;
        }
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

/*
//Editorial Code:
#include <bits/stdc++.h>
using namespace std;

#define int long long

class trieNode {
public:
    int freq;
    trieNode* left;
    trieNode* right;
    trieNode() {
        freq = 0;
        left = NULL;
        right = NULL;
    }
};

void insert(int n, trieNode* head) {
    trieNode* cur = head;
    for (int i = 31; i >= 0; --i) {
        int bit = (n >> i)&1;
        if(bit) {
            if(!cur->right) {
                cur->right = new trieNode();
            }
            cur = cur->right;
            cur->freq++;
        }
        else {
            if(!cur->left) {
                cur->left = new trieNode();
            }
            cur = cur->left;
            cur->freq++;
        }
    }
}

void erase(int n, trieNode* head) {
    trieNode* cur = head;
    for (int i = 31; i >= 0; --i) {
        int bit = (n >> i)&1;
        if(bit) {
            cur->right->freq--;
            cur = cur->right;
        }
        else {
            cur->left->freq--;
            cur = cur->left;
        }
    }
}

int findMaxXOR(int n, trieNode* head) {
    trieNode* cur = head;
    int ans = 0;
    for (int j = 31; j >= 0; --j) {
        int bit = (n >> j)&1;
        if(bit) {
            if(cur->left && cur->left->freq > 0) {
                ans += (1<<j);
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        else {
            if(cur->right && cur->right->freq > 0) {
                ans += (1<<j);
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    trieNode* head = new trieNode();
    insert(0, head);
    while(q--) {
        char c;
        int x;
        cin >> c >> x;
        if(c == '+') {
            insert(x, head);
        }
        else if(c == '-') {
            erase(x, head);
        }
        else {
            cout << findMaxXOR(x, head) << "\n";
        }
    }
    return 0;
}
*/