#include <bits/stdc++.h>
 
#define ll long long
using namespace std;


#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

const int MOD = 1e9 + 7;

class mint {
public:
    long long x;
    mint(long long x=0) : x((x % MOD + MOD) % MOD) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};


// 階乗を計算する
vector<mint> _factionals = {0,1};
mint factional(long long n) {
    if(_factionals.size() <= n) {
        long long  i = _factionals.size();
        _factionals.resize(n + 1);
        for(; i <= n; i++) {
            _factionals[i] = _factionals[i - 1] * i;
        }
    }
    return _factionals[n];
}

// 組み合わせ数を計算する。nCr
unordered_map<long long, vector<mint>> _combinations;
mint combination(long long n, long long r) {
    if(n < 1 || r < 1 || n < r) return mint(0);
    if(n == r) return mint(1);
    
    // nが小さい場合は公式を使う
    if(n < 51000) return factional(n) / (factional(r) * factional(n - r)); 

    // nが大きい場合はnC(r) = nC(r - 1) * (n - r + 1) / r
    // nCr = nC(n - r)、計算量が少ない方を選ぶ
    if(r > n - r) r = n - r;
    // nC0 = 0, nC1 = nで初期化
    if(!_combinations.count(n)) _combinations[n] = {0, n};
    auto&& vec = _combinations[n];
    if(vec.size() <= r) {
        long long i = vec.size();
        vec.resize(r + 1);
        for(; i <= r; i++) {
            vec[i] = (vec[i - 1] * (n - i + 1)) / i;
        }
    }

    return vec[r];
}

// 順序のパターン数を計算する。nPr
unordered_map<long long, vector<mint>> _permutations;
mint permutation(long long n, long long r) {
    if(n < 1 || r < 1 || n < r) return mint(0);

    // nが小さい場合は公式を使う
    if(n < 51000) return factional(n) / factional(n - r); 

    // nが大きい場合はnC(r) = nC(r - 1) * (n - r + 1)
    // nC0 = 0, nC1 = nで初期化
    if(!_permutations.count(n)) _permutations[n] = {0, n};
    auto&& vec = _permutations[n];
    if(vec.size() <= r) {
        long long i = vec.size();
        vec.resize(r + 1);
        for(; i <= r; i++) {
            vec[i] = vec[i - 1] * (n - i + 1);
        }
    }

    return vec[r];
}

int n,a,b;
mint result;
int main() {
    cin.tie(0); ios::sync_with_stdio(false); cout << fixed << std::setprecision(20);

    cin >> n >> a >> b;
    cout << combination(20, 2) << endl;
    cout << combination(20, 17) << endl;
    cout << permutation(20, 2) << endl;
    cout << permutation(20, 18) << endl;
}