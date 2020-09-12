#include <bits/stdc++.h>
 
using namespace std;

// ショートハンド
// #define ll intに変えればメモリ節約
#define ll long long
#define ld long double

const int MOD = 1e9 + 7;
#define INF 2e9

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

# define INIT() cin.tie(0); ios::sync_with_stdio(false); cout << fixed << std::setprecision(20)

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
// `chmax(a, b)` aがbより小さければ、aをbに上書きする。chminは逆
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


vector<ll> Primes;
// _Nの平方根までの素数を作る
void initPrimes( const ll _N ) {
    const ll N = floor(sqrt(_N)) * 2;
    vector<bool> is_prime( N + 1 );
    for( ll i = 0; i <= N; i++ ) {
        is_prime[ i ] = true;
    }
    for( ll i = 2; i <= N; i++ ) {
        if( is_prime[ i ] ) {
            for( ll j = 2 * i; j <= N; j += i ) {
                is_prime[ j ] = false;
            }
            Primes.emplace_back( i );
        }
    }
}

unordered_map<ll, unordered_map<ll, ll>> memo;
unordered_map<ll, ll> prime_factorize(ll _n) {
    if(memo.count(_n)) return memo[_n];
    unordered_map<ll, ll> res;
    int i = 0;
    for (ll a = Primes[i]; a * a <= _n; a = Primes[++i]) {
        if (_n % a != 0) continue;
        ll ex = 0;
        while (_n % a == 0) {
            res[a]++;
            _n /= a;
        }
    }
    if (_n != 1) res[_n]++;
    return memo[_n] = res;
}

int main() {
    INIT();
    initPrimes(5e5 + 1); // 仕様上の最大値まで初期化する

    ll n;
    cin >> n;
    REPS(i, 2, n + 1) {
        cout << i << " ";
        for(auto [prime, cnt] : prime_factorize(i)) {
            cout << prime << ":" << cnt << ", ";
        }
        cout << endl;
    }
    return 0;
}