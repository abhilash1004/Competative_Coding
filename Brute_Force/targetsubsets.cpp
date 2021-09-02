/*
Description

You have given an array of length N, and a number X. Find the number of subsets with the sum of elements less than equal to X.

Note:

The sum of elements in an empty subset is 0.
The set may contain duplicates elements.

Input Format

The first line of input contains T - the number of test cases.
The first line of each test case contains two space-separated numbers N and X.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.  


Output Format

Print the number of subsets with a sum less than equal to X in a new line for each test case.


Constraints

1 ≤ T ≤ 5
1 ≤ N ≤ 35
0 ≤ Ai ≤ 104
0 ≤ X ≤ 106


Sample Input 1

2
2 1
1 2
3 8
2 2 6

Sample Output 1

2
7
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,x;
vector<int> v;

vector<int> findsums(vector<int> &a)
{
	vector<int> ans;
	for(int i=0;i<(1<<a.size());i++)
	{
		int sum = 0;
		for(int j=0;j<a.size();j++)
		{
			if(i&(1<<j))
			{
				sum+=a[j];
			}
		}
		ans.push_back(sum);
	}
	return ans;
}
void print_vec(vector<int> a)
{
	for(auto i:a)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int count_subsets()
{
	vector<int> a[2];
	for(auto i:v)
	{
		a[i%2].push_back(i);
	}
	vector<int> ans1,ans2;
	//findsums(a[0],ans1);
	//findsums(a[1],ans2);
	ans1 = findsums(a[0]);
	ans2 = findsums(a[1]);
	int ans=0;
	sort(ans2.begin(),ans2.end());
	sort(ans1.begin(),ans1.end());
	for(auto i:ans1)
	{
		if(i>x) break;
		ans += upper_bound(ans2.begin(),ans2.end(),x-i) - ans2.begin();
	}
	return ans;
}

void solve(){
	cin>>n>>x;
	v.resize(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<count_subsets()<<endl;
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


/*
Some Geek Solution
#include <bits/stdc++.h>

using namespace std; 

#define ar array 
#define vec vector
#define pque priority_queue
#define tup tuple
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define bk back
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define emb emplace_back
#define ins insert
#define spc cout<<" ";
#define nl cout<<"\n"
#define sp setprecision
#define lbd lower_bound 
#define ubd upper_bound
#define nper next_permutation
#define fbo find_by_order
#define ook order_of_key
#define uomp unordered_map

typedef const int cint;
typedef string str;
typedef const string cstr;
typedef float fl;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<int, int> pii;
typedef pair<int, long> pil;
typedef pair<long, int> pli;
typedef pair<long, long> pll;
typedef pair<int,ll> plli;
typedef pair<ll,int> pill;
typedef pair<ll,ll> pllll;
typedef pair<ld,int> pldi;
typedef pair<pii,pii> ppiipii;
typedef vec<bool> vb;
typedef vector<string> vs;
typedef vector<string> const vsc;
typedef vector<int> vi;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<fl> vf;
typedef vector<vector<fl>> vvf;
typedef vector<pis> vpis;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pill> vpill;
typedef vector<plli> vplli;
typedef vector<pllll> vpllll;
typedef vector<psi> vpsi;
typedef vector<vpii> vvpii;
typedef forward_list<ll> flll;
typedef deque<int> deqi;
typedef stack<int> si;
typedef pque<int> pqi;
typedef pque<ll> pqll;
typedef set<int> seti;
typedef set<ll> setll;
typedef multiset<int> mseti;
typedef multiset<ll> msetll;
typedef map<string,int> msi;
typedef map<int,string> mis;
typedef map<int,int> mii;
typedef map<ll,int> mlli;
typedef multimap<string,int> mmsi;
typedef multimap<int,string> mmis;
typedef multimap<int,int> mmii;
#define minque(T) pque<T, vec<T>, greater<T>>
typedef uomp<int,int> uompii;
typedef uomp<ll,int> uomplli;


#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define couts(v) cout<<v<<" "
#define coutt(v) cout<<v<<"\t"
#define coutn(v) cout<<v<<"\n"
#define coutsps(v,n) cout<<setprecision(n)<<v<<" "
#define coutspt(v,n) cout<<setprecision(n)<<v<<"\t"
#define coutspn(v,n) cout<<setprecision(n)<<v<<"\n"
#define coutfsps(v,n) cout<<fixed<<setprecision(n)<<v<<" "
#define coutfspt(v,n) cout<<fixed<<setprecision(n)<<v<<"\t"
#define coutfspn(v,n) cout<<fixed<<setprecision(n)<<v<<"\n"
#define coutpn(v) cout<<v.fi<<" "<<v.se<<"\n"
#define coutps(v) cout<<v.fi<<" "<<v.se<<"  "
#define what(x) cout<<#x<<" = "<<x<<'\n'
#define forfz(n) for(int i=0; i<n; i++)
#define forfzdel(n,del) for(int i=0; i<n; i+=del)
#define forfo(n) for(int i=1; i<=n; i++)
#define forfvo(i,n) for(int i=1; i<=n; i++)
#define forf(f,n) for(int i=f; i<n; i++)
#define forfdel(f,n,del) for(int i=f; i<n; i+=del)
#define forbz(n) for(int i=n-1; i>=0; i--)
#define forb(f,n) for(int i=n-1; i>=f; i--)
#define fors(s) for (char c : s)
#define forfvz(i,n) for(int i=0; i<n; i++)
#define forfv(i,f,n) for(int i=f; i<n; i++)
#define forbv(i,f,n) for(int i=n-1; i>=f; i--)
#define forfsitz(s) for(auto it = s.begin();it != s.end();++it)

// string
#define intcaz(c) ((int)c - (int)'a') 
#define intc(c) ((int)c - (int)'a' + 1)

// vector
#define sz(v) (int)v.size()
#define initvvisq(v, n) vvi v(n, vi(n)) 
#define initvvi(v, n, m) vvi v(n, vi(m)) 
#define initvvisqz(v, n) vvi v(n, vi(n, 0))
#define initvvisqv(v, n, val) vvi v(n, vi(n, val))
#define initvviz(v, n, m) vvi v(n, vi(m, 0)) 
#define initvviv(v, n, m, val) vvi v(n, vi(m, val))
#define inpaz(arr,n) forfz(n) cin>>arr[i]
#define inpa(arr,f,n) forf(f,n) cin>>arr[i]
#define inpvz(v) forfz(sz(v)) cin>>v[i]
#define inpvn(v,n) forfz(n) cin>>v[i]
#define inpvo(v) forfo(sz(v)-1) cin>>v[i]
#define inpv(v,f,n) forf(f,n) cin>>v[i]
#define inpvpz(v) forfz(sz(v)) cin >> v[i].fi >> v[i].se
#define inpvpzr(v) forfz(sz(v)) cin >> v[i].se >> v[i].fi
#define inpvp(v,f,n) forf(f,n) cin >> v[i].fi >> v[i].se
#define inpvpr(v) forf(f,n) cin >> v[i].se >> v[i].fi
#define inpvvz(v) forfvz(in,sz(v)){inpvz(v[in]);}
#define inpvv(v,f,g,n,m) forfv(in,f,n){ inpv(v[in], g, m); }
#define insertv(n,temp,m) forfz(n){cin>>temp;m.insert(temp);}
#define inpvmp(n,temp,m) forfz(n){cin>>temp;mp[temp]++;}
#define coutvz(v) forfz(sz(v)) cout<<v[i]<<" "
#define coutaz(arr,n) forfz(n) cout<<arr[i]<<" "
#define couta(arr,f,n) forf(f,n) cout<<arr[i]<<" "
#define coutsitz(v) forfsitz(s) cout<<*it<<" "
#define coutvidxz(v) forfz(sz(v)){couts(i);}nl;coutvz(v)
#define coutvo(v) forfo(sz(v)-1) cout<<v[i]<<" "
#define coutplusvz(v) forf(0, sz(v)) cout<<v[i]+1<<" "
#define coutv(v,f,n) forf(f,n) cout<<v[i]<<" "
#define coutvvz(v) forfv(in,0,sz(v)){ coutvz(v[in]); cout<<"\n"; }
#define coutvv(v,f,g,n,m) forfv(in,f,n){ coutv(v[in], g, m); cout<<"\n"; }
#define coutvps(v) forf(0,sz(v)) cout<<v[i].fi<<" "<<v[i].se<<"  "
#define coutvpz(v) forf(0,sz(v)) cout << v[i].fi << " " << v[i].se << "\n"
#define coutvrpz(v) forf(0,sz(v)) cout << v[i].se << " " << v[i].fi << "\n"
#define coutvp(v,f,n) forf(f,n) cout << v[i].fi << " " << v[i].se << "\n"
#define coutmpz(v) forfsitz(s) cout<<it->first<<" "<<it->second<<"  "
#define coutvvpz(v) forfvz(in,sz(v)){coutvpzs(v[in]);nl;}
#define all(v) v.begin(),v.end()
#define itv(v,f,n) v.begin()+f,v.begin()+n
#define alla(arr,n) arr,arr+n
#define rall(v) v.rbegin(),v.rend()
#define lb(v,x) lbd(all(v),x) 
#define ub(v,x) ubd(all(v),x) 
#define sorta(arr,n) sort(alla(arr,n))
#define rsorta(arr,n) sort(alla(arr,n),greater<int>())
#define sortvz(v) sort(all(v))
#define sortv(v,f,n) sort(itv(v,f,n))
#define rsortv(v) sort(rall(v))
#define sumv(v) accumulate(all(v), 0)
#define npervz(v) nper(all(v))
#define nperaz(arr,n) nper(alla(arr,n))
#define seterase(s,x) s.erase(s.find(x))
#define testcase ll t,tt; cin>>tt; for(t=1;t<=tt;t++)
#define re return 
#define retz return 0
#define con continue
#define ansmod(ans,mod) ((ans%mod)+mod)%mod
#define clk1 clock_t start_time=clock()
#define clk2 cout<<(clock()-start_time)/(double)CLOCKS_PER_SEC
#define cleana(arr) memset(arr,0,sizeof(arr))
#define cleanv(v) fill(al(v), 0)
#define clearst(st) while(!st.empty()){st.pop();}
#define eqmax(v,w) v=max(v,w)
#define makepref(v) forfz(sz(v)){if(i){v[i]+=v[i-1];}}
#define setend(s) (*(s.rbegin()))
#define FW(d) int size=sz(d)-1; forfvo(k,size){forfo(size){forfoz(j,size){d[i][j] = min(d[[i][j], d[i][k]+d[k][j]);}}}

const int MOD5 = 1e5;
const int MOD7 = 1e7;
const int MOD9 = 1e9;
const int mod = 1e9+7;

const double EPS9 = 1e-9;
const double EPS7 = 1e-7;
const double EPS5 = 1e-5;
const int stK = 30;
long double PI = acos(-1.0);

vi generate(vi a){
    int n=sz(a);
    vi sums;
    forfz(1<<n){
        int sum=0;
        forfvz(j,n){
            if(i&(1<<j)){sum+=a[j];}
        }
        sums.pb(sum);
    }
    return sums;
}

void solve(int casen)
{
    bool printcase=false;
    if(casen==-1){printcase=true;}
    
    char ch;
    str s,t;
    bool flag=false;
    int b,c,i,j,k,l,m,n,o,p,q,u,v,w,x,y,z,cnt=0,idx=0,temp,temp2,maxn=INT_MIN,minn=INT_MAX,secminn=INT_MAX;
    ll sum=0,cntll=0,prod=1;
    cin>>n>>x;
    vvi a(2);
    forfz(n){cin>>temp;a[i%2].pb(temp);}
    
    vi sumsone = generate(a[0]);
    vi sumstwo = generate(a[1]);
    sortvz(sumstwo);
    
    for(auto el:sumsone){
        cntll+=1LL*(ub(sumstwo,x-el)-sumstwo.begin());
    }
    
    coutn(cntll);
}

// hedging against find and replace int
signed main() 
{
    fastio;  
    int _i=1;
    int _t; cin>>_t; while(_t--) 
    solve(_i++);   
}
*/