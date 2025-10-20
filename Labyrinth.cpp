#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1001;

ll n, m;
char grid[N][N];
bool vis[N][N];
pair<ll, ll> parent[N][N];
char lastMove[N][N];
ll startRow, startCol, endRow, endCol;

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};
char moves[4] = {'U', 'R', 'D', 'L'};

void bfs() {
    queue<pair<ll, ll>> q;
    q.push({startRow, startCol});
    vis[startRow][startCol] = true;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        if (row == endRow && col == endCol) break;

        for (int i = 0; i < 4; i++) {
            ll newRow = row + dx[i];
            ll newCol = col + dy[i];

            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) continue;
            if (grid[newRow][newCol] == '#') continue;
            if (vis[newRow][newCol]) continue;

            vis[newRow][newCol] = true;
            parent[newRow][newCol] = {row, col};
            lastMove[newRow][newCol] = moves[i];
            q.push({newRow, newCol});
        }
    }

    if (!vis[endRow][endCol]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    string ans = "";
    ll r = endRow, c = endCol;
    while (r != startRow || c != startCol) {
        ans += lastMove[r][c];
        auto [pr, pc] = parent[r][c];
        r = pr;
        c = pc;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    cout << ans << endl;
}

void solve() {
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') startRow = i, startCol = j;
            if (grid[i][j] == 'B') endRow = i, endCol = j;
            vis[i][j] = false;
        }
    }
    bfs();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
