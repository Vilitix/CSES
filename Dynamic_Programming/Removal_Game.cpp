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

ll top_down(vector<vector<ll>> &dp,vector<ll> &tab, ll i, ll j){
    if (dp[i][j] != LLONG_MAX) return dp[i][j];
    else if((j-i)<=1 && (j-i)>=0 ){
        return dp[i][j] = max(tab[i],tab[j]);
    }
    else if ((j-i)<0){return 0;}
    else{
        return dp[i][j] = max(tab[i] + min(top_down(dp,tab,i+2,j),top_down(dp,tab,i+1,j-1)),tab[j] + min(top_down(dp,tab,i+1,j-1),top_down(dp,tab,i,j-2)));
    }
}

void solve()
{ 
    ll n;
    cin >> n;
    vector<ll> tab(n) ;
    for(ll i=0;i<n;i++) cin>> tab[i];
    vector<vector<ll>> dp(n,vector<ll>(n,LLONG_MAX));
    cout << top_down(dp,tab,0,n-1) << endl;;

}

int main()
{
    fastio();
    solve();

    return 0;
}
