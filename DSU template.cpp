// clear adj and visited vector declared globally after each test case
// check for long long overflow
// Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <math.h>
#include <string.h>
// using namespace __gnu_pbds;
// using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset = tree<T,null_type,less_equal// for indexed_multiset */
// <T> ,rb_tree_tag,tree_order_statistics_node_update> ;    // order_of_key (k) -> # of elem strictly < k .
//                                                      // *(s.find_by_order(k)) -> element at index K .
#define ll long long
#define ld long double
#define ull unsigned long long
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
 
#define vi vector<int>
#define vl vector<ll>
#define vd vector<ld>
#define vpi vector<pi>
#define vpl vector<pl>
 
#define vvi vector<vector<ll>>
#define vvvi vector<vector<vector<ll>>>
 
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define po pop_back
#define ff first
#define ss second
#define ins insert
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
#define lb(vn, x) lower_bound(vn.begin(), vn.end(), x) - vn.begin()
#define ub(vn, x) upper_bound(vn.begin(), vn.end(), x) - vn.begin()
 
#define endl '\n'
 
#define speed_ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 
#define sp(x) fixed << setprecision(x)
#define uni(arr) arr.erase(unique(arr.begin(), arr.end()), arr.end());
 
#define to_up(x) transform(x.begin(), x.end(), x.begin(), ::toupper)
#define to_low(x) transform(x.begin(), x.end(), x.begin(), ::tolower)
 
#define input(v, n)            \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];
#define Sort(v) sort(v.begin(), v.end())
 
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
 
#define pyes cout << "YES" << endl
#define pno cout << "NO" << endl
 
const int M = 1000000007;
const int MM = 998244353;
// const ld Pi= acos(-1);
const int N = 1e6 + 5;
#define INF 1e18
 
//****************************************DEBUGS***********************************************************
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
 
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
 
//****************************************DEBUGS***********************************************************
 
//*******************************************FUNCTIONS********************************************************
 
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
 
ll smallestprimeDivisor(ll n)
{
    if (n % 2 == 0)
        return 2;
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }
    return n;
}
 
ll __lcm(ll a, ll b)
{
    return ((a * b) / __gcd(a, b));
}
 
ll binexpo(ll x, ll y, ll m)
{ // O(log y) // value of x^y % m
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        y = y >> 1;
    }
 
    return res;
}
 
const ll PMAX = 1e6 + 10;
vector<bool> isPrime(PMAX, 1);
vector<ll> prime;
void primeseive()
{
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i < PMAX; i++)
        if (isPrime[i] == true)
            for (ll j = 2 * i; j < PMAX; j += i)
                isPrime[j] = false;
    for (ll i = 2; i < PMAX; i++)
        if (isPrime[i])
            prime.push_back(i);
}
 
ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
map<ll, ll> factorize(ll n) // prime factorization of a number
{
    ll cnt = 0;
    map<ll, ll> mp;
    while (!(n % 2))
    {
        n >>= 1;
        cnt++;
    }
    if (cnt)
        mp[2] += cnt;
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n = n / i;
        }
        if (cnt)
            mp[i] = cnt;
    }
 
    if (n > 2)
        mp[n] = 1;
 
    return mp;
}
 
ll maxSubarraySum(vl &v) // Kadane's Algorithm // O(n)
{
    ll max_so_far = LLONG_MIN, max_ending_here = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
 
*/

class segTree{
public:
	vvi sgt;
	int n;
	segTree(int p){
		n = 1;
		while(n<p){
			n *= 2;
		}
		sgt.resize(2*n, {-INF52, -INF52, -INF52, 0});
	}
	void build(vi &a, int x, int lx, int rx){ // x is 'node' and [lx, rx-1] is its range 
		if(rx-lx == 1){
			if(lx < sz(a)){
				sgt[x] = {a[lx], a[lx], a[lx], a[lx]};
			}
			return;
		}
		int mid = (lx+rx)/2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);
		vi left = sgt[2*x+1], right = sgt[2*x+2];
		int maxPrefSum = max({
			left[0],
			left[3]+right[0]
		});
		int maxSuffSum = max({
			right[2],
			right[3]+left[2]
		});
		int maxSegSum = max({
			left[1],
			right[1],
			left[2]+right[0]
		});
		int segSum = left[3]+right[3];
		sgt[x] = {maxPrefSum, maxSegSum, maxSuffSum, segSum};
		
	}
	void build(vi &a){
		build(a, 0, 0, n);
	}
	
	void set(int i, int val, int x, int lx, int rx){
		// if(i>=rx || i<lx) return; no need since we`ve taken care below !!
		if(rx-lx == 1){
			sgt[x] = {val, val, val, val};
			return;
		}
		int mid = (lx+rx)/2;
		if(i < mid){
			set(i, val, 2*x+1, lx, mid);
		}else{
			set(i, val, 2*x+2, mid, rx);
		}
		vi left = sgt[2*x+1], right = sgt[2*x+2];
		int maxPrefSum = max({
			left[0],
			left[3]+right[0]
		});
		int maxSuffSum = max({
			right[2],
			right[3]+left[2]
		});
		int maxSegSum = max({
			left[1],
			right[1],
			left[2]+right[0]
		});
		int segSum = left[3]+right[3];
		sgt[x] = {maxPrefSum, maxSegSum, maxSuffSum, segSum};
	}
	void set(int i, int val){
		set(i, val, 0, 0, n);
	}
	
	vi sum(int l, int r, int x, int lx, int rx){ // lx, rx are changing, hence compare them with [l, r-1] which was required range sum
		if(lx>=r || l>=rx) return {-INF52, -INF52, -INF52, 0};
		if(lx>=l && rx<=r) return sgt[x];
		int mid = (lx+rx)/2;
		vi left = sum(l, r, 2*x+1, lx, mid);
		vi right = sum(l, r, 2*x+2, mid, rx);
		// vvi left = sgt[2*x+1], right = sgt[2*x+2];
		int maxPrefSum = max({
			left[0],
			left[3]+right[0]
		});
		int maxSuffSum = max({
			right[2],
			right[3]+left[2]
		});
		int maxSegSum = max({
			left[1],
			right[1],
			left[2]+right[0]
		});
		int segSum = left[3]+right[3];
		// sgt[x] = {maxPrefSum, maxSegSum, maxSuffSum, segSum};
		return {maxPrefSum, maxSegSum, maxSuffSum, segSum};
	}
	vi sum(int l, int r){
		return sum(l, r, 0, 0, n);
	}
};

class DSU{
	public:
	vi size, parent;
	DSU(int n){
		size.resize(n+1, 1);
		parent.resize(n+1, 0);
		for(int i=1; i<=n; i++) parent[i]=i;
	}
	int getUltPar(int u){
		if(parent[u]==u) return u;
		return parent[u]=getUltPar(parent[u]);
	}
	void unbs(int u, int v){
		int ulp_u = getUltPar(u);
		int ulp_v = getUltPar(v);
		if(ulp_u == ulp_v) return;
		if(size[ulp_u] > size[ulp_v]){
			size[ulp_u] += size[ulp_v];
			parent[ulp_v] = ulp_u;
		}else{
			size[ulp_v] += size[ulp_u];
			parent[ulp_u] = ulp_v;
		}
	}
};

int countDigit(long long n) {  
  return floor(log10(n) + 1);  
} 

void solve(){
	ip(l);
	ip(r);
	string s = to_string(l);
	string t = to_string(r);
	s = string(sz(t)-sz(s), '0') + s;
	int ans = 0;
	FORd(i, sz(t) - 1, 0){
		int d1 = s[i], d2 = t[i];
		int curr = 0;
		int p = 1;
		FOR(j, i+1, sz(t)){
			curr += pow(10, p++);
		}
		if(d1 <= d2){
			int diff = (d2 - d1);
			ans += (diff * curr);
		}else{
			int diff = (10 - d1) + d1;
			ans += (diff * curr);
			FORd(k, i-1, 0){
				if(s[k] == '9'){
					s[k] = '0';
					ans++;
				}else{
					s[k]++;
					ans++;
					break;
				}
			}
		}
	}
	opnl(ans);
}
bool multiple=1;
int32_t main(){
	// compute();
	int t=1;
	if(multiple) cin >> t;
	for(int i=1; i<=t; i++){
		solve();
	}
    return 0;
} 