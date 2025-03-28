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
    int n,x;
    cin >> n >> x; 
    vector<int> weight(n);
    for(int i = 0;i<n;i++){
        cin >> weight[i];
    }
    vector<pair<int,int>> dp(1<<n,mp(21,0));
    dp[0] = mp(1,0);
    for(ll i = 1;i<1<<n;i++){
        for(int j = 0;j<20;j++){
            if (i & (1<<j)){
                int el = i - (1<<j);
                auto [nb,w] = dp[el];
                if (weight[j]+w > x) nb++,w = min(dp[el].second,weight[j]);
                else w +=weight[j];
                dp[i] = min(dp[i],mp(nb,w));
        }
    }
}

    cout << dp[(1<<n) -1 ].first << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}