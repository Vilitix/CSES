#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int n;
    cin >> n;
    ll total = 1ll * n * (n + 1) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(total+1, 0));
    dp[0][0] = 1;
    for (int s = 1; s <= total; s++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][s] = dp[i - 1][s];
            if (s >= i && dp[i - 1][s - i])
            {
                dp[i][s] = (dp[i][s] + dp[i - 1][s - i]) % MOD;
            }
        }
    }
    if (total & 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << dp[n][total / 2] << endl;
    }
}

int main()
{
    fastio();
    solve();
    return 0;
}