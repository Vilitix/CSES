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
    int n, x;
    cin >> n >> x;
    vector<ll> nb(x+1,0);
    vector<int> coins(n);
    for(auto &x:coins) cin >> x;
    nb[0] = 1;
    for(auto el:coins){
        for(int i = 1;i<=x;i++){
            if (i>=el) nb[i]= (nb[i] + nb[i-el]) % MOD;
        }

    }
    cout << nb[x] << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}