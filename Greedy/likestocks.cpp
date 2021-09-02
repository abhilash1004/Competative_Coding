/*
Description

You are given an array A of n integers and a value k. You can select zero or more non-empty subarrays A[l..r] such that no two subarrays have any index in common, i.e., no two subarrays should overlap. For each chosen subarray A[l..r] add the value A[r]-A[l]-k to your score which is initially zero. Print the max score possible.


Input Format

First line of input contains T, number of test cases.

First line of each test case contains two integers n and k.

Second line contains n integers, Ai , the array A.


Output Format

For each test case print the max score possible in a new line.


Constraints

T ≤ 100

1 ≤ n ≤ 2*105

0 ≤ Ai , k ≤ 109

Sum of n over all test cases is ≤ 2*105


Sample Input 1

2

6 2

4 2 3 7 5 6

6 0 

4 2 3 7 5 6


Sample Output 1

3

6


Note

t=1: Chosen subarrays= ((2,4))  [1 indexed]

t=2: Chosen subarrays= ((2,4), (5,6))  [1 indexed]
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
/*//Wrong function
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	int score = 0,i=1;
	while(i<n)
	{
		while(i<n && v[i]<v[i-1])
		{
			i++;
		}
		int l = i-1;
		//cout<<"l= "<<v[l]<<endl;
		while(i<n && v[i]>v[i-1])
		{
			i++;
		}
		int r = i-1;
		//cout<<"r= "<<v[r]<<endl;
		int temp = v[r] - v[l] - k;
		if(temp>0)
			score+=temp;
	}
	cout<<score<<endl;
}
*/
/*signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}*/
/**
 * Hint:
 * If subtracting K was not there in the problem, you 
 * could have used this: A[i] - A[i-2] = (A[i] - A[i-1]) + (A[i-1] - A[i-2]) 
 * and using this we can first add (A[i-1] - A[i-2] to the answer and 
 * if (A[i]-A[i-2]) gives greater answer, we can then 
 * add (A[i]-A[i-1]) to get the final answer. 
 * How can you modify this solution to get the answer with subtraction of K.
 * 
 * 
 * Solution:
 * In this problem, instead of storing A[i-1] for the next iteration, 
 * we can store (A[i-1] - K), 
 * since this will cancel, otherwise there would be K twice. 
 * (A[i] - A[i-2] - K) = (A[i] - (A[i-1] - K) - K) + (A[i-1] - A[i-2] - K).
 * Time Complexity per test case: O(N)
**/ 

// solution
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0, cur = a[0];
        for (int i = 1; i < n; ++i) {
        	
            if(a[i] < cur) {
                cur = a[i];
            }
            else if(a[i] > cur + k) {
                ans += a[i] - cur - k;
                cur = a[i] - k;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
        cout << ans << "\n";
    }
    return 0;
}