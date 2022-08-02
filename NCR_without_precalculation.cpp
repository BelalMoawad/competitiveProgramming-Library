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

ll ncr(ll n, ll r) {
    ll ret = 1;
    for (ll i = r + 1; i <= n; ++i) {
        ll d = (i - r);
        ll q = ret / d;
        ll rem = ret - (q * d);
        ret = (q * i) + (rem * i) / d;
    }
    return ret;
}

void doWork() {
    int n, r; cin >> n >> r;
    cout << ncr(n, max(r, n - r)) << '\n';
}

int32_t main() {
    FAST
    int tc = 1;
    cin >> tc;
    while (tc--) doWork();
}
