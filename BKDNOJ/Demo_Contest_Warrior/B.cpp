#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
const ll MOD = 1e9 + 7;

void gen(int n, int max, vector<int> &a)
{
    if(n == 0)
    {
        for(int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        return void(cout << endl);
    }
    for(int i = min(max, n); i >= 1; i--)
    {
        a.pb(i);
        gen(n - i, i, a);
        a.pop_back();
    }
}

void solve()
{
    int n; cin >> n;   
    vector<int> a;
    gen(n, n, a);
}

signed main()
{
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
