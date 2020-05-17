#include <bits/stdc++.h>
 
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
#define INF 1e+9

#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

#define MATCH(_str, _ptn) regex_match(_str, regex(_ptn))
#define REPLACE(_str, _ptn, _replacement) regex_replace(_str, regex(_ptn), _replacement)

# define pb push_back

# define INIT() cin.tie(0); ios::sync_with_stdio(false)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

ll power(ll a, ll b){
	ll res=1;
	while(b>0){
		if(b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void initFact() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    REPS(i, 2, MAX) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll factionalInverse(ll n) {
    if(!fac[0]) initFact();
    return finv[n];
}
ll factional(ll n) {
    if(!fac[0]) initFact();
    return fac[n];
}
ll nCr(ll n, ll r){
	return (factional(n) * factionalInverse(r)) % MOD * factionalInverse(n-r) % MOD;
}
ll nPr(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    return factional(n) * factionalInverse(n - r) % MOD;
}

ll n,m,k;
string s;
int main() {
    INIT();

    REP(i,10) {
        REP(j,i) {
            cout << i << "P" << j << " : " << nPr(i,j) << endl;
        }
    }
    REP(i,10) {
        REP(j,i) {
            cout << i << "C" << j << " : " << nCr(i,j) << endl;
        }
    }
    return 0;
}