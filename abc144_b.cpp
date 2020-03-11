/*
 * https://atcoder.jp/contests/abc144/tasks/abc144_b
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

// `chmax(a, b)` aがbより小さければ、aをbに上書きする。chminは逆
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1e9 + 7;
int main() {
    INIT();

    ll n;
    cin >> n;
    string a;
    REPS(i, 1, 10) {
        REPS(j, 1, 10) {
            if(i * j == n) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}