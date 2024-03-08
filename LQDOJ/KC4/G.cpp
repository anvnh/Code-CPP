#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool isPrime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
#define MOD 2004010501
#define MAX_N 100005
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> precnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        precnt[i + 1] = precnt[i] + x;
    }
    int N = precnt[n];
    int res = INT_MAX;
    for (int i = 0; i + N < n + 1; i++)
    {
        res = min(res, N - precnt[i + N] + precnt[i]);
    }
    cout << res;
}
