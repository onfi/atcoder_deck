/*
 * https://atcoder.jp/contests/abc154/tasks/abc154_b
 */
#include <bits/stdc++.h>
 
using namespace std;

// ショートハンド
// #define ll intに変えればメモリ節約
#define ll long long

/* 
 * ループ系のマクロ
 * `REP(i, 10) { cout << i; }`のように、変数名,回数で動く
 */
#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
#define EACH(i, n) for (auto&& i : n)

/*
 * 正規表現系
 */
#define MATCH(_str, _ptn) regex_match(_str, regex(_ptn))
#define REPLACE(_str, _ptn, _replacement) regex_replace(_str, regex(_ptn), _replacement)
const int MAX = 510000;
const int MOD = 1e9 + 7;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

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