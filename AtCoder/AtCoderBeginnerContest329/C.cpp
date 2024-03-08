#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define ford(i, n) for (int i = (n)-1; i >= 0; --i)
#define fore(i, a, b) for (int i = (a); i <= (b); ++i)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define maxn 100005
#define debug(x) cerr << #x << " = " << x << endl;
template <typename T>
void print(const T &v) {
    for (const auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
const ll MOD = (1e9) + 7;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio;
    int ntest = 1;
    while(ntest--)
    {
        int n; cin >> n;
        string s; cin >> s;
        map<char, ll> mp;
        char c = (s[0]);
        ll cnt = 1;
        if(n == 1) return cout << 1, 0;
        for(int i = 1; i < n; i++)
        {
            if(s[i] == c)
            {
                cnt++; 
                c = s[i];
                mp[s[i]] = max(mp[s[i]], cnt);
            }
            if(s[i] != c)
            {
                cnt = 1;
                c = s[i];
                mp[s[i]] = max(mp[s[i]], cnt);
            }
        }
        ll res = 0; 
        for(auto x : mp)
        {
            res += x.se;
        }
        cout << res;
    }
    return 0;
}