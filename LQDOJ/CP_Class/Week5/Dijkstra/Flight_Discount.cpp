/**
    Author: anvnh
    RyeNyn
**/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define anvnh signed main(void)

template <typename T>
void print(const T& t) {
    for (const auto& element : t) { 
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
template<typename... T>
void get(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
#define ll long long
#define pb push_back
#define fi first
#define se second
#define forn(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define rep(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define nl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define INF 0x3f3f3f3f
const ll MOD = 1e9 + 7;

void setIO(string s){
    #ifdef ONLINE_JUDGE
        freopen((s + ".inp").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}
const int N = 1e5 + 10;
vector<pair<int, int>> adj[N];
vector<int> dis(N), vis(N, 0);

void solve()
{
    int n, m; get(n, m);
    forn(i, 1, m){
        int u, v, w; get(u, v, w);
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dis[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto& x : adj[u]){
            int v = x.fi, w = x.se;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({-dis[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << nl;
}

anvnh {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio
    int ntest;
    ntest = 1;
    // cin >> ntest;
    while (ntest--)
    {
        clock_t z = clock();
        solve();
        debug("Total Time: %.7f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
    }
    return 0;
}
