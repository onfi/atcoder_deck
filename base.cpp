#include <bits/stdc++.h>
 
using namespace std;

#define ll long long
/*
 * 
 */
#define REPS(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (ll i = (a); i >= (ll)(n); --i)
#define DEP(i, n) DEPS(i, n, 0)
#define EACH(i, n) for (auto&& i : n)

const int MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    

    cin >> a;
    REP(i, 10) {
        cout << a;
    }
    return 0;
}