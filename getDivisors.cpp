// Author : Belal Moawad
#include<bits/stdc++.h>
#include<ext/numeric>
#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
using namespace __gnu_cxx;
//#define int long long
#define all(x) (x).begin(), (x).end()
#define all_r(x) (x).rbegin(), (x).rend()
#define double long double
#define Sz(x) ((int)x.size())
#define F first
#define S second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef bitset<32> MASK;
const int N = 1e9 + 9, MOD = 1e9 + 7, OO = 0x3f3f3f3f;
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//|

int MX = (int) sqrt(N);
vi primes;
vector<bool> isPrime;

void seive() {
    isPrime = vector<bool>(MX + 1, true);
    for (int i = 2; i <= MX; ++i) {
        if(!isPrime[i]) continue;
        primes.emplace_back(i);
        for (int j = i + i; j <= MX; j += i) isPrime[j] = false;
    }
}

vi divisors;

void solve(int idx, int val, vector<pii> &v, const int& n) {
    if(idx == Sz(v)) {
        if(val != 1) divisors.emplace_back(val);
        return;
    }
    solve(idx + 1, val, v, n);
    for (int i = 1, cur = v[idx].F; i <= v[idx].S; ++i, cur *= v[idx].F)
        solve(idx + 1, val * cur, v, n);
}

void getDivisors(int n) {
    int tmp_n = n;
    vector<pii> mp;
    for(auto &prime : primes) {
        if(prime * prime > n) break;
        int cnt = 0;
        while (n % prime == 0) {
            cnt++;
            n /= prime;
        }
        if(cnt) mp.emplace_back(prime, cnt);
    }
    if(n > 1) mp.emplace_back(n, 1);
    divisors.clear();
    solve(0, 1, mp, tmp_n);
}

void doWork() {
    getDivisors(36);
    for(auto &div : divisors) cout << div << '\n';
}

int32_t main() {
    seive();
    FAST
    int tc = 1;
//    cin >> tc;
    while (tc--) doWork();
}
