/*
 * https://atcoder.jp/contests/abc157/tasks/abc157_d
 */
#include <bits/stdc++.h>
 
using namespace std;

// ショートハンド
// #define ll intに変えればメモリ節約
#define ll int

/* 
 * ループ系のマクロ
 * `REP(i, 10) { cout << i; }`のように、変数名,回数で動く
 */
#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

/*
 * 正規表現系
 */
#define MATCH(_str, _ptn) regex_match(_str, regex(_ptn))
#define REPLACE(_str, _ptn, _replacement) regex_replace(_str, regex(_ptn), _replacement)

const int MOD = 1e9 + 7;

struct UnionFind {
    ll n;
    vector<ll> par,cnt;

    UnionFind(ll N) : par(N) {
        n = N;
        REP(i,n) par[i] = i;
    }

    ll root(ll x) {
        while(par[x] != x) {
            x = par[x];
        }
        return x;
    }

    void unite(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    void clean() {
        cnt.assign(n, 0);
        REP(i,n) {
            par[i] = root(i);
            cnt[par[i]]++;
        };
    }

    // 実行前にclean必須！
    ll count(ll x) {
        return cnt[root(x)];
    }
};

ll n,m,k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    UnionFind unionFind(n);
    vector<ll> blocks(n, 1);
    REP(i,m) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        unionFind.unite(a,b);
        blocks[a]++;
        blocks[b]++;
    }
    unionFind.clean();
    REP(i,k) {
        ll c,d;
        cin >> c >> d;
        c--;d--;
        if(unionFind.same(c,d)) {
            blocks[c]++;
            blocks[d]++;
        }
    }
    REP(i,n) {
        if(i > 0) cout << " ";
        cout << unionFind.count(i) - blocks[i];
    }
    return 0;
}