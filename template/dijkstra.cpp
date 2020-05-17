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


#define MAX_V 100000

struct edge {
    ll to;
    ll cost;
};
vector<edge> Graph[MAX_V];

using _DijkstraCsot = pair<ll, ll>;
ll _dijkstraResults[MAX_V];

ll* dijkstra(ll V, ll s) {
    priority_queue<_DijkstraCsot, vector<_DijkstraCsot>, greater<_DijkstraCsot> > que;
    fill(_dijkstraResults, _dijkstraResults + V, INF);
    _dijkstraResults[s] = 0;
    que.push(_DijkstraCsot(0, s));

    while (!que.empty()) {
        _DijkstraCsot p = que.top();
        que.pop();
        ll v = p.second;
        if (_dijkstraResults[v] < p.first) continue;

        REP(i, Graph[v].size()) {
            edge e = Graph[v][i];
            if (_dijkstraResults[e.to] > _dijkstraResults[v] + e.cost) {
                _dijkstraResults[e.to] = _dijkstraResults[v] + e.cost;
                que.push(_DijkstraCsot(_dijkstraResults[e.to], e.to));
            }
        }
    }
    return _dijkstraResults;
}
void pushOneWay(ll from,ll to, ll cost) {
    edge e = {to, cost};
    Graph[from].push_back(e);
}
void pushTwoWay(ll from,ll to, ll cost) {
    pushOneWay(from, to, cost);
    pushOneWay(to, from, cost);
}

ll n,m,k;
string s;
int main() {
    INIT();

    ll x,y,results[20001];
    cin >> n >> x >> y;
    x--;
    y--;
    REP(i,n) {
        pushTwoWay(i, i - 1, 1);
    }
    pushTwoWay(x, y, 1);
    REP(i,n) {
        results[i] = 0;
    }
    REP(i,n) {
        ll* d = dijkstra(n, i);
        REPS(j,i+1,n) {
            results[d[j]]++;
        }
    }
    REPS(i,1,n) {
        cout << fixed << results[i] << endl;
    }
    return 0;
}