#include <bits/stdc++.h>
#define file(name) if(fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define TASK "REMOVE"

using namespace std;

const int MAXN = 2e3;

long long n, a[MAXN], b[MAXN];
long long x, y, dp[MAXN][MAXN];

void solve() {
    for(int i = 1; i <= n; i++)
        dp[0][0] += a[i] * b[n - i + 1];
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            dp[i][0] += a[i + j - 1] * b[n - j + 1];
        }
        if(dp[i][0] > dp[x][y]) {
            x = i;
            y = 0;
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            dp[0][i] += a[j] * b[n - i - j + 1];
        }
        if(dp[0][i] > dp[x][y]) {
            x = 0;
            y = i;
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(i + j >= n) break;
            if(i && j)
                dp[i][j] = dp[i - 1][j - 1] - a[i] * b[n - i + 1] - a[n - i + 1] * b[i];
            
            if(dp[i][j] > dp[x][y]) {
                x = i;
                y = j;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    file(TASK);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    solve();
    
    cout << x << ' ' << y << '\n' << dp[x][y];
    
    cerr << "Time elapsed: " << TIME << " s.\n";

    return 0;
}