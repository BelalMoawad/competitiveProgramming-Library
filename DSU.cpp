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

int n; // number of nodes
 
struct DSU {
    vi groupsize, parent, groupmax, groupmin;
    int numofgroups;
    DSU() {
        groupsize = vi(n + 1, 1);
        groupmin = vi(n + 1);
        groupmax = vi(n + 1);
        parent = vi(n + 1);
        numofgroups = n;
        iota(groupmax.begin(), groupmax.end(), 0);
        iota(groupmin.begin(), groupmin.end(), 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int findleader(int i) {
        if (parent[i] == i) return i;
        return parent[i] = findleader(parent[i]);
    }
    bool samegroup(int i, int j) {
        return findleader(i) == findleader(j);
    }
    void mergegroups(int i, int j) {
        numofgroups--;
        int l1 = findleader(i);
        int l2 = findleader(j);
        if (groupsize[l1] < groupsize[l2]) swap(l1, l2);
        parent[l2] = l1;
        groupmin[l1] = min(groupmin[l1], groupmin[l2]);
        groupmax[l1] = max(groupmax[l1], groupmax[l2]);
        groupsize[l1] += groupsize[l2];
    }
    int getMin(int val) {
        return groupmin[findleader(val)];
    }
    int getMax(int val) {
        return groupmax[findleader(val)];
    }
    int getSize(int val) {
        return groupsize[findleader(val)];
    }
};

void doWork() {

}

int32_t main() {
    FAST
    int tc = 1;
//    cin >> tc;
    while (tc--) doWork();
}
