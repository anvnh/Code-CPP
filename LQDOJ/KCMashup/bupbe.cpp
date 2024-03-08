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
const ll MOD = (1e9) + 7;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a;
	vector<int> temp;
	for(int i=0; i<n; i++)
	{
		int x; cin >> x;
		a.pb(x);
		temp.pb(x);
	}
	sort(all(a));
	sort(all(temp));
	int j = n - 1, i = j - 1;
	while(i >= 0)
	{
		if(a[j] - a[i] >= k)
		{
			temp[i] = 0;
			j -= 1;
			i -= 1;
		}
		else
		{
			i -= 1;
		}
	}
	ll ans = 0;
	for(auto x : temp) ans += x;
	cout << ans;
}