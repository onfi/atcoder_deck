#include <bits/stdc++.h>
 
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
#define INF 2e9

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

ll n,m,k;
string s;
int main() {
    INIT();

    cin >> s;
    EACH(c,s) {
        cout << SZ(s);
    }
    return 0;
}