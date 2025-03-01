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
    vector<pair<ll,ll>> dp(n+1);
    dp[1] = mp(1,1);
    for(int i = 2;i<=n;i++){
        dp[i] = mp((dp[i-1].first*4) % MOD+ dp[i-1].second % MOD,(dp[i-1].first %MOD)+(dp[i-1].second*2)%MOD);
    }
    cout << (dp[n].first + dp[n].second)%MOD << endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}