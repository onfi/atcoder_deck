/*
 * https://atcoder.jp/contests/abc160/tasks/abc160_d
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
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

/*
 * 正規表現
 */
#define MATCH(_str, _ptn) regex_match(_str, regex(_ptn))
#define REPLACE(_str, _ptn, _replacement) regex_replace(_str, regex(_ptn), _replacement)

# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())

# define pb push_back

# define INIT() cin.tie(0); ios::sync_with_stdio(false)

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
// `chmax(a, b)` aがbより小さければ、aをbに上書きする。chminは逆
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1e9 + 7;


#define INF 1e+9
#define MAX_V 100000

struct edge {
    ll to;
    ll cost;
};

using P = pair<ll, ll>;

vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll V, ll s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;

        for (ll i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void pushV(ll node,ll to, ll cost) {
    edge e = {to, cost};
    G[node].push_back(e);
}
int main() {
    INIT();

    ll n,x,y,results[20001];
    cin >> n >> x >> y;
    x--;
    y--;
    pushV(0, 1, 1);
    REPS(i,1,n - 1) {
        pushV(i, i - 1, 1);
        pushV(i, i + 1, 1);
    }
    pushV(n - 1, n - 2, 1);
    pushV(x, y, 1);
    pushV(y, x, 1);
    REP(i,n) {
        dijkstra(n, i);
        REPS(j,i+1,n) {
            cout << i << "から" << j << "までのコスト: " << d[j] << endl;
            results[d[j]]++;
        }
    }
    REPS(i,1,n) {
        cout << fixed << results[i] << endl;
    }
    return 0;
}