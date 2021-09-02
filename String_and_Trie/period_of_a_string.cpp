/*
Period of a string

Time-Limit: 3 sec Score: 100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

For each prefix of a given string S with N characters consisting of lowercase characters, we want to know whether the prefix is a periodic string. That is, for each i (2 <= i <= N) we want to know the largest K > 1 (if there is one) such that the prefix of S with length i can be written as AK , that is A concatenated K times, for some string A. Of course, we also want to know the period K. If there are multiple AK print the maximum value of K.


Input Format

The first line contains an integer T, ( 1 ≤ T ≤ 10000) - the number of test cases.

The first line of each test case contains an integer N, ( 2 ≤ N ≤ 100000).

The second line contains a string S of length N.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case, output “Test case #” and the consecutive test case number on a single line; then, for each prefix with length i that has a period K > 1, output the prefix size i and the largest period K separated by a single space; the prefix sizes must be in increasing order. Print a blank line after each test case.


Sample Input 1

2
9
abababaab
6
ffffff

Sample Output 1

Test case #1
4 2
6 3

Test case #2
2 2
3 3
4 4
5 5
6 6
*/

/*
If the prefix function for substring with length i is p[i], 
we would consider the period length as (i - p[i]). 
If this value is a multiple of the length i, 
then K = i / (i - p[i]). We can combine the prefix of 
length (i - p[i]) K times to get the prefix of length i.

Time complexity per test case: O(N)
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int kmp[n+1];
    int i=0,j=-1;
    kmp[0] = -1;
    while(i<n){
        while(j>-1 && s[i]!=s[j]){
            j = kmp[j];
        }
        i++;j++;
        kmp[i] = j;
    }
    for(int i=2;i<=n;i++){
        int x = i - kmp[i];
        if(i%x==0 && i!=x){//if(i%x)==0 then we found a period and if i==x this is whole length of string so no period
            cout<<i<<" "<<i/x<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    int i=0;
    while(t--){
        cout<<"Test case #"<<++i<<"\n";
        solve();
        cout<<endl;
    }
}