// https://codeforces.com/contest/20/problem/C
/*
 * بسم الله الرحمن الرحيم
 * Author : Belal Moawad
 */
#include<bits/stdc++.h>
#include <unordered_map>
#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define int long long
#define doulbe long double
#define ll long long
# define f first
# define s second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef bitset<70> MASK;
const int N = 1e5 + 9, OO = 1e18 , mod = 1e9 + 7;
/********************* 3la allah **********************/

int n, m;
vector<vector<pii> > graph;
vi dist , vis , par;

void print_path(int s, int t) {
    vi path;
    for (int v = t; v != s; v = par[v]) path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    for(auto i : path) cout << i << ' '; cout << '\n';
}

void dijkstra(int src) {
    dist[src] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.emplace(0 , src);
    while (!pq.empty()) {
        int u = pq.top().s; pq.pop(); vis[u] = 1;
        for(auto edge : graph[u]) {
            int v = edge.f , cost = edge.s;
            if(vis[v]) continue;
            if(dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                par[v] = u;
                pq.emplace(dist[v] , v);
            }
        }
    }
}

void doWork() {
    int u , v , w;
    cin >> n >> m;
    dist = vi(n + 1 , OO);
    vis = vi(n + 1);
    par = vi(n + 1 , -1);
    graph = vector<vector<pii>>(n + 1);
    while (m--) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v , w);
        graph[v].emplace_back(u , w);
    }
    // shortest path from 1 to n
    dijkstra(1);
    if(dist[n] == OO) return void(cout << -1 << '\n');
    print_path(1 , n);
}

int32_t main() {
    FAST
    int tc = 1;
//    cin >> tc;
    while(tc--) doWork();
}
/*
 * الحمد لله
 */
