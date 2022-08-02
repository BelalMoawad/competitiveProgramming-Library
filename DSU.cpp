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

const int MAXNODES = 1e5 + 5;

int n; // number of nodes

struct DSU {
	int groupsize[MAXNODES];
	int parent[MAXNODES];
	int numofgroups;
	DSU() {
		numofgroups = n;
		for (int i = 0; i < MAXNODES; ++i) {
			parent[i] = i;
			groupsize[i] = 1;
		}
	}
	int findleader(int i) {
		if (parent[i] == i) return i;
		return parent[i] = findleader(parent[i]);
	}
	bool samegroup(int i, int j) {
		int l1 = findleader(i);
		int l2 = findleader(j);
		return l1 == l2;
	}
	void mergegroups(int i, int j) {
		numofgroups--;
		int l1 = findleader(i);
		int l2 = findleader(j);
		if (groupsize[l1] > groupsize[l2]) {
			parent[l2] = l1;
			groupsize[l1] += groupsize[l2];
		}
		else {
			parent[l1] = l2;
			groupsize[l2] += groupsize[l1];
		}
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
