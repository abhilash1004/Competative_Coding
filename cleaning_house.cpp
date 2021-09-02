/*
Given n tiles and q queries and string which mentions 
ith tile state

States of tile:
'F' - Food present
'-' - Nothing
'D' - Dirty

In each query u will be given x and y
x - Mentions the cost to move food to adjacent tile.
y - Mentions the cost to clean dirty tile.

You have to print min cost for each query such that u can make
all food tiles adjacent to each other.

Note: U can't move food to dirty tile

Constarints:
1<=n,q<=10^5
0<=x,y<=10^5

Sample Input 1:
10 3
---F-FD-F-
0 10
10 0
1 1


Sample Output 1:
10
30
4


Sample Input 2:
20 8
-F-F-FDFFF----FFF---
8 2
4 4
7 2
9 10
10 6
8 6
3 2
5 9

Sample Output 2:
146
76
128
172
186
150
56
99
*/

#include<bits/stdc++.h>
using namespace std;

int n,q;
string str;

int getnxt(string s,int st,int end){
    for(int i=st;i<=end;i++){
        if(s[i]=='-') return i;
    }
    return -1;
}

void solve(int &x,int &y){
    //string temp = str;
    int pos=-1;
    x=y=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='F'){
            pos = i;
            break;
        }
    }
    if(pos==-1) return;
    int pos2=-1;
    for(int i=n-1;i>pos;i--){
        if(str[i]=='F'){
            pos2=i;
            break;
        }
    }
    if(pos2==-1) return;
    for(int i=pos;i<=pos2;i++){
        if(str[i]=='D'){y++;str[i]='-';}
    }
    x = 1e9;
    int cur=0;
    for(int i=pos;i<=pos2;i++){
        if(str[i]!='F') continue;
        string temp = str;
        cur = 0;
        for(int j=i-1;j>=pos;j--){
            if(temp[j]=='F'){
                continue;
            }
            int k=j-1;
            for(;k>=pos;k--){
                if(temp[k]=='F'){
                    break;
                }
            }
            if(k!=pos-1){
                cur+=(j-k);
                temp[j] = 'F';
                temp[k] = '-';
            }
        }
        for(int j=i+1;j<=pos2;j++){
            if(temp[j]=='F'){
                continue;
            }
            int k=j+1;
            for(;k<=pos2;k++){
                if(temp[k]=='F'){
                    break;
                }
            }
            if(k!=pos2+1){
                cur+=(k-j);
                temp[j] = 'F';
                temp[k] = '-';
            }
        }
        //cout<<" pos = "<<i<<" "<<cur<<endl;
        //cout<<temp<<endl;
        x = min(x,cur);
    }
    //cout<<"X="<<x<<endl;
}

int main(){
    cin>>n>>q;
    cin>>str;
    int rx,ry;
    solve(rx,ry);
    //cout<<rx<<" "<<ry<<endl;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(a*rx+b*ry)<<endl;
    }
}