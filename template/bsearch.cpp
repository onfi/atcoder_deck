// https://atcoder.jp/contests/abc174/tasks/abc174_e
#include <bits/stdc++.h>
// https://boostjp.github.io/tips/multiprec-int.html
// https://boostjp.github.io/tips/multiprec-float.html
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
 
using namespace std;

#define ll long long
#define ld long double

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

# define INIT() cin.tie(0); ios::sync_with_stdio(false); cout << fixed << std::setprecision(20)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll n,k;
# define BSEARCH_TYPE ll
vector<BSEARCH_TYPE> v;
BSEARCH_TYPE key;

// val が条件を満たすかどうか
bool isOK(ll val) {
    // // 普通のbsearch, valはindex
    // if (v[val] >= key) {
    //     return true;
    // } else {
    //     return false;
    // }

    ll cnt = 0;
    for(auto&& a : v) {
        cnt += (a + val - 1) / val;
    }
    return cnt <= k + n;
}

// leftはmin - 1
ll bsearch(ll left, ll right) {
    while (abs(right - left) > 1) {
        ll mid = (right + left) / 2;

        if (isOK(mid)) right = mid;
        else left = mid;
    }
    return right;
}

// vから普通にbsearchする
ll bsearchVec(BSEARCH_TYPE _key) {
    key = _key;
    return bsearch(-1, (int)v.size());
}

int main() {
    INIT();

    cin >> n >> k;
    v.resize(n);
    REP(i, n) {
        cin >> v[i];
    }
    cout << bsearch(0, *max_element(v.begin(), v.end()));
    return 0;
}