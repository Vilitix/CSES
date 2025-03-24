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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[1][2] = 1;
    dp[2][1] = 1;
    dp[2][2] = 2;
    for(int i = 1;i<=n;i++){
        dp[i][1] = !(i&1);v
        for(int j = 2;j<=m;j++){
            dp[i][j] += dp[i][j-1]*dp[i][1];
            if (j>2) dp[i][j]+=dp[i][j-2]*dp[i][2];
            cout << " i " << i << " j " << j << " dp i j " << dp[i][j] << endl;
        }
    }
    cout << dp[n][m] << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}