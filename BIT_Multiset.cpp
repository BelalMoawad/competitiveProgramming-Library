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
const int N = 1 << 19, MOD = 1e9 + 7, OO = 0x3f3f3f3f3f3f3f3f;
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//|

struct BIT {
    int tree[N];

    void init() {
        memset(tree, 0, sizeof tree);
    }

    void add(int pos, int val) {
        for (++pos; pos <= N; pos += (pos & (-pos))) tree[pos - 1] += val;
    }

    int get(int pos) {
        int ret = 0;
        for (++pos; pos; pos -= (pos & (-pos))) ret += tree[pos - 1];
        return ret;
    }

    int find(int t) {
        int st = 0;
        for (int sz = N >> 1; sz; sz >>= 1) {
            if (tree[st + sz - 1] < t) t -= tree[(st += sz) - 1];
        }
        return st;
    }
};

struct multiSet {
    BIT bit;

    multiSet() {
        bit.init();
    }

    void insert(int val) {
        bit.add(val, 1);
    }

    void erase(int val) {
        bit.add(val, -1);
    }

    int count(int val) {
        return bit.get(val) - bit.get(val - 1);
    }

    int largerThanMe(int val) {
        return size() - bit.get(val);
    }

    int largerThanOrEqualMe(int val) {
        return size() - bit.get(val - 1);
    }

    int lessThanMe(int val) {
        return bit.get(val - 1);
    }

    int lessThanOrEqualMe(int val) {
        return bit.get(val);
    }

    int size() {
        return bit.get(N - 1);
    }

    int at(int ind) {
        return bit.find(ind);
    }
} st;

void doWork() {

}

int32_t main() {
    FAST
    int tc = 1;
//    cin >> tc;
    while (tc--) doWork();
}