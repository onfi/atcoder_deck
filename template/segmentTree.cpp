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
const ll INF = LLONG_MAX;

struct SEGMENT_TREE
{
private:
    bool enabledMin, enabledMax, enabledSum;
    vector<ll> r_min_q_node, r_max_q_node, r_sum_q_node;
public:
    int n;
    SEGMENT_TREE(vector<ll> &v, bool _enabledMin = true, bool _enabledMax = true, bool _enabledSum = true) {
        enabledMin = _enabledMin;
        enabledMax = _enabledMax;
        enabledSum = _enabledSum;

        int sz = v.size();

        n = 1;
        while (n < sz) {
            n <<= 1;
        }

        if(enabledMin) r_min_q_node.assign(2 * n - 1, INF);
        if(enabledMax) r_max_q_node.assign(2 * n - 1, 0);
        if(enabledSum) r_sum_q_node.assign(2 * n - 1, 0);

        // 直接値が入るのは、index + (n - 1)
        for (int i = 0; i < sz; i++) {
            if(enabledMin) r_min_q_node[i + n - 1] = v[i];
            if(enabledMax) r_max_q_node[i + n - 1] = v[i];
            if(enabledSum) r_sum_q_node[i + n - 1] = v[i];
        }

        // 親：(i - 1) / 2
        // 左の子：2 * i + 1
        // 右の子：左の子 + 1
        for (int i = n - 2; i >= 0; i--) {
            updateNode(i);
        }
    }

    // i番目の値をvalに変更する
    void update(ll i, ll val) {
        i += (n - 1);
        if(enabledMin) r_min_q_node[i] = val;
        if(enabledMax) r_max_q_node[i] = val;
        if(enabledSum) r_sum_q_node[i] = val;
        for (i = (i - 1) / 2; i > 0; i = (i - 1)) {
            updateNode(i);
        }
    }
    
    void updateNode(ll i) {
        if(enabledMin) r_min_q_node[i] = RmQProcess(r_min_q_node[2 * i + 1], r_min_q_node[2 * i + 2]);
        if(enabledMax) r_max_q_node[i] = RMQProcess(r_max_q_node[2 * i + 1], r_max_q_node[2 * i + 2]);
        if(enabledSum) r_sum_q_node[i] = RSQProcess(r_sum_q_node[2 * i + 1], r_sum_q_node[2 * i + 2]);
    }

    // [a, b)の最小値を求める
    ll RmQ(ll a, ll b) {
        ll val_left = INF, val_right = INF;
        for (a += (n - 1), b += (n - 1); a < b; a >>= 1, b >>= 1) {
            if ((a & 1) == 0) {
                val_left = RmQProcess(val_left, r_min_q_node[a]);
            }
            if ((b & 1) == 0) {
                val_right = RmQProcess(val_right, r_min_q_node[--b]);
            }
        }
        return RmQProcess(val_left, val_right);
    }
    ll RmQProcess(ll val1, ll val2) {
        return min(val1, val2);
    }

    // [a, b)の最大値を求める
    ll RMQ(ll a, ll b) {
        ll val_left = 0, val_right = 0;
        for (a += (n - 1), b += (n - 1); a < b; a >>= 1, b >>= 1) {
            if ((a & 1) == 0) {
                val_left = RMQProcess(val_left, r_max_q_node[a]);
            }
            if ((b & 1) == 0) {
                val_right = RMQProcess(val_right, r_max_q_node[--b]);
            }
        }
        return RMQProcess(val_left, val_right);
    }
    ll RMQProcess(ll val1, ll val2) {
        return max(val1, val2);
    }

    // [a, b)の合計を求める
    ll RSQ(ll a, ll b) {
        ll val_left = 0, val_right = 0;
        for (a += (n - 1), b += (n - 1); a < b; a >>= 1, b >>= 1) {
            if ((a & 1) == 0) {
                val_left = RSQProcess(val_left, r_sum_q_node[a]);
            }
            if ((b & 1) == 0) {
                val_right = RSQProcess(val_right, r_sum_q_node[--b]);
            }
        }
        return RSQProcess(val_left, val_right);
    }
    ll RSQProcess(ll val1, ll val2) {
        return (val1 + val2) % MOD;
    }
};

int main() {
    INIT();

    vector<ll> vec;
    ll n = 3000000;
    REP(i, n) {
        vec.push_back(i);
    }
    SEGMENT_TREE segTree(vec);
    segTree.update(30, 1);
    segTree.update(300, 20000);
    cout << segTree.RmQ(4, n - 1) << endl;
    cout << segTree.RMQ(4, n - 1) << endl;
    cout << segTree.RSQ(4, n - 1) << endl;
    return 0;
}