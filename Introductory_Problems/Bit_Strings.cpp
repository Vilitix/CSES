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

ll fast_exp(ll a,int n){
    if (n==1)return a;
    if (n==0) return 1;
    ll x = fast_exp(a,n/2);
    if (n%2==0)return (x*x) % MOD;
    if (n&1)return (a*x*x) % MOD;
 }

void solve()
{ 
    ll n;
    cin >> n;
    cout << fast_exp(2ll,n) << endl;
    
}

int main()
{
    fastio();
    solve();
    return 0;
}