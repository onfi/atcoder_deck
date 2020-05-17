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

struct UnionFind {
    ll n;
    vector<ll> par,rank;

    UnionFind(ll N) : par(N) {
        n = N;
        REP(i,n) par[i] = i;
        rank.assign(n, 1);
    }

    ll root(ll x) {
        ll tmp = x;
        while(par[tmp] != tmp) {
            tmp = par[tmp];
        }
        return par[x] = tmp;
    }

    void unite(ll x, ll y) {
        ll rootX = root(x);
        ll rootY = root(y);
        if (rootX == rootY) return;
        rank[rootY] += rank[rootX];
        par[rootX] = rootY;
    }

    bool same(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll count(ll x) {
        return rank[root(x)];
    }
};

ll n,m,k;
int main() {
    INIT();

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