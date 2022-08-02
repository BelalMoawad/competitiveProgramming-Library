// Author : Belal Moawad

#include<bits/stdc++.h>
#include<ext/numeric>

#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
#define int long long
#define ll long long
#define double long double
#define F first
#define S second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef bitset<70> MASK;
const int N = 1e5 + 9, MOD = 1e9 + 7, OO = 0x3f3f3f3f3f3f3f3f;
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//|


int iterativeFastPower(int x, int p, int mod) {
    int ret = 1;
    while (p) {
        if (p & 1)
            ret = (ret * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return ret;
}

int modInverse(int a) {
    return iterativeFastPower(a, MOD - 2, MOD);
}

int fact[N];
//ncr = n! / ( r! * (n-r)! )
int ncr(int n, int r) {
    if (n < r) return 0;
    return (fact[n] % MOD * modInverse(fact[r]) % MOD * modInverse(fact[n - r]) % MOD) % MOD;
}

void init() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++) (fact[i] = i * fact[i - 1]) %= MOD;
}

void doWork() {
    int n, r;
    cin >> n >> r;
    cout << ncr(n, r) << '\n';
}

int32_t main() {
    init();
    FAST
    int tc = 1;
    cin >> tc;
    while (tc--) doWork();
}
