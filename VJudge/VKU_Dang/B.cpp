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

const int maxN = 1e6 + 5;
vector<int> graph[maxN];
vector<bool> visited(maxN, false);

void solve()
{
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int ans = 0;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(a[i][j] == '.' || visited[i][j])
                continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            while(!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for(int dx = -1; dx <= 1; dx++)
                {
                    for(int dy = -1; dy <= 1; dy++)
                    {
                        if(dx == 0 && dy == 0)
                            continue;
                        int nx = x + dx, ny = y + dy;
                        if(nx >= 0 && nx < h && ny >= 0 && ny < w && a[nx][ny] == '#' && !visited[nx][ny])
                        {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
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
