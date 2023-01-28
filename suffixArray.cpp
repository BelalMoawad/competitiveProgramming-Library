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
#define F first
#define S second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef bitset<5> MASK;
const int N = 3e5 + 9, MOD = 1e9 + 7, OO = 0x3f3f3f3f/*3f3f3f3f*/;
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//|

class suffixArray {
    int n;
    vi p, c, lcp;
    string str;
    void radixSort(vector<pair<pii, int> > &a) {
        { // sort based on second
            vi cnt(n);
            for(auto x : a) cnt[x.F.S]++;
            vector<pair<pii, int> > a_new(n);
            vi pos(n);
            for (int i = 1; i < n; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
            for(auto x : a) a_new[pos[x.F.S]++] = x;
            a = a_new;
        }
        { // sort based on first
            vi cnt(n);
            for(auto x : a) cnt[x.F.F]++;
            vector<pair<pii, int> > a_new(n);
            vi pos(n);
            for (int i = 1; i < n; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
            for(auto x : a) a_new[pos[x.F.F]++] = x;
            a = a_new;
        }
    }
    void complete(auto a) {
        for (int i = 0; i < n; ++i) p[i] = a[i].S;
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) c[p[i]] = c[p[i - 1]] + (a[i].F != a[i - 1].F);
    }
    void init() {
        vector<pair<char, int> > a(n);
        for (int i = 0; i < n; ++i) a[i] = {str[i], i};
        sort(all(a));
        complete(a);
    }
    void process(int k) {
        vector<pair<pii, int> > a(n);
        for (int i = 0; i < n; ++i) a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        radixSort(a);
        complete(a);
    }
    void calcSuffixArray() {
        init();
        int k = 0;
        while ((1 << k) < n) {
            process(k);
            k++;
        }
    }
    void calcLCP() {
        int k = 0;
        for (int i = 0; i < n - 1; ++i) {
            int pi = c[i];
            int j = p[pi - 1];
            // lcp[i] = lcp(str[i...], str[j...])
            while (str[i + k] == str[j + k]) k++;
            lcp[pi] = k;
            k = max(k - 1, 0);
        }
    }
    int can(int idx, string &pattern){
        int cur = p[idx], len = (int) pattern.size();
        int u = n - cur - 1;
        int mn = min(len, u);
        for (int i = 0; i < mn; ++i, ++cur) {
            if(str[cur] == pattern[i]) continue;
            if(str[cur] < pattern[i]) return 0;
            return 2;
        }
        return (int)(len <= u);
    }
    int lower_bound(string &pattern) {
        int lo = 0, hi = n - 1, mid, ret = -1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int status = can(mid, pattern);
            if(status == 1) ret = mid, hi = mid - 1;
            else if(!status) lo = mid + 1;
            else hi = mid - 1;
        }
        return ret;
    }
    int upper_bound(string &pattern) {
        int lo = 0, hi = n - 1, mid, ret = -1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int status = can(mid, pattern);
            if(status == 1) ret = mid, lo = mid + 1;
            else if(!status) lo = mid + 1;
            else hi = mid - 1;
        }
        return ret;
    }
public:
    suffixArray(string s) {
        str = s;
        str += '$';
        n = (int) str.size();
        p = c = lcp = vi(n);
        calcSuffixArray();
        calcLCP();
    }
    vi getSuffixArray() {
        return p;
    }
    vi getLCP() {
        return vi(lcp.begin() + 1, lcp.end());
    }
    bool patternIsExist(string &pattern) {
        return lower_bound(pattern) != -1;
    }
    int countPattern(string &pattern) {
        int lower = lower_bound(pattern);
        if(lower == -1) return 0;
        return upper_bound(pattern) - lower + 1;
    }
};
